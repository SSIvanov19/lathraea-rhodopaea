/*! @file validations.h
*   @brief A header file for the validation system.
*/

#pragma once
#include <regex>

/**
 * @brief A struct for validation of data
*/
struct Validations
{
	/**
	 * @brief Function for validating a username
	 * @param uname Username to be validated
	 * @return Is username valid
	*/
	bool isUnameValid(const std::string uname);

	/**
	 * @brief Function for validating a email
	 * @param email Email to be validated
	 * @return Is email valid
	*/
	bool isEmailValid(const std::string email);

	/**
	 * @brief Function for validating a password
	 * @param pass Password to be validated
	 * @return Is password valid
	*/
	bool isPassValid(const std::string pass);
};