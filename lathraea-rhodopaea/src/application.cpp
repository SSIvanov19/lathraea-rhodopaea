/*! @file application.cpp
*   @brief A source file for the application.
*/

#include <application.h>

void Application::run(AccountManager accountManager)
{
	try
	{
		accountManager.isRegistrationSuccessful("Stoyan", "SS@cb.bg", "Password123", Roles::USER);
		accountManager.isLoginSuccessful("SS@cb.bg", "Password123");
	}
	catch (const std::string errorMsg)
	{
		std::cout << "The user can not be registered\nReason: " + errorMsg << std::endl;;
	}
	catch (...)
	{
		std::cout << "Problem occurred. Please restart the program!";
	}
}