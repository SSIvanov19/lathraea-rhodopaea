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
	
	try
	{
		LoggerManager loggerManager;
		loggerManager.log(LogSeverity::INFO, "Initializing the application");
		Application* app = new Application();
		app->init(app->accountManager, app->eventManager);
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
	}
	
	
}

