/*! @file env.cpp
*   @brief A source file for the managing the environment variables.
*/

#include <back-end/env.h>
#include <external/dotenv.h>

std::string EnvManager::getEnv(const char* var)
{
	dotenv::init("../.env");

	char* val = std::getenv(var);

	if (val == NULL)
	{
		throw std::string("Environment variable not found");
	}
	else
	{
		return val;
	}
}
