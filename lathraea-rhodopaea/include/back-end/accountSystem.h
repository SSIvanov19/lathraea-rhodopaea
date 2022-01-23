/*! @file accountSystem.h
*   @brief A header file for the account system.
*/

#pragma once
#include <back-end/validations.h>

/**
 * @brief A enum for the different roles
*/
enum class Roles
{
	USER = 0, /*!< User role */
	ADMIN = 1 /*!< Admin role */
};

/**
 * @brief A struct about the account manager
*/
static struct AccountManager
{
	/**
	 * @brief Function for registering a user
	 * @param uname Username of the user
	 * @param email Email of the user
	 * @param pass Password of the user
	 * @param role Role of the user
	 * @return True or false, based on that
			   if a registration is successful
	*/
	bool registerUser(
		std::string uname,
		std::string email,
		std::string pass,
		Roles role
	)
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

		//Check for dublicate email and uname

		//Create the user

		//Save the user 
		return true;
	}
} accountManager;