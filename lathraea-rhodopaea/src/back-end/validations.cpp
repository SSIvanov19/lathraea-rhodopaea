/*! @file validations.cpp
*   @brief A source file for the validation system.
*/
#include <back-end/validations.h>

bool Validations::isUnameValid(const std::string uname)
{
	const std::regex valRegex("[A-Za-z][A-Za-z0-9_]{2,29}");

	return std::regex_match(uname, valRegex);
}

bool Validations::isEmailValid(const std::string email)
{
	const std::regex valRegex("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");;

	return std::regex_match(email, valRegex);
}

bool Validations::isPassValid(const std::string pass)
{
	const std::regex valRegex("(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])[a-zA-Z0-9]{8,}");;

	return std::regex_match(pass, valRegex);
}