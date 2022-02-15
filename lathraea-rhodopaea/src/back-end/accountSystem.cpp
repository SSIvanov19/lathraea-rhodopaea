/*! @file accountSystem.cpp
*   @brief A source file for the account system.
*/

#include <back-end/accountSystem.h>
#include <back-end/env.h>
#include <back-end/encryption.h>
#include <back-end/logs.h>

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

AccountList::AccountList(Account user_, AccountList * next_)
{
	user = user_;
	next = next_;
}

void AccountList::addUser(Account data)
{
	AccountList* newNode = new AccountList(data, nullptr);

	AccountList* temp = this;

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

bool AccountList::doesUserExist(std::string emailToCheck, Account * *accountData = nullptr)
{
	AccountList* temp = this;

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

AccountManager::AccountManager()
{
	// Create the first Account
	accountList = new AccountList(
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
	//Make email in lower case
	std::transform(email.begin(), email.end(), email.begin(), ::tolower);

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
	if (accountList->doesUserExist(email))
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Email address: " + email + " is duplicate."
		);

		throw std::string("The email is duplicate");
	}

	//Create and save the user
	accountList->addUser(
		Account(uname, email, encryptionManager.encrypt(pass), role)
	);

	loggerManager.log(
		LogSeverity::INFO,
		"User with email: " + email + "is successfully registered"
	);
}

void AccountManager::loginUser(std::string email, std::string pass)
{
	//Make email in lower case
	std::transform(email.begin(), email.end(), email.begin(), ::tolower);

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

	if (!accountList->doesUserExist(email, &user))
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

void AccountManager::logoutUser()
{
	LoggerManager loggerManager;

	if (this->activeUser == nullptr)
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"There is not active user"
		);

		throw std::string("There is not currently any logged in user");
	}

	loggerManager.log(
		LogSeverity::INFO,
		"User is logged in successfully"
	);

	this->activeUser = nullptr;
}

bool AccountManager::isUserLoggedIn()
{
	return this->activeUser != nullptr;
}

bool AccountManager::isAdmin()
{
	if (this->isUserLoggedIn())
	{
		return this->getLoggedInUserData().role == Roles::ADMIN;
	}

	return false;
}

Account AccountManager::getLoggedInUserData()
{
	return *this->activeUser;
}

std::vector<Account> AccountManager::getAllUserData()
{
	LoggerManager loggerManager;
	std::vector<Account> allAccounts;

	AccountList* temp = this->accountList;

	loggerManager.log(
		LogSeverity::INFO,
		"Getting all users"
	);

	while (temp)
	{
		allAccounts.push_back(temp->user);

		temp = temp->next;
	}

	loggerManager.log(
		LogSeverity::INFO,
		"Found " + std::to_string(allAccounts.size()) + " events."
	);

	return allAccounts;
}

void AccountManager::changeUserRoleToAdmin(std::string email)
{
	LoggerManager loggerManager;

	AccountList* temp = this->accountList;

	loggerManager.log(
		LogSeverity::INFO,
		"Changing role of user with email: " + email + " to Admin"
	);

	while (temp)
	{
		if (temp->user.email == email)
		{
			temp->user.role = Roles::ADMIN;
			
			loggerManager.log(
				LogSeverity::INFO,
				"Role changed successfully."
			);
			return;
		}

		temp = temp->next;
	}

	loggerManager.log(
		LogSeverity::NOTICE,
		"Couldn't find account with such email: " + email
	);
}

bool AccountManager::removeAccount(AccountList** head, std::string email)
{
	LoggerManager loggerManager;

	AccountList* temp = *head;
	AccountList* prev = NULL;

	if (temp != NULL && temp->user.email == email)
	{
		*head = temp->next;

		loggerManager.log(
			LogSeverity::INFO,
			"User with email: " +
			email +
			" is successfully deleted."
		);

		delete temp;
		return true;
	}
	else
	{
		while (temp != NULL && temp->user.email != email)
		{
			prev = temp;
			temp = temp->next;
		}

		if (temp == NULL)
		{
			loggerManager.log(
				LogSeverity::NOTICE,
				"User with email: " +
				email +
				" can not be deleted, because there is not an user with such email."
			);

			return false;
		}

		prev->next = temp->next;

		loggerManager.log(
			LogSeverity::INFO,
			"User with email: " +
			email +
			" is successfully deleted."
		);

		delete temp;
	}

	return true;
}
