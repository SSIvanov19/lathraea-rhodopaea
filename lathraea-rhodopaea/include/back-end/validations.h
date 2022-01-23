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
	bool validateUname(const std::string uname)
	{
		const std::regex valRegex("[A-Za-z][A-Za-z0-9_]{2,29}");

		return std::regex_match(uname, valRegex);
	}

	/**
	 * @brief Function for validating a email
	 * @param email Email to be validated
	 * @return Is email valid
	*/
	bool validateEmail(const std::string email)
	{
		const std::regex valRegex("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");;

		return std::regex_match(email, valRegex);
	}

	/**
	 * @brief Function for validating a password
	 * @param pass Password to be validated
	 * @return Is password valid
	*/
	bool validatePass(const std::string pass)
	{
		const std::regex valRegex("(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])[a-zA-Z0-9]{8,}");;

		return std::regex_match(pass, valRegex);
	}
} validations;