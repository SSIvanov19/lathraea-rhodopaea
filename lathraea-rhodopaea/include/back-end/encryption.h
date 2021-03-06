/*! @file encryption.h
*   @brief A header file for the encryption system.
*/

#pragma once
#include <string>
#include <vector>

/**
 * @brief A struct for a system that will encrypt a passsword
*/
struct EncryptionManager
{
	/**
	 * @brief Function for encrypting a password
	 * @param str The password in format of string
	 * @return The encrypted password in format of a vector
	*/
	std::vector<int> encrypt(std::string str);
};
