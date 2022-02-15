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

void Application::init(AccountManager& accountManager, EventManager& eventManager, StorylineManager& storylineManager)
{
	// Hide the cursor
	setCursor(false);

	// Premade events
	eventManager.addUprisingEvent(
		"April Uprising of 1876",
		{ "20 apr 1876", "15 may 1876" },
		{ 0, 0 },
		{ "Stefan Stambolov", "Ilarion Dragostinov", "Stoyan Zaimov", "Zahari Stoyanov" },
		false,
		200
	);

	eventManager.addUprisingEvent(
		"Uprising of Karposh",
		{ "10 oct 1689", "18 dec 1689"},
		{ 0, 0 },
		{ "Karposh", "Selim Girai" },
		true,
		1
	);

	eventManager.addWarEvent(
		"Crimean War",
		{ "5 oct 1853", "30 mar 1856" },
		{ 0, 0 },
		{ "Ottoman Empire", "Russian Empire" , "France",},
		{ "Otoman Empire" },
		{ "Influence on the declining Ottoman territories" }
	);

	eventManager.addMovementEvent(
		"Movement ipsum",
		{ "10 century" },
		{ 0 },
		"Long story",
		"Djena e velika",
		"Qsha beibi"
	);

	eventManager.addOtherEvent(
		"Giurgiu Revolutionary Committee",
		{ "11 nov 1875", "25 dec 1875" },
		{ 0, 0 },
		"Giurgiu Revolutionary Committee lorem ipsum lorem"
	);

	eventManager.addOtherEvent(
		"Qsha",
		{ "11 nov 1875", "25 dec 1875" },
		{ 0, 0 },
		"Giurgiu Revolutionary Committee lorem ipsum lorem"
	);

	eventManager.addOtherEvent(
		"Djana Koleva",
		{ "11 nov 1875", "25 dec 1875" },
		{ 0, 0 },
		"Giurgiu Revolutionary Committee lorem ipsum lorem"
	);
}

void Application::run(AccountManager& accountManager, EventManager& eventManager, StorylineManager& storylineManager)
{
	try
	{
		printMainPage();
		loadingAnimation();
		_getch();
		system("CLS");
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

		char pressedKey;
		int selectedOption = 1;
		bool firstTime = true;

		/*accountMenu(accountManager);
		if (isUserLogedIn)
		{*/
			while (selectedOption)
			{
				if (firstTime)
				{
					printClosedBook();
					printBookDecorations();
					printSnakeSword();
					printTeamLogo();
					firstTime = false;
				}

				outputOptions(menuOptions, selectedOption);
				pressedKey = _getch();
				switchMenuOptions(&eventManager, &storylineManager, pressedKey, selectedOption, menuOptions);
			}
		}
	/*}*/
	catch (const std::string errorMsg)
	{
		std::cout << "The event can not be added\nReason: " + errorMsg << std::endl;;
	}
}
