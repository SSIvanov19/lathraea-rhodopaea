/*! @file lathraeaRhodopaea.cpp
*   @brief The main source file of the program.
*/

#include <application.h>

/**
 * @brief The main entry point for the application
*/
int main()
{

	Application* app = new Application();
	app->run(app->accountManager, app->eventManager);	
}
