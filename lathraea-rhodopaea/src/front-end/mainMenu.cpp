/*! @file mainMenu.cpp
*   @brief A source file for the main menu handaling system.
*/

#include <front-end/output.h>
#include <front-end/graphics.h>
#include <front-end/adminMenu.h>
#include <front-end/animations.h>
#include <front-end/enumerations.h>
#include <front-end/eventManagerMenu.h>
#include <front-end/userManagementMenu.h>
#include <front-end/storylineManagerMenu.h>
#include <application.h>

/**
 * @brief Function for printing the main menu options
 * @param possibleOptions The possible options
 * @param selectedOption The selected option
*/
void outputOptions(std::vector<std::string> possibleOptions, int& selectedOption)
{
	for (int i = 0; i < possibleOptions.size(); i++)
	{
		if (i + 1 == selectedOption)
		{
			outputPosition(6, 18 + i * 2);
			std::cout << "-> ";
		}
		else
		{
			outputPosition(6, 18 + i * 2);
			std::cout << "   ";
		}

		std::cout << possibleOptions[i] << std::endl << std::endl;
	}
}

/**
 * @brief Function for coloring hovered options
 * @param eventManager Variable for an event manager
 * @param key The pressed button
 * @param selectedOption The selected option
 * @param possibleOptions The possible options
*/
void switchMenuOptions(
	EventManager* eventManager,
	StorylineManager* storylineManager,
	AccountManager* accountManager,
	char key,
	int& selectedOption,
	std::vector<std::string> possibleOptions
)
{
	switch (key)
	{
	case (int)ARROW_KEYS::KEY_UP:
		selectedOption--;
		if (selectedOption == 0)
		{
			selectedOption += 1;
		}
		break;

	case (int)ARROW_KEYS::KEY_DOWN:
		selectedOption++;
		if (selectedOption == possibleOptions.size() + 1)
		{
			selectedOption -= 1;
		}
		break;
	case (int)ARROW_KEYS::KEY_ENTER:
		clearConsole();

		if (accountManager->isAdmin())
		{
			switch (selectedOption)
			{
			case 1:
				//Event Management
				bookOpeningAnimation();
				adminEventManagement(eventManager, storylineManager);
				break;
			case 2:
				//Storyline management
				bookOpeningAnimation();
				adminStorylineManagement(
					eventManager,
					storylineManager,
					accountManager
				);
				break;
			case 3:
				// User Management
				bookOpeningAnimation();
				adminUserManagement(accountManager);
				break;
			case 4:
				// Log out
				accountManager->logoutUser();
				break;
			case 5:
				// Exit
				clearConsole();
				exit(0);
				break;
			}
		}
		else
		{
			switch (selectedOption)
			{
			case 1:
				// Add events
				bookOpeningAnimation();
				addEvent(eventManager, false);
				break;
			case 2:
				// Visualise event
				bookOpeningAnimation();
				displayEvents(eventManager);
				break;
			case 3:
				// Create Storyline
				bookOpeningAnimation();
				createStoryline(eventManager, storylineManager, accountManager, true);
				break;
			case 4:;
				//Visualisation of storyline
				bookOpeningAnimation();
				displayStoryline(storylineManager);
				break;
			case 5:
				//Log out
				accountManager->logoutUser();
				break;
			case 6:
				// About us
				clearConsole();
				printaboutUs();
				printText();
				(void)_getch();
				clearConsole();
				printClosedBook();
				printBookDecorations();
				printSnakeSword();
				printTeamLogo();
				break;
			case 7:
				// Exit 
				clearConsole();
				exit(0);
				break;
			}
		}
	}
}