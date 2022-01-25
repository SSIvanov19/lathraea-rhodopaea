/*! @file encryption.h
*   @brief A header file for the encryption system.
*/

#pragma once
#include <string>
#include <vector>

/**
 * @brief A struct for a system that will encrypt and decrypt a passsword
*/
static struct EncryptionManager
{
	std::vector<int> encrypt(std::string str);

	std::string decrypt(std::vector<int> v);
} encryptionManager;
