/*! @file encryption.h
*   @brief A header file for the encryption system.
*/

#pragma once
#include <string>
#include <vector>

/**
 * @brief A struct for a system that will encrypt and decrypt a passsword
*/
struct EncryptionManager
{
	/**
	 * @brief Function for encrypting a password
	 * @param str The password in format of string
	 * @return The encrypted password in format of a vector
	*/
	std::vector<int> encrypt(std::string str); /*!< Function for encrypting a password */

	/**
	 * @brief Function for decrypting a password
	 * @param str The password in format of string
	 * @return The decrypted password in format of a vector
	*/
	std::string decrypt(std::vector<int> v); /*!< Function for decrypting a password */
};
