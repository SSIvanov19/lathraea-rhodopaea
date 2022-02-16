/*! @file application.cpp
*   @brief A source file for the application.
*/

#include <application.h>
#include <external/strptime.h>
#include <windows.h>
#include <conio.h>
#include <front-end/mainMenu.h>
#include <front-end/graphics.h>
#include <front-end/animations.h>
#include <front-end/loginMenu.h>
#include <front-end/output.h>
#include <front-end/enumerations.h>

void Application::init(
	AccountManager& accountManager,
	EventManager& eventManager,
	StorylineManager& storylineManager
)
{
	// Hide the cursor
	setCursorVisibilityTo(false);

	// Premade events
	eventManager.addOtherEvent(
		"Giurgiu Revolutionary Committee",
		{ "11 nov 1875", "25 dec 1875" },
		{ 85, 15 },
		"Example of other event"
	);

	eventManager.addOtherEvent(
		"Start of the uprising",
		{ "11 nov 1875" },
		{ 66, 26 },
		"Start of the April Uprising in Koprivshtitsa"
	);

	eventManager.addOtherEvent(
		"Batak massacre",
		{ "20 apr 1876" },
		{ 64, 30 },
		"Batak massacre"
	);

	eventManager.addOtherEvent(
		"Hristo Botev",
		{ "1 june 1876" },
		{ 54, 20 },
		"Hristo Botev's death"
	);

	eventManager.addOtherEvent(
		"Example 1",
		{ "1 june 1876" },
		{ 0, 0 }
	);

	eventManager.addOtherEvent(
		"Example 2",
		{ "1 june 1877" },
		{ 0, 0 }
	);

	eventManager.addOtherEvent(
		"Example 3",
		{ "1 june 1878" },
		{ 0, 0 }
	);

	eventManager.addOtherEvent(
		"Example 4",
		{ "1 june 1879" },
		{ 0, 0 }
	);

	eventManager.addOtherEvent(
		"Example 5",
		{ "1 june 1880" },
		{ 0, 0 }
	);

	eventManager.addOtherEvent(
		"Example 6",
		{ "1 june 1882" },
		{ 0, 0 }
	);
	
	eventManager.addUprisingEvent(
		"Uprising of Karposh",
		{ "10 oct 1689", "18 dec 1689" },
		{ 0, 0 },
		{ "Karposh", "Selim Girai" },
		false,
		200,
		"Uprising in North Macedonia"
	);

	eventManager.approveEvent("Example 1");
	eventManager.approveEvent("Example 2");
	eventManager.approveEvent("Example 3");
	eventManager.approveEvent("Example 4");
	eventManager.approveEvent("Example 5");
	eventManager.approveEvent("Example 6");

	storylineManager.addStoryline("Example Storyline", eventManager.sortAndGetAllEventsByDate(eventManager.getAllEvents(1)), "Example desc");

	eventManager.approveEvent("Giurgiu Revolutionary Committee");
	eventManager.approveEvent("Start of the uprising");
	eventManager.approveEvent("Batak massacre");
	eventManager.approveEvent("Hristo Botev");
	eventManager.approveEvent("Uprising of Karposh");
}

void Application::run(
	AccountManager& accountManager,
	EventManager& eventManager, 
	StorylineManager& storylineManager
)
{
	try
	{
		//Loading page
		printMainPage();
		loadingAnimation();
		(void)_getch();
		clearConsole();

		const std::vector<std::string> loginOptions =
		{
			"Login",
			"Register"
		};

		const std::vector<std::string> userMenuOptions =
		{
			"Add historical event",
			"Visualize added events",
			"Add storyline",
			"Visualize storylines",
			"Log out",
			"About us",
			"Exit"
		};

		const std::vector<std::string> adminMenuOptions =
		{
			"Event management",
			"Storyline managemet",
			"User management",
			"Log out",
			"Exit"
		};

		char pressedKey;
		int selectedOption = 1;

		printClosedBook();
		printBookDecorations();
		printSnakeSword();
		printTeamLogo();

		while (selectedOption)
		{
			if (accountManager.isUserLoggedIn())
			{
				if (accountManager.isAdmin())
				{
					outputOptions(adminMenuOptions, selectedOption);
					pressedKey = _getch();
					switchMenuOptions(
						&eventManager, 
						&storylineManager,
						&accountManager,
						pressedKey, 
						selectedOption, 
						adminMenuOptions
					);
				}
				else
				{
					outputOptions(userMenuOptions, selectedOption);
					pressedKey = _getch();
					switchMenuOptions(
						&eventManager,
						&storylineManager,
						&accountManager, 
						pressedKey, 
						selectedOption, 
						userMenuOptions
					);
				}
			}
			else
			{
				accountMenu(accountManager);
			}
		}
	}
	catch (const std::string errorMsg)
	{
		std::cout << "The event can not be added\nReason: " + errorMsg << std::endl;
	}
}
