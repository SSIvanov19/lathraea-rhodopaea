/*! @file accountSystem.cpp
*   @brief A source file for the account system.
*/

#include <back-end/accountSystem.h>
#include <back-end/env.h>
#include <back-end/encryption.h>
#include <string>
#include <iostream>

Account::Account(std::string uname_, std::string email_, std::vector<int> pass_, Roles role_)
{
	uname = uname_;
	email = email_;
	pass = pass_;
	role = role_;
}

Account::Account() = default;

void Account::displayUserInfo()
{
	std::cout << "Username: " << uname << std::endl;
	std::cout << "Email: " << email << std::endl;
	//std::cout << "Password: " << encryptionManager.decrypt(pass) << std::endl;
	std::cout << "Roles: " << int(role) << std::endl;
}

AccountList::AccountList(Account user_, AccountList* next_)
{
	user = user_;
	next = next_;
}

void AccountList::addUser(AccountList* head, Account data)
{
	AccountList* newNode = new AccountList(data, nullptr);

	AccountList* temp = head;

	while (temp)
	{
		if (temp->next == NULL)
		{
			temp->next = newNode;
			return;
		}
		else
		{
			temp = temp->next;
		}
	}
}

bool AccountList::doesUserExist(AccountList* head, std::string emailToCheck, Account* accountData)
{
	AccountList* temp = head;

	while (temp != NULL)
	{
		if (temp->user.email == emailToCheck)
		{
			if (accountData)
			{
				accountData = &temp->user;
			}

			return true;
		}
		temp = temp->next;
	}

	return false;
}

bool AccountList::kondio(AccountList* head, std::string emailToCheck, Account*& accountData)
{
	AccountList* temp = head;

	while (temp != NULL)
	{
		if (temp->user.email == emailToCheck)
		{
			if (accountData)
			{
				accountData = &temp->user;
			}

			return true;
		}
		temp = temp->next;
	}

	return false;
}

void AccountList::displayAllUsers(AccountList* head)
{
	while (head != NULL)
	{
		head->user.displayUserInfo();
		std::cout << std::endl;
		head = head->next;
	}
}

AccountManager::AccountManager()
{
	try
	{
		// Create the first Account
		accountList = new AccountList(Account(envManager.getEnv("ADMIN_USERNAME"), envManager.getEnv("ADMIN_EMAIL"), encryptionManager.encrypt(envManager.getEnv("ADMIN_PASSWORD")), Roles::ADMIN), nullptr);
	}
	catch (const std::string errorMsg)
	{
		std::cout << "There is a problem with the program\nReason: " + errorMsg << std::endl;
		exit(1);
	}
	catch (...)
	{
		std::cout << "Problem occurred. Please restart the program!";
		exit(1);
	}
}

bool AccountManager::isRegistrationSuccessful(std::string uname, std::string email, std::string pass, Roles role)
{
	//Validate the data
	if (!validations.isUnameValid(uname))
	{
		throw std::string("The username is invalid");
	}

	if (!validations.isEmailValid(email))
	{
		throw std::string("The email address is invalid");
	}

	if (!validations.isPassValid(pass))
	{
		throw std::string("The password is invalid");
	}

	//Check for duplicate email
	if (accountList->doesUserExist(accountList, email))
	{
		throw std::string("The email is duplicate");
	}

	//Create and save the user
	accountList->addUser(accountList, Account(uname, email, encryptionManager.encrypt(pass), role));

	// Only for debugging purposes
	// Should not be used in the final product
	std::cout << "Added new user. All users are:\n";

	// Only for debugging purposes
	// Should not be used in the final product
	accountList->displayAllUsers(accountList);

	return true;
}

bool AccountManager::isLoginSuccessful(std::string email, std::string pass)
{
	if (this->activeUser != nullptr)
	{
		throw std::string("There is already logged in account");
	}

	Account* user = new Account();

	if (!accountList->kondio(accountList, email, user))
	{
		throw std::string("There is no user with such an email");
	}

	if (user->pass != encryptionManager.encrypt(pass))
	{
		throw std::string("The password in incorrect");
	}

	this->activeUser = user;

	return true;
}