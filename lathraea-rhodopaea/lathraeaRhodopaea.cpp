/*! @file lathraeaRhodopaea.cpp
*   @brief The main source file of the program.
*/

#include <application.h>
#include <windows.h>
#include <conio.h>
#include <front-end/mainMenu.h>

/**
 * @brief The main entry point for the application
*/
int main()
{
		/*try
	{
		LoggerManager loggerManager;
		loggerManager.log(LogSeverity::INFO, "Initializing the application");
		Application* app = new Application();
		app->run(app->accountManager, app->eventManager);
	}
	catch (ErrorHandler error)
	{
		if (error.errorCode != NULL)
		{
			LoggerManager loggerManager;
			loggerManager.log(
				LogSeverity::ERR,
				"File: " + error.fileName +
				", Function: " + error.functionName +
				", Error code: " + std::to_string(error.errorCode) +
				", Message: " + error.errorMsg
			);
		}
		else
		{
			LoggerManager loggerManager;
			loggerManager.log(
				LogSeverity::ERR,
				"File: " + error.fileName +
				", Function: " + error.functionName +
				", Message: " + error.errorMsg
			);
		}

		std::cout << error.errorMsg + "\nThe program is going to close itself!\n"
			"See the log file for more information";
	}
	catch (...)
	{
		std::cout << "There was a problem with the program and it is going to close"
			"itself!\nSee the log file for more information";
	}*/

	/*TO-DO - FIX BUGS*/
	std::vector<std::string> loginOptions =
	{
		"Login",
		"Register"
	};

	std::vector<std::string> menuOptions =
	{
		"Add historical event",
		"Remove historical event",
		"Edit historical events",
		"Visualize added events",
		"Connect events",
		"About us",
		"Exit"
	};

	std::vector<std::string> visualizationOptions =
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
		hoverMenuOptions(pressedKey, selectedOption, menuOptions);
	}

}

