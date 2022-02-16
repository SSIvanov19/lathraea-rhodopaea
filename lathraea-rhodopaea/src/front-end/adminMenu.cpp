/*! @file adminMenu.cpp
*   @brief A source file for the admin menu handaling system.
*/

#include <front-end/output.h>
#include <front-end/graphics.h>
#include <front-end/adminMenu.h>
#include <front-end/enumerations.h>
#include <front-end/eventManagerMenu.h>
#include <front-end/userManagementMenu.h>
#include <front-end/storylineManagerMenu.h>

void adminStorylineManagement(
	EventManager* eventManager,
	StorylineManager* storylineManager,
	AccountManager* accountManager
)
{
	const std::vector<std::string> options{
		"Add new storyline",
		"Approve storyline",
		"Display storyline",
		"Remove storyline"
	};

	printFullyOpenedBook();
	outputPosition(81, 10);
	std::cout << "Choose what do you want to do:";

	int selectedOption = 1;
	char pressedKey = ' ';

	while (pressedKey != (int)ARROW_KEYS::KEY_ENTER)
	{
		for (int i = 0; i < options.size(); i++)
		{
			if (i + 1 == selectedOption)
			{
				outputPosition(81, 12 + i * 2);
				std::cout << "-> ";
			}
			else
			{
				outputPosition(81, 12 + i * 2);
				std::cout << "   ";
			}
			std::cout << options[i] << std::endl << std::endl;
		}

		pressedKey = _getch();

		switch (pressedKey)
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
			if (selectedOption == options.size() + 1)
			{
				selectedOption -= 1;
			}
			break;
		case (int)ARROW_KEYS::KEY_ENTER:
			clearConsole();
			printFullyOpenedBook();

			switch (selectedOption)
			{
			case 1:
				// Add new storyline
				createStoryline(
					eventManager,
					storylineManager,
					accountManager, 
					true
				);
				break;
			case 2:
				// Approve storyline
				approveStoryline(storylineManager);
				break;
			case 3:
				// Display storylines
				displayStoryline(storylineManager, true);
				break;
			case 5:
				deleteStoryline(storylineManager);
				break;
			}
		case (int)ARROW_KEYS::KEY_ESC:
			// Return to main menu
			clearConsole();
			printClosedBook();
			printBookDecorations();
			printSnakeSword();
			printTeamLogo();
			return;
			break;
		}
	}

	if (_getch())
	{
		clearConsole();
		printClosedBook();
		printBookDecorations();
		printSnakeSword();
		printTeamLogo();
	}
}


void adminEventManagement(
	EventManager* eventManager,
	StorylineManager* storylineManager
)
{
	const std::vector<std::string> options{
		"Add new history event",
		"Approve event",
		"Display event",
		"Edit event",
		"Remove event"
	};

	printFullyOpenedBook();
	outputPosition(81, 10);
	std::cout << "Choose what do you want to do:";

	int selectedOption = 1;
	char pressedKey = ' ';

	while (pressedKey != (int)ARROW_KEYS::KEY_ENTER)
	{
		for (int i = 0; i < options.size(); i++)
		{
			if (i + 1 == selectedOption)
			{
				outputPosition(81, 12 + i * 2);
				std::cout << "-> ";
			}
			else
			{
				outputPosition(81, 12 + i * 2);
				std::cout << "   ";
			}
			std::cout << options[i] << std::endl << std::endl;
		}

		pressedKey = _getch();

		switch (pressedKey)
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
			if (selectedOption == options.size() + 1)
			{
				selectedOption -= 1;
			}
			break;
		case (int)ARROW_KEYS::KEY_ENTER:
			clearConsole();
			printFullyOpenedBook();

			switch (selectedOption)
			{
			case 1:
				// Add new history event
				addEvent(eventManager, true);
				break;
			case 2:
				// Approve event
				approveEvent(eventManager);
				break;
			case 3:
				// Display event
				displayEvents(eventManager, true);
				break;
			case 4:
				// Edit event
				editEvent(eventManager);
				break;
			case 5:
				// Remove event
				deleteEvent(eventManager);
				break;
			}
		case (int)ARROW_KEYS::KEY_ESC:
			// Return to main menu
			clearConsole();
			printClosedBook();
			printBookDecorations();
			printSnakeSword();
			printTeamLogo();
			return;
			break;
		}
	}

	if (_getch())
	{
		clearConsole();
		printClosedBook();
		printBookDecorations();
		printSnakeSword();
		printTeamLogo();
	}
}

void adminUserManagement(AccountManager* accountManager)
{
	const std::vector<std::string> options{
		"View all users",
		"Add new admin"
	};

	printFullyOpenedBook();
	outputPosition(81, 10);
	std::cout << "Choose what do you want to do:";

	int selectedOption = 1;
	char pressedKey = ' ';

	while (pressedKey != (int)ARROW_KEYS::KEY_ENTER)
	{
		for (int i = 0; i < options.size(); i++)
		{
			if (i + 1 == selectedOption)
			{
				outputPosition(81, 12 + i * 2);
				std::cout << "-> ";
			}
			else
			{
				outputPosition(81, 12 + i * 2);
				std::cout << "   ";
			}
			std::cout << options[i] << std::endl << std::endl;
		}

		pressedKey = _getch();

		switch (pressedKey)
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
			if (selectedOption == options.size() + 1)
			{
				selectedOption -= 1;
			}
			break;
		case (int)ARROW_KEYS::KEY_ENTER:
			clearConsole();
			printFullyOpenedBook();

			switch (selectedOption)
			{
			case 1:
				// View all users
				viewAllUsers(accountManager);
				break;
			case 2:
				// Add new admin
				addNewAdmin(accountManager);
				break;
			}
		case (int)ARROW_KEYS::KEY_ESC:
			// Return to main menu
			clearConsole();
			printClosedBook();
			printBookDecorations();
			printSnakeSword();
			printTeamLogo();
			return;
			break;
		}
	}

	if (_getch())
	{
		clearConsole();
		printClosedBook();
		printBookDecorations();
		printSnakeSword();
		printTeamLogo();
	}
}
