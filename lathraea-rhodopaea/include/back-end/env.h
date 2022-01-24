/*! @file env.h
*   @brief A header file for the managing the environment variables.
*/

#pragma once
#include <string>

static struct EnvManager
{
	std::string getEnv(const char* var);
} envManager;