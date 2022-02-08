/*! @file encryption.cpp
*   @brief A source file for the encryption system.
*/

#include <back-end/encryption.h>

/**
 * @brief Function for converting from decimal to gray code
 * @param n The number in decimal
 * @return The number in gray code
*/
int applyGrayCode(const int n)
{
	/* Right Shift the number by 1
	   taking xor with original number */
	return n ^ (n >> 1);
}

/**
 * @brief Function for converting from gray code to decimal
 * @param n The number in gray code
 * @return The number in decimal
*/
int inversegrayCode(int n)
{
	int inv = 0;

	// Taking xor until n becomes zero
	for (; n; n = n >> 1)
	{
		inv ^= n;
	}

	return inv;
}

std::vector<int> EncryptionManager::encrypt(const std::string str)
{
	std::vector<int> returnVal;

	for (int el: str)
	{
		returnVal.push_back(applyGrayCode(el));
	}

	return returnVal;
}