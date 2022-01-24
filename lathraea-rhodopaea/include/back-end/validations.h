/*! @file validations.h
*   @brief A header file for the validation system.
*/

#pragma once
#include <regex>

/**
 * @brief A struct for validation of data
*/
static struct Validations
{
	/**
	 * @brief Function for validating a username
	 * @param uname Username to be validated
	 * @return Is username valid
	*/
	bool validateUname(const std::string uname); /*!< Function for validating a username */

	/**
	 * @brief Function for validating a email
	 * @param email Email to be validated
	 * @return Is email valid
	*/
	bool validateEmail(const std::string email); /*!< Function for validating a username */

	/**
	 * @brief Function for validating a password
	 * @param pass Password to be validated
	 * @return Is password valid
	*/
	bool validatePass(const std::string pass); /*!< Function for validating a username */
} validations;