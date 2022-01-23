/*! @file accountSystem.cpp
*   @brief A source file for the account system.
*/

#include <back-end/accountSystem.h>
#include <back-end/validations.h>
#include <string>

/**
 * @brief A struct for account
*/
struct Account
{
	std::string uname; /*!< Username of the user */
	std::string email; /*!< Email of the user */
	std::string pass; /*!< Password of the user */
	Roles role; /*< Role of the user */

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
		std::string pass_,
		Roles role_
	) /*!< A constructor for creating a user */
	{
		uname = uname_;
		email = email_;
		pass = pass_;
		role = role_;
	}
};
