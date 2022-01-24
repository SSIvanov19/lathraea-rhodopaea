/*! @file accountSystem.cpp
*   @brief A source file for the account system.
*/

#include <back-end/accountSystem.h>
#include <back-end/validations.h>
#include <back-end/env.h>
#include <string>
#include <iostream>

Account::Account(std::string uname_, std::string email_, std::string pass_, Roles role_)
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
	std::cout << "Password: " << pass << std::endl;
	std::cout << "Roles: " << int(role) << std::endl;
}

AccountList::AccountList(Account user_, AccountList* next_)
{
	user = user_;
	next = next;
}

void AccountList::addUser(AccountList* head, Account data)
{
	AccountList* newNode = new AccountList(data, head);

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

bool AccountList::checkForDuplicateEmail(AccountList* head, std::string emailToCheck)
{
	while (head != NULL)
	{
		if (head->user.email == emailToCheck)
		{
			return true;
		}
		head = head->next;
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
		accountList = new AccountList(Account(envManager.getEnv("ADMIN_USERNAME"), envManager.getEnv("ADMIN_EMAIL"), envManager.getEnv("ADMIN_PASSWORD"), Roles::ADMIN), nullptr);
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

bool AccountManager::registerUser(std::string uname, std::string email, std::string pass, Roles role)
{
	//Validate the data
	if (!validations.validateUname(uname))
	{
		throw std::string("The username is invalid");
	}

	if (!validations.validateEmail(email))
	{
		throw std::string("The email address is invalid");
	}

	if (!validations.validatePass(pass))
	{
		throw std::string("The password is invalid");
	}

	//Check for dublicate email
	if (accountList->checkForDuplicateEmail(accountList, email))
	{
		throw std::string("The email is duplicate");
	}

	//Create and save the user
	accountList->addUser(accountList, Account(uname, email, pass, role));

	// Only for debugging purposes
	// Should not be used in the final product
	std::cout << "Added new user. All users are:\n";

	// Only for debugging purposes
	// Should not be used in the final product
	accountList->displayAllUsers(accountList);

	return true;
}