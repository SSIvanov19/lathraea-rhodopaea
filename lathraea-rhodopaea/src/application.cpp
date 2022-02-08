/*! @file application.cpp
*   @brief A source file for the application.
*/

#include <application.h>
#include <external/strptime.h>
#include <windows.h>
#include <conio.h>
#include <front-end/mainMenu.h>

void Application::run(AccountManager accountManager, EventManager eventManager)
{
	try
	{
		const std::vector<std::string> loginOptions =
		{
			"Login",
			"Register"
		};

		const std::vector<std::string> menuOptions =
		{
			"Add historical event",
			"Remove historical event",
			"Edit historical events",
			"Visualize added events",
			"Connect events",
			"About us",
			"Exit"
		};

		const std::vector<std::string> visualizationOptions =
		{
			"As a map",
			"As a timeline",
			"As an encyclopedia"
		};

		char pressedKey;
		int selectedOption = 1;

		while (selectedOption)
		{
			outputOptions(menuOptions, selectedOption);
			pressedKey = _getch();
			switchMenuOptions(&eventManager, pressedKey, selectedOption, menuOptions);
		}
	}
	catch (const std::string errorMsg)
	{
		std::cout << "The event can not be added\nReason: " + errorMsg << std::endl;;
	}
	
	/* Account system test
	try
	{
		accountManager.isRegistrationSuccessful("Stoyan", "SS@cb.bg", "Password123", Roles::USER);
		if (accountManager.isLoginSuccessful("admin@cb.bg", "password123"))
		{
			std::cout << "Logging is successfully\nLogged user info:\n";
			accountManager.activeUser->displayUserInfo();
		}
	}
	catch (const std::string errorMsg)
	{
		std::cout << "The user can not be registered\nReason: " + errorMsg << std::endl;;
	}
	catch (...)
	{
		std::cout << "Problem occurred. Please restart the program!";
	}
	*/
}