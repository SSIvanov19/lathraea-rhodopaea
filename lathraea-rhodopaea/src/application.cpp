/*! @file application.cpp
*   @brief A source file for the application.
*/

#include <application.h>
#include <external/strptime.h>
#include <windows.h>
#include <conio.h>
#include <front-end/mainMenu.h>
#include <front-end/graphics.h>
#include <front-end/loginMenu.h>
#include <front-end/output.h>

void Application::init(AccountManager& accountManager, EventManager& eventManager)
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
		"Uprising of Vanya Velikova",
		{ "18 sep 2021" },
		{ 0, 0 },
		{ "Vanya Velikoa", "Qsha Beibi" },
		true,
		1
	);

	eventManager.addWarEvent(
		"Crimean War",
		{ "16 oct 1853", "30 mar 1856" },
		{ 0, 0 },
		{ "Ottoman Empire", "Russian Empire" },
		"Otoman Empire",
		"Lorem ipsum"
	);

	eventManager.addMovementEvent(
		"Movement ipsum",
		{ "16 oct 1153", "30 mar 1157" },
		{ 0, 0 },
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
}

void Application::run(AccountManager& accountManager, EventManager& eventManager)
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
					prinyBookDecorations();
					printSnakeSword();
					printTeamLogo();
					firstTime = false;
				}

				outputOptions(menuOptions, selectedOption);
				pressedKey = _getch();
				switchMenuOptions(&eventManager, pressedKey, selectedOption, menuOptions);
			}
		}
	/*}*/
	catch (const std::string errorMsg)
	{
		std::cout << "The event can not be added\nReason: " + errorMsg << std::endl;;
	}
}
