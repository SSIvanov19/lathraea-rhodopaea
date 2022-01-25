/*! @file env.h
*   @brief A header file for the managing the environment variables.
*/

#pragma once
#include <string>

/**
 * @brief A struct for the system for managing the environment variables.
*/
static struct EnvManager
{
	/**
	 * @brief A function for getting environment variable
	 * @param var The name of the variable to be getted
	 * @return The environment variable
	*/
	std::string getEnv(const char* var); /*!< A function for getting environment variable */
} envManager;