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
 * @brief A struct for account
*/
struct Account
{
	std::string uname; /*!< Username of the user */
	std::string email; /*!< Email of the user */
	std::vector<int> pass; /*!< Password of the user */
	Roles role = Roles::USER; /*< Role of the user */

	/**
	 * @brief A constructor for creating a user
	 * @param uname_ Username of the user
	 * @param email_ Email of the user
	 * @param pass_ Password of the user
	 * @param role_ Role of the user
	*/
	Account(std::string uname_, std::string email_, std::vector<int> pass_, Roles role_); /*!< A constructor for creating a user */

	/**
	 * @brief Default constructor for Account
	*/
	Account(); /*!< Default constructor for Account */
	
	
	// Only for debugging purposes
	// Should not be used in the final product
	void displayUserInfo();
};

/**
 * @brief A structure for a linked list that holds all of the accounts
*/
struct AccountList
{
	Account user; /*!< The data of the user */
	AccountList* next = nullptr; /*!< The next node */

	/**
	 * @brief A constructor for AccountList
	 * @param user_ The data of the first user (Admin)
	 * @param next_ A pointer to the next user
	*/
	AccountList(Account user_, AccountList* next_); /*!< A constructor for AccountList */

	/**
	 * @brief Function for adding a user
	 * @param head The head of the list
	 * @param data The data of the account
	*/
	void addUser(AccountList* head, Account data); /*!< Function for adding a user */

	// Only for debugging purposes
	// Should not be used in the final product
	void displayAllUsers(AccountList* head);

	/**
	 * @brief A function for checking if there is already a account with this email
	 * @param head The head of the list
	 * @param emailToCheck The email to be checked
	 * @param accountData Optional parameter for getting an account data 
	 * @return Is email duplicate
	*/
	bool doesUserExist(AccountList* head, std::string emailToCheck, Account* accountData = nullptr); /*!< Function for checking for duplicate emails */
	
	bool kondio(AccountList* head, std::string emailToCheck, Account*& accountData);
};

/**
 * @brief A struct about the account manager
*/
struct AccountManager
{
	/**
	 * @brief A Linked list that holds all of the accounts
	*/
	AccountList* accountList; /*!< A Linked list that holds all of the accounts */

	/**
	 * @brief Account that is currently logged in
	*/
	Account* activeUser = nullptr; /*!< Account that is currently logged in */
	
	/**
	 * @brief Validation manager
	*/
	Validations validations; /*!< Validation manager */

	/**
	 * @brief Environment variables manager
	*/
	EnvManager envManager ;/*!< Environment variables manager */

	/**
	 * @brief Encryption manager
	*/
	EncryptionManager encryptionManager; /*!< Encryption manager */

	/**
	 * @brief A constructior for AccountManager
	*/
	AccountManager(); /*!< A constructior for AccountManager */

	/**
	 * @brief Function for registering a user
	 * @param uname Username of the user
	 * @param email Email of the user
	 * @param pass Password of the user
	 * @param role Role of the user
	 * @return True or false, based on that
			   if a registration is successful
	*/
	bool isRegistrationSuccessful(std::string uname, std::string email, std::string pass, Roles role); /*!< Function for registering a user */

	/**
	 * @brief Function for logining a user
	 * @param email Email of the user
	 * @param pass Password of the user
	 * @return True or false, based on that
			   if a login is successful 
	*/
	bool isLoginSuccessful(std::string email, std::string pass); /*!< Function for logining a user */
};