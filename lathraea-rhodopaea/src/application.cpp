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

void Application::init(AccountManager& accountManager, EventManager& eventManager, StorylineManager& storylineManager)
{
	// Hide the cursor
	setCursorVisibilityTo(false);

	//setConsoleColorTo((int)COLORS::WHITE);

	/*
	// Premade events
	eventManager.addUprisingEvent(
		"April Uprising",
		{ "20 apr 1876", "15 may 1876" },
		{ 30, 76 },
		{ "Stefan Stambolov", "Ilarion Dragostinov", "Stoyan Zaimov", "Zahari Stoyanov" },
		false,
		200
	);
	

	eventManager.addUprisingEvent(
		"Uprising of Vanya Velikova",
		{ "18 sep 2021" },
		{ 45, 23 },
		{ "Vanya Velikoa", "Qsha Beibi" },
		true,
		1
	);

	eventManager.addWarEvent(
		"Crimean War",
		{ "16 oct 1853", "30 mar 1856" },
		{ 33, 43 },
		{ "Ottoman Empire", "Russian Empire" },
		"Otoman Empire",
		"Lorem ipsum"
	);

	eventManager.addMovementEvent(
		"Qsha movement",
		{ "19 jan 2020", "14 jan 2022" },
		{ 67, 23 },
		"Long story",
		"Djena e velika",
		"Qsha beibi",
		{ "Slavka Kalcheva",
		"1114131374",
		"Mariana Kalcheva",
		"Margarita Kalcheva",
		"Darina Kalcheva Georgieva-Pavlova",
		"Vanya Kycheck",
		"D-R Blagosweta Kalcheva",
		"D-R Svetla Kalcheva",
		"Debel Kalchev",
		"Rumena Kalcheva"
		},
		"Qsha jelqzko"
	);

	eventManager.addOtherEvent(
		"Giurgiu Revolutionary Committee",
		{ "11 nov 1875", "25 dec 1875" },
		{ 34, 56 },
		"Giurgiu Revolutionary Committee lorem ipsum lorem"
	);

	eventManager.addOtherEvent(
		"Qsha",
		{ "11 nov 1875", "25 dec 1875" },
		{ 67, 34 },
		"Giurgiu Revolutionary Committee lorem ipsum lorem"
	);

	eventManager.addOtherEvent(
		"Djana Koleva",
		{ "11 nov 1875", "25 dec 1875" },
		{ 46, 34 },
		"Giurgiu Revolutionary Committee lorem ipsum lorem"
	);

	//eventManager.approveEvent("April Uprising");
	eventManager.approveEvent("Uprising of Vanya Velikova");
	eventManager.approveEvent("Crimean War");
	eventManager.approveEvent("Qsha movement");
	eventManager.approveEvent("Giurgiu Revolutionary Committee");
	eventManager.approveEvent("Qsha");
	eventManager.approveEvent("Djana Koleva");

	storylineManager.addStoryline("Storyline 1", eventManager.sortAndGetAllEventsByDate(eventManager.getAllEvents(1)), "Sick desc");
	*/
}

void Application::run(AccountManager& accountManager, EventManager& eventManager, StorylineManager& storylineManager)
{
	try
	{
		//Loading page
		printMainPage();
		loadingAnimation();
		_getch();
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
			"Event managment",
			"Storyline managmet",
			"User managment",
			"Log out",
			"Exit"
		};

		char pressedKey;
		int selectedOption = 1;

		/*
		accountManager.registerUser(
			"SSIvanov19",
			"SSIvanov19@cb.bg",
			"Password123",
			Roles::USER
		);

		accountManager.loginUser(
			"SSIvanov19@cb.bg",
			"Password123"
		);
		*/

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
					switchMenuOptions(&eventManager, &storylineManager, &accountManager, pressedKey, selectedOption, adminMenuOptions);
				}
				else
				{
					outputOptions(userMenuOptions, selectedOption);
					pressedKey = _getch();
					switchMenuOptions(&eventManager, &storylineManager, &accountManager, pressedKey, selectedOption, userMenuOptions);
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
		std::cout << "The event can not be added\nReason: " + errorMsg << std::endl;;
	}
}
