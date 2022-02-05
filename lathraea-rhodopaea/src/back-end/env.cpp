/*! @file env.cpp
*   @brief A source file for the managing the environment variables.
*/

#include <back-end/env.h>
#include <external/dotenv.h>
#include <back-end/errorManager.h>

std::string EnvManager::getEnv(const char* var)
{
	dotenv::init("../.env");

	char* val = std::getenv(var);

	if (val == NULL)
	{
		throw ErrorHandler("env.cpp", "getEnv()", "Environment variable not found!");
	}
	else
	{
		return val;
	}
}
