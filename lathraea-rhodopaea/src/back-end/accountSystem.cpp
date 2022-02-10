/*! @file accountSystem.cpp
*   @brief A source file for the account system.
*/

#include <back-end/accountSystem.h>
#include <back-end/env.h>
#include <back-end/encryption.h>
#include <back-end/logs.h>
#include <string>
#include <iostream>

Account::Account(
	std::string uname_,
	std::string email_,
	std::vector<int> pass_,
	Roles role_
)
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

bool AccountList::doesUserExist(AccountList* head, std::string emailToCheck, Account** accountData = nullptr)
{
	AccountList* temp = head;

	while (temp != NULL)
	{
		if (temp->user.email == emailToCheck)
		{
			if (accountData)
			{
				*accountData = &temp->user;
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
	// Create the first Account
	accountNode = new AccountList(
		Account(
			envManager.getEnv("ADMIN_USERNAME"), 
			envManager.getEnv("ADMIN_EMAIL"),
			encryptionManager.encrypt(envManager.getEnv("ADMIN_PASSWORD")),
			Roles::ADMIN),
		nullptr
	);
}

void AccountManager::registerUser(
	std::string uname,
	std::string email,
	std::string pass,
	Roles role
)
{
	LoggerManager loggerManager;
	loggerManager.log(
		LogSeverity::INFO, 
		"User with email: " + 
		email + 
		" is trying to login."
	);

	//Validate the data
	if (!validations.isUnameValid(uname))
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Username: " + uname + " is invalid."
		);

		throw std::string("The username is invalid");
	}

	if (!validations.isEmailValid(email))
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Email address: " + email + " is invalid."
		);

		throw std::string("The email address is invalid");
	}

	if (!validations.isPassValid(pass))
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"The password is invalid."
		);

		throw std::string("The password is invalid");
	}

	//Check for duplicate email
	if (accountNode->doesUserExist(accountNode, email))
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Email address: " + email + " is duplicate."
		);

		throw std::string("The email is duplicate");
	}

	//Create and save the user
	accountNode->addUser(
		accountNode,
		Account(uname, email, encryptionManager.encrypt(pass), role)
	);

	loggerManager.log(
		LogSeverity::INFO,
		"User with email: " + email + "is successfully registered"
	);

//	// Only for debugging purposes
//	// Should not be used in the final product
//	std::cout << "Added new user. All users are:\n";
//
//	// Only for debugging purposes
//	// Should not be used in the final product
//	accountNode->displayAllUsers(accountNode);
//
}

void AccountManager::loginUser(std::string email, std::string pass)
{
	LoggerManager loggerManager;
	loggerManager.log(
		LogSeverity::INFO,
		"User with email: " + email + " is trying to login."
	);

	if (this->activeUser != nullptr)
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"There is already logged in account."
		);

		throw std::string("There is already logged in account");
	}

	Account* user = nullptr;

	if (!accountNode->doesUserExist(accountNode, email, &user))
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"There is no user with this email:" + email
		);

		throw std::string("There is no user with such an email");
	}

	if (user->pass != encryptionManager.encrypt(pass))
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"The password for " + email + "is incorrect."
		);

		throw std::string("The password in incorrect");
	}

	this->activeUser = user;

	loggerManager.log(
		LogSeverity::INFO,
		"User with email: " + email + " is successfully logged."
	);
}