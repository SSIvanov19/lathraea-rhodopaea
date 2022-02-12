/*! @file accountSystem.h
*   @brief A header file for the account system.
*/

#pragma once
#include <back-end/validations.h>
#include <back-end/env.h>
#include <back-end/encryption.h>

/**
 * @brief An enum for the different roles
*/
enum class Roles
{
	USER = 0, /*!< User role */
	ADMIN = 1 /*!< Admin role */
};

/**
 * @brief A struct for an account
*/
struct Account
{
	std::string uname; //!< Username of the user
	std::string email; //!< Email of the user
	std::vector<int> pass; //!< Password of the user
	Roles role = Roles::USER; //!< Role of the user

	/**
	 * @brief A constructor for creating a user
	 * @param uname_ Username of the user
	 * @param email_ Email of the user
	 * @param pass_ Password of the user
	 * @param role_ Role of the user
	*/
	Account(
		std::string uname_,
		std::string email_,
		std::vector<int> pass_,
		Roles role_
	);

	/**
	 * @brief Default constructor for Account
	*/
	Account();


	// Only for debugging purposes
	// Should not be used in the final product
	void displayUserInfo();
};

/**
 * @brief A structure for a linked list that holds all of the accounts
*/
struct AccountList
{
	Account user; //!< The data of the user
	AccountList* next = nullptr; //!< The next node

	/**
	 * @brief A constructor for AccountList
	 * @param user_ The data of the first user (Admin)
	 * @param next_ A pointer to the next user
	*/
	AccountList(Account user_, AccountList* next_);

	/**
	 * @brief Function for adding a user
	 * @param data The data of the account
	*/
	void addUser(Account data);

	// Only for debugging purposes
	// Should not be used in the final product
	void displayAllUsers();

	/**
	 * @brief Function that check if user exists
	 * @param emailToCheck The email to be checked
	 * @param accountData Variable which gets the account data
	 * @return does the user exist
	*/
	bool doesUserExist(
		std::string emailToCheck,
		Account** accountData
	);
};

/**
 * @brief A struct about the account manager
*/
struct AccountManager
{
	/**
	 * @brief A Linked list that holds all of the accounts
	*/
	AccountList* accountNode;

	/**
	 * @brief Pointer to the account that is currently logged in
	*/
	Account* activeUser = nullptr;

	/**
	 * @brief Validation manager
	*/
	Validations validations;

	/**
	 * @brief Environment variables manager
	*/
	EnvManager envManager;

	/**
	 * @brief Encryption manager
	*/
	EncryptionManager encryptionManager;

	/**
	 * @brief A constructior for AccountManager
	*/
	AccountManager();

	/**
	 * @brief Function for registering a user
	 * @param uname Username of the user
	 * @param email Email of the user
	 * @param pass Password of the user
	 * @param role Role of the user
	 * @return True or false, based on that
			   if a registration is successful
	*/
	void registerUser(
		std::string uname,
		std::string email,
		std::string pass,
		Roles role
	);

	/**
	 * @brief Function for logining a user
	 * @param email Email of the user
	 * @param pass Password of the user
	 * @return True or false, based on that
			   if a login is successful
	*/
	void loginUser(std::string email, std::string pass);

	/**
	 * @brief Function for logging out the current user
	*/
	void logoutUser();

	/**
	 * @brief Function that checks if the user is logged in
	 * @return Is the user logged in
	*/
	bool isUserLoggedIn();

	/**
	 * @brief Function for getting logged in user data
	 * @return Logged in user data
	*/
	Account getLoggedInUserData();
};