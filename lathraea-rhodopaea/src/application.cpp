/*! @file application.cpp
*   @brief A source file for the application.
*/

#include <application.h>
#include <external/strptime.h>

void Application::run(AccountManager accountManager, EventManager eventManager)
{
	/**/
	try
	{
		// EventManager test
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
			{ "Vanya Velikoa", "Qsha Beibi"},
			true,
			1
		);

		eventManager.addWarEvent(
			"Crimean War",
			{ "16 oct 1853", "30 mar 1856"},
			{0, 0},
			{ "Ottoman Empire", "Russian Empire"},
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

		if (eventManager.removeEvent(&eventManager.eventList, "Movement ipsum"))
		{
			std::cout << "Event remove successfully!\n";
			eventManager.eventList->displayAllEvents(eventManager.eventList);
		}
		else
		{
			std::cout << "Event couldn't be find!\n";
		}

		std::string keyword = "Uprising";
		std::vector<Event> v = eventManager.getAllEventsWithTitle(eventManager.eventList, keyword);

		std::cout << "Found elements by keyword " + keyword + ":\n";

		for (Event el: v)
		{
			el.displayEventInfo();
			std::cout << std::endl << std::endl;
		}
		
		std::string date = "1 may 1876";

		DateManager dateManager;

		v = eventManager.getAllEventsWithDate(eventManager.eventList, dateManager.convertStringToDate(date));

		std::cout << "Found elements by date " << date << ":\n";

		for (Event el : v)
		{
			el.displayEventInfo();
			std::cout << std::endl << std::endl;
		}
	}
	catch (const std::string errorMsg)
	{
		std::cout << "The event can not be added\nReason: " + errorMsg << std::endl;;
	}
	catch (...)
	{
		std::cout << "Problem occurred. Please restart the program!";
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