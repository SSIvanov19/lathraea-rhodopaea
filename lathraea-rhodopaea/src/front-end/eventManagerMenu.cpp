/*! @file eventManagerMenu.cpp
*   @brief A source file for the event menu handaling system.
*/

#include <front-end/output.h>
#include <front-end/graphics.h>
#include <front-end/enumerations.h>
#include <front-end/helperFunctions.h>
#include <front-end/eventManagerMenu.h>

void addOtherEvent(EventManager* eventManager, bool approve)
{
	printFullyOpenedBook();
	std::string title;
	outputPosition(81, 10);
	std::cout << "Enter the title of the event you want to add: " << std::endl;
	outputPosition(81, 12);
	getline(std::cin, title);

	while (title.empty())
	{
		outputPosition(81, 12);
		std::cout << "Title can not be empty, please enter again: ";
		outputPosition(81, 14);
		getline(std::cin, title);
	}

	printFullyOpenedBook();
	std::string period;
	outputPosition(81, 10);
	std::cout << "Enter the starting and ending year and date";
	outputPosition(81, 12);
	std::cout << "Example - (20 apr 1876, 15 may 1876)";
	outputPosition(81, 14);
	getline(std::cin, period);

	while (!checkDatesValidation(period))
	{
		outputPosition(81, 14);
		std::cout << "The data you've entered is incorrect!";
		outputPosition(81, 16);
		std::cout << "Please enter a date/s - ex(24 apr 809, 27 apr 810)";
		outputPosition(81, 18);
		getline(std::cin, period);
	}
	separateDates(period);

	printFullyOpenedBook();
	printMapPopUp();
	printBulgarianMap();
	short x = 56;
	short y = 20;
	char key;
	outputPosition(x, y);
	std::cout << char(254);
	while ((key = _getch()) != (char)ARROW_KEYS::KEY_ENTER)
	{
		switch (key)
		{
		case (char)ARROW_KEYS::KEY_UP:
			outputPosition(x, y);
			std::cout << " ";
			y -= 1;
			outputPosition(x, y);
			std::cout << char(254);
			break;
		case (char)ARROW_KEYS::KEY_DOWN:
			outputPosition(x, y);
			std::cout << " ";
			y += 1;
			outputPosition(x, y);
			std::cout << char(254);
			break;
		case (char)ARROW_KEYS::KEY_LEFT:
			outputPosition(x, y);
			std::cout << " ";
			x += 1;
			outputPosition(x, y);
			std::cout << char(254);

			break;
		case (char)ARROW_KEYS::KEY_RIGHT:

			outputPosition(x, y);
			std::cout << " ";
			x -= 1;
			outputPosition(x, y);
			std::cout << char(254);
			break;
		case (char)ARROW_KEYS::KEY_ENTER:
			printFullyOpenedBook();
			break;
		}
	}
	Coordinates coordinates{ x, y };

	printFullyOpenedBook();
	std::string additionalNotes;
	outputPosition(81, 10);
	std::cout << "Enter some additional notes for the event, if any: ";
	outputPosition(81, 12);
	getline(std::cin, additionalNotes);

	try
	{
		eventManager->addOtherEvent(title, separateDates(period), coordinates, additionalNotes);
	}
	catch (std::string errorMessage)
	{
		std::cout << errorMessage;
	}
}

void addUprisingEvent(EventManager* eventManager, bool approve)
{
	std::string title;
	printFullyOpenedBook();
	outputPosition(81, 10);
	std::cout << "Enter the title of the event you want to add: " << std::endl;
	outputPosition(81, 12);
	getline(std::cin, title);

	while (title.empty())
	{
		outputPosition(81, 12);
		std::cout << "Title can not be empty, please enter again: ";
		outputPosition(81, 14);
		getline(std::cin, title);
	}
	printFullyOpenedBook();
	std::string period;
	outputPosition(81, 10);
	std::cout << "Enter the starting and ending year and date";
	outputPosition(81, 12);
	std::cout << "Example - (20 apr 1876, 15 may 1876)";
	outputPosition(81, 14);
	getline(std::cin, period);

	while (!checkDatesValidation(period))
	{
		outputPosition(81, 14);
		std::cout << "The data you've entered is incorrect!";
		outputPosition(81, 16);
		std::cout << "Please enter a date/s - ex(24 apr 809, 27 apr 810)";
		outputPosition(81, 18);
		std::cout << "                                                  ";
		outputPosition(81, 18);
		getline(std::cin, period);
	}
	separateDates(period);

	printFullyOpenedBook();
	printMapPopUp();
	printBulgarianMap();
	short x = 56;
	short y = 20;
	char key;
	outputPosition(x, y);
	std::cout << char(254);
	while ((key = _getch()) != (char)ARROW_KEYS::KEY_ENTER)
	{
		switch (key)
		{
		case (char)ARROW_KEYS::KEY_UP:
			outputPosition(x, y);
			std::cout << " ";
			y -= 1;
			outputPosition(x, y);
			std::cout << char(254);
			break;
		case (char)ARROW_KEYS::KEY_DOWN:
			outputPosition(x, y);
			std::cout << " ";
			y += 1;
			outputPosition(x, y);
			std::cout << char(254);
			break;
		case (char)ARROW_KEYS::KEY_LEFT:
			outputPosition(x, y);
			std::cout << " ";
			x += 1;
			outputPosition(x, y);
			std::cout << char(254);
			break;
		case (char)ARROW_KEYS::KEY_RIGHT:
			outputPosition(x, y);
			std::cout << " ";
			x -= 1;
			outputPosition(x, y);
			std::cout << char(254);
			break;
		case (char)ARROW_KEYS::KEY_ENTER:
			printFullyOpenedBook();
			break;
		}
	}
	Coordinates coordinates{ x, y };

	std::string organizers;
	printFullyOpenedBook();
	outputPosition(81, 10);
	std::cout << "Enter the organizers of the event you want to add: ";
	outputPosition(81, 12);
	getline(std::cin, organizers);

	while (organizers.empty())
	{
		outputPosition(81, 12);
		std::cout << "Organizers can not be empty, please enter again: ";
		outputPosition(81, 14);
		getline(std::cin, organizers);
	}

	std::vector<std::string> organizersV;
	organizersV.push_back(organizers);

	printFullyOpenedBook();
	bool isItSuccessful = true;
	const std::vector<std::string> successOfEventOptions = {
		"Successful",
		"Unsuccessful"
	};

	outputPosition(81, 10);
	std::cout << "Is the event successful?";

	int selectedOption = 1;
	char pressedKey = ' ';

	while (pressedKey != (int)ARROW_KEYS::KEY_ENTER)
	{
		for (int i = 0; i < successOfEventOptions.size(); i++)
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
			std::cout << successOfEventOptions[i] << std::endl << std::endl;
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
			if (selectedOption == successOfEventOptions.size() + 1)
			{
				selectedOption -= 1;
			}
			break;
		case (int)ARROW_KEYS::KEY_ENTER:
			switch (selectedOption)
			{
			case 1:
				isItSuccessful = true;
				printFullyOpenedBook();
				break;
			case 2:
				isItSuccessful = false;
				printFullyOpenedBook();
				break;
			}
		}
	}

	int numberOfRebelions;
	printFullyOpenedBook();
	outputPosition(81, 10);
	std::cout << "Enter the number of rebellions of the event: ";
	outputPosition(81, 12);
	std::cin >> numberOfRebelions;

	std::string additionalNotes;
	printFullyOpenedBook();
	outputPosition(81, 10);
	std::cout << "Enter some additional notes for the event, if any: ";
	outputPosition(81, 12);
	std::cin.ignore(INT_MAX, '\n');
	getline(std::cin, additionalNotes);

	try
	{
		eventManager->addUprisingEvent(
			title,
			separateDates(period), 
			coordinates, 
			organizersV,
			isItSuccessful,
			numberOfRebelions,
			additionalNotes
		);

		if (approve)
		{
			eventManager->approveEvent(title);
		}
	}
	catch (std::string errorMessage)
	{
		std::cout << errorMessage;
	}
}

void addWarEvent(EventManager* eventManager, bool approve)
{
	printFullyOpenedBook();
	std::string title;
	outputPosition(81, 10);
	std::cout << "Enter the title of the event you want to add: " << std::endl;
	outputPosition(81, 12);
	getline(std::cin, title);

	while (title.empty())
	{
		outputPosition(81, 12);
		std::cout << "Title can not be empty, please enter again: ";
		outputPosition(81, 14);
		getline(std::cin, title);
	}

	printFullyOpenedBook();
	std::string period;
	outputPosition(81, 10);
	std::cout << "Enter the starting and ending year and date";
	outputPosition(81, 12);
	std::cout << "Example - (20 apr 1876, 15 may 1876)";
	outputPosition(81, 14);
	getline(std::cin, period);

	while (!checkDatesValidation(period))
	{
		outputPosition(81, 14);
		std::cout << "The data you've entered is incorrect!";
		outputPosition(81, 16);
		std::cout << "Please enter a date/s - ex(24 apr 809, 27 apr 810)";
		outputPosition(81, 18);
		getline(std::cin, period);
	}
	separateDates(period);

	printFullyOpenedBook();
	printMapPopUp();
	printBulgarianMap();
	short x = 56;
	short y = 20;
	char key;
	outputPosition(x, y);
	std::cout << char(254);
	while ((key = _getch()) != (char)ARROW_KEYS::KEY_ENTER)
	{
		switch (key)
		{
		case (char)ARROW_KEYS::KEY_UP:
			outputPosition(x, y);
			std::cout << " ";
			y -= 1;
			outputPosition(x, y);
			std::cout << char(254);
			break;
		case (char)ARROW_KEYS::KEY_DOWN:
			outputPosition(x, y);
			std::cout << " ";
			y += 1;
			outputPosition(x, y);
			std::cout << char(254);
			break;
		case (char)ARROW_KEYS::KEY_LEFT:
			outputPosition(x, y);
			std::cout << " ";
			x += 1;
			outputPosition(x, y);
			std::cout << char(254);
			break;
		case (char)ARROW_KEYS::KEY_RIGHT:
			outputPosition(x, y);
			std::cout << " ";
			x -= 1;
			outputPosition(x, y);
			std::cout << char(254);
			break;
		case (char)ARROW_KEYS::KEY_ENTER:
			printFullyOpenedBook();
			break;
		}
	}
	Coordinates coordinates{ x, y };

	printFullyOpenedBook();
	std::string participatingCountries;
	outputPosition(81, 10);
	std::cout << "Enter the countries participating in the event: ";
	outputPosition(81, 12);
	getline(std::cin, participatingCountries);

	while (participatingCountries.empty())
	{
		outputPosition(81, 12);
		std::cout << "Participating countries can not be empty!";
		outputPosition(81, 12);
		std::cout << "Please enter again: ";
		outputPosition(81, 14);
		getline(std::cin, participatingCountries);
	}

	std::vector<std::string> participatingCountriesV;
	participatingCountriesV.push_back(participatingCountries);

	printFullyOpenedBook();
	std::string winner;
	outputPosition(81, 10);
	std::cout << "Enter the winner of the event you want to add: " << std::endl;
	outputPosition(81, 12);
	getline(std::cin, winner);

	while (winner.empty())
	{
		outputPosition(81, 12);
		std::cout << "Winner can not be empty, please enter again: ";
		outputPosition(81, 14);
		getline(std::cin, winner);
	}

	printFullyOpenedBook();
	std::string reasons;
	outputPosition(81, 10);
	std::cout << "Enter the reason that led to the event: " << std::endl;
	outputPosition(81, 12);
	getline(std::cin, reasons);

	while (reasons.empty())
	{
		outputPosition(81, 12);
		std::cout << "Reasons can not be empty, please enter again: ";
		outputPosition(81, 14);
		getline(std::cin, reasons);
	}

	printFullyOpenedBook();
	std::string rulers;
	outputPosition(81, 10);
	std::cout << "Enter the rulers of the event you want to add: ";
	outputPosition(81, 12);
	getline(std::cin, rulers);

	while (rulers.empty())
	{
		outputPosition(81, 12);
		std::cout << "Rulers can not be empty, please enter again: ";
		outputPosition(81, 14);
		getline(std::cin, rulers);
	}

	std::vector<std::string> rulersV;
	rulersV.push_back(rulers);

	printFullyOpenedBook();
	std::string additionalNotes;
	outputPosition(81, 10);
	std::cout << "Enter some additional notes for the event, if any: ";
	outputPosition(81, 12);
	getline(std::cin, additionalNotes);

	try
	{
		eventManager->addWarEvent(
			title,
			separateDates(period),
			coordinates,
			participatingCountriesV,
			winner,
			reasons,
			rulersV,
			additionalNotes
		);
		if (approve)
		{
			eventManager->approveEvent(title);
		}
	}
	catch (std::string errorMessage)
	{
		std::cout << errorMessage;
	}
}

void addMovementEvent(EventManager* eventManager, bool approve)
{
	printFullyOpenedBook();
	std::string title;
	outputPosition(81, 10);
	std::cout << "Enter the title of the event you want to add: " << std::endl;
	outputPosition(81, 12);
	getline(std::cin, title);

	while (title.empty())
	{
		outputPosition(81, 12);
		std::cout << "Title can not be empty, please enter again: ";
		outputPosition(81, 14);
		getline(std::cin, title);
	}

	printFullyOpenedBook();
	std::string period;
	outputPosition(81, 10);
	std::cout << "Enter the starting and ending year and date";
	outputPosition(81, 12);
	std::cout << "Example - (20 apr 1876, 15 may 1876)";
	outputPosition(81, 14);
	getline(std::cin, period);

	while (!checkDatesValidation(period))
	{
		outputPosition(81, 14);
		std::cout << "The data you've entered is incorrect!";
		outputPosition(81, 16);
		std::cout << "Please enter a date/s - ex(24 apr 809, 27 apr 810)";
		outputPosition(81, 18);
		getline(std::cin, period);
	}
	separateDates(period);

	printFullyOpenedBook();
	printMapPopUp();
	printBulgarianMap();
	short x = 56;
	short y = 20;
	char key;
	outputPosition(x, y);
	std::cout << char(254);
	while ((key = _getch()) != (char)ARROW_KEYS::KEY_ENTER)
	{
		switch (key)
		{
		case (char)ARROW_KEYS::KEY_UP:
			outputPosition(x, y);
			std::cout << " ";
			y -= 1;
			outputPosition(x, y);
			std::cout << char(254);
			break;
		case (char)ARROW_KEYS::KEY_DOWN:
			outputPosition(x, y);
			std::cout << " ";
			y += 1;
			outputPosition(x, y);
			std::cout << char(254);
			break;
		case (char)ARROW_KEYS::KEY_LEFT:
			outputPosition(x, y);
			std::cout << " ";
			x += 1;
			outputPosition(x, y);
			std::cout << char(254);
			break;
		case (char)ARROW_KEYS::KEY_RIGHT:
			outputPosition(x, y);
			std::cout << " ";
			x -= 1;
			outputPosition(x, y);
			std::cout << char(254);
			break;
		case (char)ARROW_KEYS::KEY_ENTER:
			printFullyOpenedBook();
			break;
		}
	}
	Coordinates coordinates{ x, y };

	printFullyOpenedBook();
	std::string howItStarted;
	outputPosition(81, 10);
	std::cout << "Enter the way the event started: " << std::endl;
	outputPosition(81, 12);
	getline(std::cin, howItStarted);

	while (howItStarted.empty())
	{
		outputPosition(81, 12);
		std::cout << "The way it started can not be empty!";
		outputPosition(81, 14);
		std::cout << "Please enter again: ";
		outputPosition(81, 16);
		getline(std::cin, howItStarted);
	}

	printFullyOpenedBook();
	std::string ideas;
	outputPosition(81, 10);
	std::cout << "Enter ideas of the event you want to add: " << std::endl;
	outputPosition(81, 12);
	getline(std::cin, ideas);

	while (ideas.empty())
	{
		outputPosition(81, 12);
		std::cout << "The ideas can not be empty, please enter again: ";
		outputPosition(81, 14);
		getline(std::cin, ideas);
	}

	printFullyOpenedBook();
	std::string aims;
	outputPosition(81, 10);
	std::cout << "Enter the aims of the event you want to add: " << std::endl;
	outputPosition(81, 12);
	getline(std::cin, aims);

	while (aims.empty())
	{
		outputPosition(81, 10);
		std::cout << "The aims can not be empty, please enter again: ";
		outputPosition(81, 12);
		getline(std::cin, aims);
	}

	printFullyOpenedBook();
	std::string representatives;
	outputPosition(81, 10);
	std::cout << "Enter the representatives of the event: ";
	outputPosition(81, 12);
	getline(std::cin, representatives);

	while (representatives.empty())
	{
		outputPosition(81, 12);
		std::cout << "The representatives can not be empty!";
		outputPosition(81, 14);
		std::cout << "Please enter again: ";
		outputPosition(81, 16);
		getline(std::cin, representatives);
	}

	std::vector<std::string> representativesV;
	representativesV.push_back(representatives);

	printFullyOpenedBook();
	std::string additionalNotes;
	outputPosition(81, 10);
	std::cout << "Enter some additional notes for the event, if any: ";
	outputPosition(81, 12);
	getline(std::cin, additionalNotes);
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		outputPosition(81, 10);
		std::cout << "Enter some additional notes for the event, if any: ";
		outputPosition(81, 12);
		getline(std::cin, additionalNotes);
	}

	try
	{
		eventManager->addMovementEvent(
			title,
			separateDates(period),
			coordinates, 
			howItStarted, 
			ideas, 
			aims, 
			representativesV, 
			additionalNotes
		);

		if (approve)
		{
			eventManager->approveEvent(title);
		}
	}
	catch (std::string errorMessage)
	{
		std::cout << errorMessage;
	}
}

void addEvent(EventManager* eventManager, bool approve)
{
	outputPosition(81, 10);
	std::cout << "Choose the type of event you want to add!";
	const std::vector<std::string> eventTypeOptions = {
		"Uprising",
		"War",
		"Movement",
		"Other"
	};

	int selectedOption = 1;
	char pressedKey = ' ';

	while (pressedKey != (int)ARROW_KEYS::KEY_ENTER)
	{
		for (int i = 0; i < eventTypeOptions.size(); i++)
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
			std::cout << eventTypeOptions[i] << std::endl << std::endl;
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
			if (selectedOption == eventTypeOptions.size() + 1)
			{
				selectedOption -= 1;
			}
			break;
		case (int)ARROW_KEYS::KEY_ENTER:
			switch (selectedOption)
			{
			case 1:
				addUprisingEvent(eventManager, approve);
				break;
			case 2:
				addWarEvent(eventManager, approve);
				break;
			case 3:
				addMovementEvent(eventManager, approve);
				break;
			case 4:
				addOtherEvent(eventManager, approve);
				break;
			}
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

void deleteEvent(EventManager* eventManager)
{
	std::vector<Event> approveEvents = eventManager->getAllEvents(1);
	std::vector<Event> unApproveEvents = eventManager->getAllEvents(0);

	approveEvents.insert(
		approveEvents.end(),
		unApproveEvents.begin(),
		unApproveEvents.end()
	);

	if (approveEvents.empty())
	{
		outputPosition(81, 10);
		std::cout << "There are no storylines to display";
		outputPosition(81, 11);
		std::cout << "Press any key to go back!";
		(void)_getch();
		clearConsole();
		printClosedBook();
		printBookDecorations();
		printSnakeSword();
		printTeamLogo();
		return;
	}

	printFullyOpenedBook();
	outputPosition(81, 10);
	std::cout << "Choose event that you want to remove:";

	int selectedOption = 1;
	char pressedKey = ' ';

	while (pressedKey != (int)ARROW_KEYS::KEY_ENTER)
	{
		for (int i = 0; i < approveEvents.size(); i++)
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
			std::cout << approveEvents[i].title;
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
			if (selectedOption == approveEvents.size() + 1)
			{
				selectedOption -= 1;
			}
			break;
		case (int)ARROW_KEYS::KEY_ENTER:
			clearConsole();
			printFullyOpenedBook();
			if (!eventManager->removeEvent(
				&eventManager->eventList, approveEvents[__int64(selectedOption) - 1].title)
				)
			{
				outputPosition(81, 20);
				std::cout << "The event wasn't found";
			}

			return;
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

void displayEvent(const Event& e, bool approve, EventManager* eventManager)
{
	DateManager  dateManager;
	printFullyOpenedBook();
	outputPosition(81, 10);
	std::cout << "Press ESC if you want to go back!";
	switch (e.type)
	{
	case TypeOfEvent::UPRISING:
		printFullyOpenedBook();
		outputPosition(81, 12);
		std::cout << "Title: " << e.title;

		struct tm timeinfo;
		localtime_s(&timeinfo, &e.timeOfCreation);

		outputPosition(81, 14);
		std::cout << "Time of creation: " << std::put_time(&timeinfo, "%x");
		outputPosition(81, 16);
		std::cout << "Type: Uprising";
		outputPosition(81, 18);
		std::cout << "Epoch: " << e.epochs[0];
		if (e.period.size() == 2)
		{
			outputPosition(81, 21);
			std::cout << "Start date: " << std::put_time(&e.period[0], "%x") << std::endl;
			outputPosition(81, 23);
			std::cout << "End date: " << std::put_time(&e.period[1], "%x") << std::endl;
			outputPosition(81, 25);
			std::cout << "Duration in days: " << dateManager.getDifference(
				e.period[0], e.period[1]
			) << std::endl;
			outputPosition(81, 27);
			std::cout << "Success: ";
			switch (e.isItSuccessful)
			{
			case 0: std::cout << "No"; break;
			case 1: std::cout << "Yes"; break;
			}
			outputPosition(81, 29);
			std::cout << "Number of rebellions: " << e.numberOfRebelions;
			outputPosition(81, 31);
			std::cout << "Additional notes: ";
			outputPosition(81, 32);
			std::cout << e.additionalNotes;
		}
		else
		{
			outputPosition(81, 21);
			std::cout << "Date: " << std::put_time(&e.period[0], "%x") << std::endl;
			outputPosition(81, 23);
			std::cout << "Success: ";
			switch (e.isItSuccessful)
			{
			case 0: std::cout << "No"; break;
			case 1: std::cout << "Yes"; break;
			}
			outputPosition(81, 25);
			std::cout << "Number of rebellions: " << e.numberOfRebelions;
			outputPosition(81, 27);
			std::cout << "Additional notes: ";
			outputPosition(81, 28);
			std::cout << e.additionalNotes;
		}

		break;
	case TypeOfEvent::WAR:
		printFullyOpenedBook();
		outputPosition(81, 12);
		std::cout << "Title: " << e.title;
		localtime_s(&timeinfo, &e.timeOfCreation);

		outputPosition(81, 14);
		std::cout << "Time of creation: " << std::put_time(&timeinfo, "%x");
		outputPosition(81, 16);
		std::cout << "Type: War";
		outputPosition(81, 18);
		std::cout << "Epoch: " << e.epochs[0];
		if (e.period.size() == 2)
		{
			outputPosition(81, 21);
			std::cout << "Start date: " << std::put_time(&e.period[0], "%x") << std::endl;
			outputPosition(81, 23);
			std::cout << "End date: " << std::put_time(&e.period[1], "%x") << std::endl;
			outputPosition(81, 25);
			std::cout << "Duration in days: " << dateManager.getDifference(
				e.period[0], e.period[1]
			) << std::endl;
			outputPosition(81, 27);
			std::cout << "Participting countries: " << separate(e.participatingCountries);
			outputPosition(81, 29);
			std::cout << "Winner: " << e.winner;
			outputPosition(81, 31);
			std::cout << "Reason " << e.reason;
			outputPosition(81, 33);
			std::cout << "Rulers: " << separate(e.rulers);
			outputPosition(81, 35);
			std::cout << "Additional notes: ";
			outputPosition(81, 36);
			std::cout << e.additionalNotes;
		}
		else
		{
			outputPosition(81, 21);
			std::cout << "Date: " << std::put_time(&e.period[0], "%x") << std::endl;
			outputPosition(81, 23);
			std::cout << "Participting countries: " << separate(e.participatingCountries);
			outputPosition(81, 25);
			std::cout << "Winner:  " << e.winner;
			outputPosition(81, 27);
			std::cout << "Reason " << e.reason;
			outputPosition(81, 29);
			std::cout << "Rulers: " << separate(e.rulers);
			outputPosition(81, 31);
			std::cout << "Additional notes: ";
			outputPosition(81, 32);
			std::cout << e.additionalNotes;
		}

		break;
	case TypeOfEvent::MOVEMENT:
		printFullyOpenedBook();
		outputPosition(81, 12);
		std::cout << "Title: " << e.title;
		localtime_s(&timeinfo, &e.timeOfCreation);

		outputPosition(81, 14);
		std::cout << "Time of creation: " << std::put_time(&timeinfo, "%x");
		outputPosition(81, 16);
		std::cout << "Type: Movement";
		outputPosition(81, 18);
		std::cout << "Epoch: " << e.epochs[0];
		if (e.period.size() == 2)
		{
			outputPosition(81, 21);
			std::cout << "Start date: " << std::put_time(&e.period[0], "%x") << std::endl;
			outputPosition(81, 23);
			std::cout << "End date: " << std::put_time(&e.period[1], "%x") << std::endl;
			outputPosition(81, 25);
			std::cout << "Duration in days: " << dateManager.getDifference(
				e.period[0], e.period[1]
			) << std::endl;
			outputPosition(81, 27);
			std::cout << "How it started: " << e.howItStarted;
			outputPosition(81, 29);
			std::cout << "Ideas " << e.ideas;
			outputPosition(81, 31);
			std::cout << "Aims " << e.aims;
			outputPosition(81, 33);
			std::cout << "Representatives: " << separate(e.representatives);
			outputPosition(81, 35);
			std::cout << "Additional notes: ";
			outputPosition(81, 36);
			std::cout << e.additionalNotes;
		}
		else
		{
			outputPosition(81, 21);
			std::cout << "Date: " << std::put_time(&e.period[0], "%x") << std::endl;
			outputPosition(81, 23);
			std::cout << "How it started: " << e.howItStarted;
			outputPosition(81, 25);
			std::cout << "Ideas " << e.ideas;
			outputPosition(81, 27);
			std::cout << "Aims " << e.aims;
			outputPosition(81, 29);
			std::cout << "Representatives: " << separate(e.representatives);
			outputPosition(81, 31);
			std::cout << "Additional notes: ";
			outputPosition(81, 32);
			std::cout << e.additionalNotes;
		}
	case TypeOfEvent::OTHER:
		printFullyOpenedBook();
		outputPosition(81, 12);
		std::cout << "Title: " << e.title;
		localtime_s(&timeinfo, &e.timeOfCreation);

		outputPosition(81, 14);
		std::cout << "Time of creation: " << std::put_time(&timeinfo, "%x");
		outputPosition(81, 16);
		std::cout << "Type: Other";
		outputPosition(81, 18);
		std::cout << "Epoch: ";
		for (size_t i = 0; i < e.epochs[0].size(); i++)
		{
			if (i != 0)
			{
				if (e.epochs[0][i - 1] == '>')
				{
					outputPosition(81, 19);
				}
			}

			std::cout << e.epochs[0][i];
		}

		if (e.period.size() == 2)
		{
			outputPosition(81, 21);
			std::cout << "Start date: " << std::put_time(&e.period[0], "%x") << std::endl;
			outputPosition(81, 23);
			std::cout << "End date: " << std::put_time(&e.period[1], "%x") << std::endl;
			outputPosition(81, 25);
			std::cout << "Duration in days: " << dateManager.getDifference(
				e.period[0], e.period[1]
			) << std::endl;
			outputPosition(81, 27);
			std::cout << "Additional notes: ";
			outputPosition(81, 28);
			std::cout << e.additionalNotes;
		}
		else
		{
			outputPosition(81, 21);
			std::cout << "Date: " << std::put_time(&e.period[0], "%x") << std::endl;
			outputPosition(81, 23);
			std::cout << "Additional notes: ";
			outputPosition(81, 24);
			std::cout << e.additionalNotes;
		}

		break;
	}
	if (approve)
	{
		short xCord;

		switch (e.type)
		{
		case TypeOfEvent::UPRISING:
			xCord = 26;
			break;
		case TypeOfEvent::WAR:
			xCord = 30;
			break;
		case TypeOfEvent::MOVEMENT:
			xCord = 30;
			break;
		case TypeOfEvent::OTHER:
			xCord = 22;
			break;
		default:
			xCord = 30;
			break;
		}

		std::vector<std::string> options = {
			"Approve",
			"Disapprove (deleate)"
		};

		char pressedKey = ' ';
		int selectedOption = 1;

		outputPosition(81, xCord);
		std::cout << "Choose option:";

		while (pressedKey != (int)ARROW_KEYS::KEY_ENTER)
		{
			for (int i = 0; i < options.size(); i++)
			{
				if (i + 1 == selectedOption)
				{
					outputPosition(81, xCord + i + 1);
					std::cout << "-> ";
				}
				else
				{
					outputPosition(81, xCord + i + 1);
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
				switch (selectedOption)
				{
				case 1:
					eventManager->approveEvent(e.title);
					break;
				case 2:
					eventManager->removeEvent(&eventManager->eventList, e.title);
					break;
				}
			}
		}
	}
	else
	{
		(void)_getch();
		clearConsole();
		printClosedBook();
		printBookDecorations();
		printSnakeSword();
		printTeamLogo();
	}
}

void printEventInfo(const std::vector<Event> events, int output)
{
	int selectedOption = 1;
	char pressedKey = ' ';

	while (pressedKey != (int)ARROW_KEYS::KEY_ENTER)
	{
		for (int i = 0; i < events.size(); i++)
		{
			if (i + 1 == selectedOption)
			{
				outputPosition(81, 10 + i * 2);
				std::cout << "-> ";
			}
			else
			{
				outputPosition(81, 10 + i * 2);
				std::cout << "   ";
			}
			if (output == 1) {
				for (int j = 0; j < events[i].period.size(); j++)
				{
					outputPosition(84, 10 + i * 2);
					std::cout << events[i].title << " - " << std::put_time(&events[i].period[j], "%x") << std::endl;
				}
			}
			else if (output == 2)
			{
				for (int i = 0; i < events.size(); i++)
				{
					for (int j = 0; j < events[i].period.size(); j++)
					{
						outputPosition(84, 10 + i * 2);
						std::cout << std::put_time(&events[i].period[j], "%x") << " - "
							<< events[i].title;
					}
				}
			}
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
			if (selectedOption == events.size() + 1)
			{
				selectedOption -= 1;
			}
			break;
		case (int)ARROW_KEYS::KEY_ENTER:
			displayEvent(events[__int64(selectedOption) - 1]);
		}
	}
}

void displayAllEvents(EventManager* eventManager, int sorting, int& type, bool getAllEvents)
{
	std::vector<Event> allEvents = eventManager->getAllEvents(true);
	if (getAllEvents)
	{
		std::vector<Event> events = eventManager->getAllEvents(false);
		allEvents.insert(allEvents.end(), events.begin(), events.end());
	}

	if (allEvents.empty())
	{
		outputPosition(81, 10);
		std::cout << "There are no events to display";
		outputPosition(81, 11);
		std::cout << "Press any key to go back!";
		(void)_getch();
		clearConsole();
		printClosedBook();
		printBookDecorations();
		printSnakeSword();
		printTeamLogo();
		return;
	}
	int output = 1;
	if (sorting == 1 && type == 1)
	{
		allEvents = eventManager->sortAndGetAllEventsByTitle(allEvents);
	}
	else if (sorting == 1 && type == 2)
	{
		allEvents = eventManager->sortAndGetAllEventsByDate(allEvents);
		output++;
	}
	else if (sorting == 1 && type == 3)
	{
		allEvents = eventManager->sortAndGetAllEventsByTimeOfCreation(allEvents);
	}
	else if (sorting == 2 && type == 1)
	{
		allEvents = eventManager->sortAndGetAllEventsByTitle(allEvents);
		reverse(allEvents.begin(), allEvents.end());
	}
	else if (sorting == 2 && type == 2)
	{
		allEvents = eventManager->sortAndGetAllEventsByDate(allEvents);
		reverse(allEvents.begin(), allEvents.end());
		output++;
	}
	else if (sorting == 2 && type == 3)
	{
		allEvents = eventManager->sortAndGetAllEventsByTimeOfCreation(allEvents);
		reverse(allEvents.begin(), allEvents.end());
	}
	printEventInfo(allEvents, output);
}

void chooseSorting(EventManager* eventManager, int type, bool getAllEvents)
{
	printFullyOpenedBook();
	outputPosition(81, 10);
	std::cout << "How do you want to sort the events?" << std::endl;
	int selectedOption = 1;
	char pressedKey = ' ';
	const std::vector<std::string> y�arSortingOptions =
	{
		"Ascending",
		"Descending",
	};

	const std::vector<std::string> titleSortingOptions =
	{
		"A -> Z",
		"Z -> A",
	};

	const std::vector<std::string> timeAddedSortingOptions =
	{
		"Newer -> Older",
		"Older -> Newer",
	};
	while (pressedKey != (int)ARROW_KEYS::KEY_ENTER)
	{
		if (type == 1)
		{
			for (int i = 0; i < titleSortingOptions.size(); i++)
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
				std::cout << titleSortingOptions[i] << std::endl << std::endl;
			}
		}
		else if (type == 2)
		{
			for (int i = 0; i < y�arSortingOptions.size(); i++)
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
				std::cout << y�arSortingOptions[i] << std::endl << std::endl;
			}
		}
		else if (type == 3)
		{
			for (int i = 0; i < timeAddedSortingOptions.size(); i++)
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
				std::cout << timeAddedSortingOptions[i] << std::endl << std::endl;
			}
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
			if (selectedOption == y�arSortingOptions.size() + 1)
			{
				selectedOption -= 1;
			}
			break;
		case (int)ARROW_KEYS::KEY_ENTER:
			switch (selectedOption)
			{
			case 1:
				printFullyOpenedBook();
				displayAllEvents(eventManager, 1, type, getAllEvents);
				break;
			case 2:
				printFullyOpenedBook();
				displayAllEvents(eventManager, 2, type, getAllEvents);
				break;
			}
		}
	}
}

void printBy(EventManager* eventManager, bool getAllEvents)
{
	outputPosition(81, 10);
	std::cout << "How do you want to sort the events?" << std::endl;
	int selectedOption = 1;
	char pressedKey = ' ';
	const std::vector<std::string> printByOptions =
	{
		"By title",
		"By year, month and day",
		"By time added"
	};
	while (pressedKey != (int)ARROW_KEYS::KEY_ENTER)
	{
		for (int i = 0; i < printByOptions.size(); i++)
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
			std::cout << printByOptions[i] << std::endl << std::endl;
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
			if (selectedOption == printByOptions.size() + 1)
			{
				selectedOption -= 1;
			}
			break;
		case (int)ARROW_KEYS::KEY_ENTER:
			switch (selectedOption)
			{
			case 1:
				printFullyOpenedBook();
				chooseSorting(eventManager, 1, getAllEvents);
				break;
			case 2:
				printFullyOpenedBook();
				chooseSorting(eventManager, 2, getAllEvents);
				break;
			case 3:
				printFullyOpenedBook();
				chooseSorting(eventManager, 3, getAllEvents);
				break;
			}
		case (int)ARROW_KEYS::KEY_ESC:
			return;
		}
	}
}

void printAsMap(EventManager* eventManager, bool getAllEvents)
{
	std::vector<Event> allEvents = eventManager->getAllEvents(true);

	if (getAllEvents)
	{
		std::vector<Event> unApproveEvents = eventManager->getAllEvents(false);
		allEvents.insert(allEvents.end(), unApproveEvents.begin(), unApproveEvents.end());
	}

	if (allEvents.empty())
	{
		outputPosition(81, 10);
		std::cout << "There are no events to display";
		outputPosition(81, 12);
		std::cout << "Press Enter to go back!";
		(void)_getch();
		return;
	}

	int selectedOption = 1;
	char pressedKey = ' ';

	while (pressedKey != (int)ARROW_KEYS::KEY_ENTER)
	{
		for (int i = 0; i < allEvents.size(); i++)
		{
			if (i + 1 == selectedOption)
			{
				outputPosition(81, 10 + i * 2);
				std::cout << "-> ";
			}
			else
			{
				outputPosition(81, 10 + i * 2);
				std::cout << "   ";
			}

			for (int j = 0; j < allEvents[i].period.size(); j++)
			{
				outputPosition(84, 10 + i * 2);
				std::cout << allEvents[i].title << " - " 
					<< std::put_time(&allEvents[i].period[j], "%x") << std::endl;
			}

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
			if (selectedOption == allEvents.size() + 1)
			{
				selectedOption -= 1;
			}
			break;
		case (int)ARROW_KEYS::KEY_ENTER:
			printMapPopUp();
			printBulgarianMap();
			outputPosition(
				(allEvents[__int64(selectedOption) - 1].coordinates.X), 
				(allEvents[__int64(selectedOption) - 1].coordinates.Y)
			);
			std::cout << char(254);
			if (_getch())
			{
				return;
				clearConsole();
				printClosedBook();
				printBookDecorations();
				printSnakeSword();
				printTeamLogo();
			}
		}
	}
}

void editEvent(EventManager* eventManager)
{
	std::vector<Event> approveEvents = eventManager->getAllEvents(1);
	std::vector<Event> unApproveEvents = eventManager->getAllEvents(0);

	approveEvents.insert(
		approveEvents.end(), 
		unApproveEvents.begin(),
		unApproveEvents.end()
	);

	if (approveEvents.empty())
	{
		outputPosition(81, 10);
		std::cout << "There are no events to display";
		outputPosition(81, 12);
		std::cout << "Press Enter to go back!";
		(void)_getch();
		return;
	}

	int selectedOption = 1;
	char pressedKey = ' ';
	outputPosition(81, 10);
	std::cout << "Choose the event you want to edit!";
	while (pressedKey != (int)ARROW_KEYS::KEY_ENTER)
	{
		for (int i = 0; i < approveEvents.size(); i++)
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

			for (int j = 0; j < approveEvents[i].period.size(); j++)
			{
				outputPosition(84, 12 + i * 2);
				std::cout << approveEvents[i].title << " - " 
					<< std::put_time(&approveEvents[i].period[j], "%x") << std::endl;
			}

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
			if (selectedOption == approveEvents.size() + 1)
			{
				selectedOption -= 1;
			}
			break;
		case (int)ARROW_KEYS::KEY_ENTER:
			std::vector<std::string> uprisingOptions
			{
				"Title",
				"Date",
				"Coordinates",
				"Organizers",
				"Number of rebellions",
				"Success",

			};

			std::vector<std::string> warOptions
			{
				"Title",
				"Date",
				"Coordinates",
				"Participating countries",
				"Winner",
				"Reason",
				"Rulers",

			};

			std::vector<std::string> movementOptions
			{
				"Title",
				"Date",
				"Coordinates",
				"How it started",
				"Ideas",
				"Aims",
				"Representatives",

			};

			std::vector<std::string> otherOptions
			{
				"Title",
				"Date",
				"Coordinates",
			};
			if ((approveEvents[__int64(selectedOption) - 1].type == TypeOfEvent::UPRISING))
			{
				printFullyOpenedBook();
				outputPosition(81, 10);
				std::cout << "What do you want to edit?";

				std::string title;
				std::string period;
				std::string organizers;
				bool isItSuccessful = true;
				int rebelions;
				const std::vector<std::string> successOfEventOptions = {
					"Successful",
					"Unsuccessful"
				};
				short x = 56;
				short y = 20;
				char key;


				int selectedOption1 = 1;
				char pressedKey1 = ' ';

				while (pressedKey1 != (int)ARROW_KEYS::KEY_ENTER)
				{
					for (int i = 0; i < uprisingOptions.size(); i++)
					{
						if (i + 1 == selectedOption1)
						{
							outputPosition(81, 12 + i * 2);
							std::cout << "-> ";
						}
						else
						{
							outputPosition(81, 12 + i * 2);
							std::cout << "   ";
						}

						outputPosition(84, 12 + i * 2);
						std::cout << uprisingOptions[i];

					}

					pressedKey1 = _getch();
					switch (pressedKey1)
					{
					case (int)ARROW_KEYS::KEY_UP:
						selectedOption1--;
						if (selectedOption1 == 0)
						{
							selectedOption1 += 1;
						}
						break;

					case (int)ARROW_KEYS::KEY_DOWN:
						selectedOption1++;
						if (selectedOption1 == uprisingOptions.size() + 1)
						{
							selectedOption1 -= 1;
						}
						break;
					case (int)ARROW_KEYS::KEY_ENTER:
						switch (selectedOption1)
						{
						case 1:
							printFullyOpenedBook();
							outputPosition(81, 10);
							std::cout << "Enter the title of the event: " << std::endl;
							outputPosition(81, 12);
							getline(std::cin, title);

							while (title.empty())
							{
								outputPosition(81, 12);
								std::cout << "Title can not be empty, please enter again: ";
								outputPosition(81, 14);
								getline(std::cin, title);
							}
							outputPosition(81, 14);
							std::cout << "Changes saved successfully!";

							eventManager->setSingleValueField(
								(eventManager->getEventWithName(
									approveEvents[__int64(selectedOption) - 1].title
								))->title, title);
							break;
						case 2:
							printFullyOpenedBook();

							outputPosition(81, 10);
							std::cout << "Enter the starting and ending year and date";
							outputPosition(81, 12);
							std::cout << "Example - (20 apr 1876, 15 may 1876)";
							outputPosition(81, 14);
							getline(std::cin, period);
							outputPosition(81, 16);
							std::cout << "Changes saved successfully!";
							while (!checkDatesValidation(period))
							{
								outputPosition(81, 14);
								std::cout << "The data you've entered is incorrect!";
								outputPosition(81, 16);
								std::cout << "Please enter a date/s - ex(24 apr 809, 27 apr 810)";
								outputPosition(81, 18);
								getline(std::cin, period);
								outputPosition(81, 20);
								std::cout << "Changes saved successfully!";
							}
							DateManager dateManager;
							eventManager->setMultiValueField((
								eventManager->getEventWithName(
									approveEvents[__int64(selectedOption) - 1].title
								))->period, 
								dateManager.converVectorOfStringsToVectorOfDate(
									separateDates(period)
								));
							break;
						case 3:
							printFullyOpenedBook();
							printMapPopUp();
							printBulgarianMap();
							outputPosition(x, y);
							std::cout << char(254);
							while ((key = _getch()) != (char)ARROW_KEYS::KEY_ENTER)
							{
								switch (key)
								{
								case (char)ARROW_KEYS::KEY_UP:
									outputPosition(x, y);
									std::cout << " ";
									y -= 1;
									outputPosition(x, y);
									std::cout << char(254);
									break;
								case (char)ARROW_KEYS::KEY_DOWN:
									outputPosition(x, y);
									std::cout << " ";
									y += 1;
									outputPosition(x, y);
									std::cout << char(254);
									break;
								case (char)ARROW_KEYS::KEY_LEFT:
									outputPosition(x, y);
									std::cout << " ";
									x += 1;
									outputPosition(x, y);
									std::cout << char(254);
									break;
								case (char)ARROW_KEYS::KEY_RIGHT:
									outputPosition(x, y);
									std::cout << " ";
									x -= 1;
									outputPosition(x, y);
									std::cout << char(254);
									break;
								case (char)ARROW_KEYS::KEY_ENTER:
									printFullyOpenedBook();
									break;
								}
							}
							eventManager->setSingleValueField(
								(eventManager->getEventWithName(
									approveEvents[__int64(selectedOption) - 1].title)
									)->coordinates.X, (short)x);
							eventManager->setSingleValueField(
								(eventManager->getEventWithName(
									approveEvents[__int64(selectedOption) - 1].title)
									)->coordinates.Y, (short)y);
							break;
						case 4:
							printFullyOpenedBook();
							outputPosition(81, 10);
							std::cout << "Enter the organizers of the event: " << std::endl;
							outputPosition(81, 12);
							getline(std::cin, organizers);

							while (organizers.empty())
							{
								outputPosition(81, 12);
								std::cout << "Organizers can not be empty, please enter again: ";
								outputPosition(81, 14);
								getline(std::cin, organizers);
							}

							outputPosition(81, 14);
							std::cout << "Changes saved successfully!";
							eventManager->setMultiValueField(
								(eventManager->getEventWithName(
									approveEvents[__int64(selectedOption) - 1].title)
									)->organizers, { organizers });
							break;
						case 5:
							printFullyOpenedBook();
							outputPosition(81, 10);
							std::cout << "Enter the numbers of rebellions: " << std::endl;
							outputPosition(81, 12);
							std::cin >> rebelions;

							outputPosition(81, 14);
							std::cout << "Changes saved successfully!";
							eventManager->setSingleValueField(
								(eventManager->getEventWithName(
									approveEvents[__int64(selectedOption) - 1].title)
									)->numberOfRebelions, rebelions);
							break;
						case 6:
							printFullyOpenedBook();
							outputPosition(81, 10);
							std::cout << "Is the event successful?";

							int selectedOption = 1;
							char pressedKey = ' ';

							while (pressedKey != (int)ARROW_KEYS::KEY_ENTER)
							{
								for (int i = 0; i < successOfEventOptions.size(); i++)
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
									std::cout << successOfEventOptions[i] 
										<< std::endl << std::endl;
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
									if (selectedOption == successOfEventOptions.size() + 1)
									{
										selectedOption -= 1;
									}
									break;
								case (int)ARROW_KEYS::KEY_ENTER:
									switch (selectedOption)
									{
									case 1:
										isItSuccessful = true;

										break;
									case 2:
										isItSuccessful = false;
										break;
									}
								}
							}
							eventManager->setSingleValueField(
								(eventManager->getEventWithName(
									approveEvents[__int64(selectedOption) - 1].title)
									)->isItSuccessful, isItSuccessful);
							break;
						}
					}
				}
			}
			else if ((approveEvents[__int64(selectedOption) - 1].type == TypeOfEvent::WAR))
			{
				printFullyOpenedBook();
				outputPosition(81, 10);
				std::cout << "What do you want to edit?";

				std::string title;
				std::string period;
				std::string participatingCountries;
				std::string winner;
				std::string reasons;
				std::string rulers;
				short x = 56;
				short y = 20;
				char key;

				int selectedOption1 = 1;
				char pressedKey1 = ' ';

				while (pressedKey1 != (int)ARROW_KEYS::KEY_ENTER)
				{
					for (int i = 0; i < warOptions.size(); i++)
					{
						if (i + 1 == selectedOption1)
						{
							outputPosition(81, 12 + i * 2);
							std::cout << "-> ";
						}
						else
						{
							outputPosition(81, 12 + i * 2);
							std::cout << "   ";
						}
						outputPosition(84, 12 + i * 2);
						std::cout << warOptions[i];

					}
					pressedKey1 = _getch();
					switch (pressedKey1)
					{
					case (int)ARROW_KEYS::KEY_UP:
						selectedOption1--;
						if (selectedOption1 == 0)
						{
							selectedOption1 += 1;
						}
						break;

					case (int)ARROW_KEYS::KEY_DOWN:
						selectedOption1++;
						if (selectedOption1 == approveEvents.size() + 1)
						{
							selectedOption1 -= 1;
						}
						break;
					case (int)ARROW_KEYS::KEY_ENTER:
						switch (selectedOption1) {
						case 1:
							printFullyOpenedBook();
							outputPosition(81, 10);
							std::cout << "Enter the title of the event: " << std::endl;
							outputPosition(81, 12);
							getline(std::cin, title);

							while (title.empty())
							{
								outputPosition(81, 12);
								std::cout << "Title can not be empty, please enter again: ";
								outputPosition(81, 14);
								getline(std::cin, title);
							}
							outputPosition(81, 14);
							std::cout << "Changes saved successfully!";

							eventManager->setSingleValueField(
								(eventManager->getEventWithName(
									approveEvents[__int64(selectedOption) - 1].title)
									)->title, title);
							break;
						case 2:
							printFullyOpenedBook();

							outputPosition(81, 10);
							std::cout << "Enter the starting and ending year and date";
							outputPosition(81, 12);
							std::cout << "Example - (20 apr 1876, 15 may 1876)";
							outputPosition(81, 14);
							getline(std::cin, period);
							outputPosition(81, 16);
							std::cout << "Changes saved successfully!";
							while (!checkDatesValidation(period))
							{
								outputPosition(81, 14);
								std::cout << "The data you've entered is incorrect!";
								outputPosition(81, 16);
								std::cout << "Please enter a date/s - ex(24 apr 809, 27 apr 810)";
								outputPosition(81, 18);
								getline(std::cin, period);
								outputPosition(81, 20);
								std::cout << "Changes saved successfully!";
							}
							DateManager dateManager;
							eventManager->setMultiValueField(
								(eventManager->getEventWithName(approveEvents[__int64(
									selectedOption) - 1].title)
									)->period, 
								dateManager.converVectorOfStringsToVectorOfDate(
									separateDates(period))
							);
							break;
						case 3:
							printFullyOpenedBook();
							printMapPopUp();
							printBulgarianMap();
							outputPosition(x, y);
							std::cout << char(254);
							while ((key = _getch()) != (char)ARROW_KEYS::KEY_ENTER)
							{
								switch (key)
								{
								case (char)ARROW_KEYS::KEY_UP:
									outputPosition(x, y);
									std::cout << " ";
									y -= 1;
									outputPosition(x, y);
									std::cout << char(254);
									break;
								case (char)ARROW_KEYS::KEY_DOWN:
									outputPosition(x, y);
									std::cout << " ";
									y += 1;
									outputPosition(x, y);
									std::cout << char(254);
									break;
								case (char)ARROW_KEYS::KEY_LEFT:
									outputPosition(x, y);
									std::cout << " ";
									x += 1;
									outputPosition(x, y);
									std::cout << char(254);
									break;
								case (char)ARROW_KEYS::KEY_RIGHT:
									outputPosition(x, y);
									std::cout << " ";
									x -= 1;
									outputPosition(x, y);
									std::cout << char(254);
									break;
								case (char)ARROW_KEYS::KEY_ENTER:
									printFullyOpenedBook();
									break;
								}
							}
							eventManager->setSingleValueField(
								(eventManager->getEventWithName(
									approveEvents[__int64(selectedOption) - 1].title)
									)->coordinates.X, (short)x);
							eventManager->setSingleValueField(
								(eventManager->getEventWithName(
									approveEvents[__int64(selectedOption) - 1].title)
									)->coordinates.Y, (short)y);
							break;
						case 4:
							printFullyOpenedBook();
							outputPosition(81, 10);
							std::cout << "Enter the participating countries of the event: " << std::endl;
							outputPosition(81, 12);
							getline(std::cin, participatingCountries);

							while (participatingCountries.empty())
							{
								outputPosition(81, 12);
								std::cout << "Participating countries can not be empty, please enter again: ";
								outputPosition(81, 14);
								getline(std::cin, participatingCountries);
							}

							outputPosition(81, 14);
							std::cout << "Changes saved successfully!";
							eventManager->setMultiValueField((
								eventManager->getEventWithName(
									approveEvents[__int64(selectedOption) - 1].title
								))->participatingCountries, 
								{ participatingCountries });
							break;
						case 5:
							printFullyOpenedBook();
							outputPosition(81, 10);
							std::cout << "Enter the winner of the event: " 
								<< std::endl;
							outputPosition(81, 12);
							getline(std::cin, winner);

							while (winner.empty())
							{
								outputPosition(81, 12);
								std::cout << "Winner can not be empty, please enter again: ";
								outputPosition(81, 14);
								getline(std::cin, winner);
							}
							outputPosition(81, 14);
							std::cout << "Changes saved successfully!";

							eventManager->setSingleValueField((
								eventManager->getEventWithName(
									approveEvents[__int64(selectedOption) - 1].title
								))->winner, winner);
							break;
						case 6:
							printFullyOpenedBook();
							outputPosition(81, 10);
							std::cout << "Enter the reasons of the event: " <<
								std::endl;
							outputPosition(81, 12);
							getline(std::cin, reasons);

							while (reasons.empty())
							{
								outputPosition(81, 12);
								std::cout << "Reasons can not be empty, please enter again: ";
								outputPosition(81, 14);
								getline(std::cin, reasons);
							}
							outputPosition(81, 14);
							std::cout << "Changes saved successfully!";

							eventManager->setSingleValueField((
								eventManager->getEventWithName(
									approveEvents[__int64(selectedOption) - 1].title
								))->reason, reasons);
							break;
						case 7:
							printFullyOpenedBook();
							outputPosition(81, 10);
							std::cout << "Enter the rulers of the event: " 
								<< std::endl;
							outputPosition(81, 12);
							getline(std::cin, rulers);

							while (rulers.empty())
							{
								outputPosition(81, 12);
								std::cout << "Rulers can not be empty, please enter again: ";
								outputPosition(81, 14);
								getline(std::cin, rulers);
							}
							outputPosition(81, 14);
							std::cout << "Changes saved successfully!";

							eventManager->setSingleValueField((
								eventManager->getEventWithName(
									approveEvents[__int64(selectedOption) - 1].title
								))->rulers, { rulers });
							break;
						}
					}
				}
			}
			else if ((
			approveEvents[__int64(selectedOption) - 1].type == TypeOfEvent::MOVEMENT))
			{
				printFullyOpenedBook();
				outputPosition(81, 10);
				std::cout << "What do you want to edit?";

				std::string title;
				std::string period;
				std::string howItStarted;
				std::string ideas;
				std::string aims;
				std::string representatives;
				short x = 56;
				short y = 20;
				char key;

				int selectedOption1 = 1;
				char pressedKey1 = ' ';


				while (pressedKey1 != (int)ARROW_KEYS::KEY_ENTER)
				{
					for (int i = 0; i < movementOptions.size(); i++)
					{
						if (i + 1 == selectedOption1)
						{
							outputPosition(81, 12 + i * 2);
							std::cout << "-> ";
						}
						else
						{
							outputPosition(81, 12 + i * 2);
							std::cout << "   ";
						}
						outputPosition(84, 12 + i * 2);
						std::cout << movementOptions[i];

					}
					pressedKey1 = _getch();
					switch (pressedKey1)
					{
					case (int)ARROW_KEYS::KEY_UP:
						selectedOption1--;
						if (selectedOption1 == 0)
						{
							selectedOption1 += 1;
						}
						break;

					case (int)ARROW_KEYS::KEY_DOWN:
						selectedOption1++;
						if (selectedOption1 == approveEvents.size() + 1)
						{
							selectedOption1 -= 1;
						}
						break;
					case (int)ARROW_KEYS::KEY_ENTER:
						switch (selectedOption1)
						{
						case 1:
							printFullyOpenedBook();
							outputPosition(81, 10);
							std::cout << "Enter the title of the event: " 
								<< std::endl;
							outputPosition(81, 12);
							getline(std::cin, title);

							while (title.empty())
							{
								outputPosition(81, 12);
								std::cout << "Title can not be empty, please enter again: ";
								outputPosition(81, 14);
								getline(std::cin, title);
							}
							outputPosition(81, 14);
							std::cout << "Changes saved successfully!";

							eventManager->setSingleValueField(
								(eventManager->getEventWithName(
									approveEvents[__int64(selectedOption) - 1].title
								))->title, title);
							break;
						case 2:
							printFullyOpenedBook();

							outputPosition(81, 10);
							std::cout << "Enter the starting and ending year and date";
							outputPosition(81, 12);
							std::cout << "Example - (20 apr 1876, 15 may 1876)";
							outputPosition(81, 14);
							getline(std::cin, period);
							outputPosition(81, 16);
							std::cout << "Changes saved successfully!";
							while (!checkDatesValidation(period))
							{
								outputPosition(81, 14);
								std::cout << "The data you've entered is incorrect!";
								outputPosition(81, 16);
								std::cout << "Please enter a date/s - ex(24 apr 809, 27 apr 810)";
								outputPosition(81, 18);
								getline(std::cin, period);
								outputPosition(81, 20);
								std::cout << "Changes saved successfully!";
							}
							DateManager dateManager;
							eventManager->setMultiValueField((
								eventManager->getEventWithName(
									approveEvents[__int64(selectedOption) - 1].title)
								)->period,
								dateManager.converVectorOfStringsToVectorOfDate(
									separateDates(period)
								)
							);
							break;
						case 3:
							printFullyOpenedBook();
							printMapPopUp();
							printBulgarianMap();
							outputPosition(x, y);
							std::cout << char(254);
							while ((key = _getch()) != (char)ARROW_KEYS::KEY_ENTER)
							{
								switch (key)
								{
								case (char)ARROW_KEYS::KEY_UP:
									outputPosition(x, y);
									std::cout << " ";
									y -= 1;
									outputPosition(x, y);
									std::cout << char(254);
									break;
								case (char)ARROW_KEYS::KEY_DOWN:
									outputPosition(x, y);
									std::cout << " ";
									y += 1;
									outputPosition(x, y);
									std::cout << char(254);
									break;
								case (char)ARROW_KEYS::KEY_LEFT:
									outputPosition(x, y);
									std::cout << " ";
									x += 1;
									outputPosition(x, y);
									std::cout << char(254);
									break;
								case (char)ARROW_KEYS::KEY_RIGHT:
									outputPosition(x, y);
									std::cout << " ";
									x -= 1;
									outputPosition(x, y);
									std::cout << char(254);
									break;
								case (char)ARROW_KEYS::KEY_ENTER:
									printFullyOpenedBook();
									break;
								}
							}
							eventManager->setSingleValueField((
								eventManager->getEventWithName(
									approveEvents[__int64(selectedOption) - 1].title)
								)->coordinates.X, (short)x);
							eventManager->setSingleValueField((
								eventManager->getEventWithName(
									approveEvents[__int64(selectedOption) - 1].title)
								)->coordinates.Y, (short)y);
							break;
						case 4:
							printFullyOpenedBook();
							outputPosition(81, 10);
							std::cout << "Enter the way the event started: " << std::endl;
							outputPosition(81, 12);
							getline(std::cin, howItStarted);

							while (howItStarted.empty())
							{
								outputPosition(81, 12);
								std::cout << "The way the event started can not be empty, please enter again: ";
								outputPosition(81, 14);
								getline(std::cin, howItStarted);
							}
							outputPosition(81, 14);
							std::cout << "Changes saved successfully!";

							eventManager->setSingleValueField((
								eventManager->getEventWithName(
									approveEvents[__int64(selectedOption) - 1].title)
								)->howItStarted, howItStarted);
							break;
						case 5:
							printFullyOpenedBook();
							outputPosition(81, 10);
							std::cout << "Enter the ideas of the event: " 
								<< std::endl;
							outputPosition(81, 12);
							getline(std::cin, ideas);

							while (ideas.empty())
							{
								outputPosition(81, 12);
								std::cout << "The ideas can not be empty, please enter again: ";
								outputPosition(81, 14);
								getline(std::cin, ideas);
							}
							outputPosition(81, 14);
							std::cout << "Changes saved successfully!";

							eventManager->setSingleValueField((
								eventManager->getEventWithName(
									approveEvents[__int64(selectedOption) - 1].title)
								)->ideas, ideas);
							break;
						case 6:
							printFullyOpenedBook();
							outputPosition(81, 10);
							std::cout << "Enter the aims of the event: "
								<< std::endl;
							outputPosition(81, 12);
							getline(std::cin, aims);

							while (aims.empty())
							{
								outputPosition(81, 12);
								std::cout << "The aims can not be empty, please enter again: ";
								outputPosition(81, 14);
								getline(std::cin, aims);
							}
							outputPosition(81, 14);
							std::cout << "Changes saved successfully!";

							eventManager->setSingleValueField((
								eventManager->getEventWithName(
									approveEvents[__int64(selectedOption) - 1].title)
								)->aims, aims);
							break;
						case 7:
							printFullyOpenedBook();
							outputPosition(81, 10);
							std::cout << "Enter the representatives of the event: "
								<< std::endl;
							outputPosition(81, 12);
							getline(std::cin, representatives);

							while (representatives.empty())
							{
								outputPosition(81, 12);
								std::cout << "The representatives can not be empty, please enter again: ";
								outputPosition(81, 14);
								getline(std::cin, representatives);
							}
							outputPosition(81, 14);
							std::cout << "Changes saved successfully!";

							eventManager->setSingleValueField((
								eventManager->getEventWithName(
									approveEvents[__int64(selectedOption) - 1].title)
								)->representatives, { representatives });
							break;
						}
					}
				}
			}
			else if ((
				approveEvents[__int64(selectedOption) - 1].type == TypeOfEvent::OTHER
			))
			{
				printFullyOpenedBook();
				outputPosition(81, 10);
				std::cout << "What do you want to edit?";

				std::string title;
				std::string period;
				short x = 56;
				short y = 20;
				char key;

				int selectedOption1 = 1;
				char pressedKey1 = ' ';


				while (pressedKey1 != (int)ARROW_KEYS::KEY_ENTER)
				{
					for (int i = 0; i < movementOptions.size(); i++)
					{
						if (i + 1 == selectedOption1)
						{
							outputPosition(81, 12 + i * 2);
							std::cout << "-> ";
						}
						else
						{
							outputPosition(81, 12 + i * 2);
							std::cout << "   ";
						}
						outputPosition(84, 12 + i * 2);
						std::cout << movementOptions[i];

					}
					pressedKey1 = _getch();
					switch (pressedKey1)
					{
					case (int)ARROW_KEYS::KEY_UP:
						selectedOption1--;
						if (selectedOption1 == 0)
						{
							selectedOption1 += 1;
						}
						break;

					case (int)ARROW_KEYS::KEY_DOWN:
						selectedOption1++;
						if (selectedOption1 == approveEvents.size() + 1)
						{
							selectedOption1 -= 1;
						}
						break;
					case (int)ARROW_KEYS::KEY_ENTER:
						switch (selectedOption1)
						{


						case 1:
							printFullyOpenedBook();
							outputPosition(81, 10);
							std::cout << "Enter the title of the event: " 
								<< std::endl;
							outputPosition(81, 12);
							getline(std::cin, title);

							while (title.empty())
							{
								outputPosition(81, 12);
								std::cout << "Title can not be empty, please enter again: ";
								outputPosition(81, 14);
								getline(std::cin, title);
							}
							outputPosition(81, 14);
							std::cout << "Changes saved successfully!";

							eventManager->setSingleValueField((
								eventManager->getEventWithName(
									approveEvents[__int64(selectedOption) - 1].title)
								)->title, title);
							break;
						case 2:
							printFullyOpenedBook();

							outputPosition(81, 10);
							std::cout << "Enter the starting and ending year and date";
							outputPosition(81, 12);
							std::cout << "Example - (20 apr 1876, 15 may 1876)";
							outputPosition(81, 14);
							getline(std::cin, period);
							outputPosition(81, 16);
							std::cout << "Changes saved successfully!";
							while (!checkDatesValidation(period))
							{
								outputPosition(81, 14);
								std::cout << "The data you've entered is incorrect!";
								outputPosition(81, 16);
								std::cout << "Please enter a date/s - ex(24 apr 809, 27 apr 810)";
								outputPosition(81, 18);
								getline(std::cin, period);
								outputPosition(81, 20);
								std::cout << "Changes saved successfully!";
							}
							DateManager dateManager;
							eventManager->setMultiValueField((
								eventManager->getEventWithName(
									approveEvents[__int64(selectedOption) - 1].title)
								)->period, 
								dateManager.converVectorOfStringsToVectorOfDate(
									separateDates(period)
								)
							);
							break;
						case 3:
							printFullyOpenedBook();
							printMapPopUp();
							printBulgarianMap();
							outputPosition(x, y);
							std::cout << char(254);
							while ((key = _getch()) != (char)ARROW_KEYS::KEY_ENTER)
							{
								switch (key)
								{
								case (char)ARROW_KEYS::KEY_UP:
									outputPosition(x, y);
									std::cout << " ";
									y -= 1;
									outputPosition(x, y);
									std::cout << char(254);
									break;
								case (char)ARROW_KEYS::KEY_DOWN:
									outputPosition(x, y);
									std::cout << " ";
									y += 1;
									outputPosition(x, y);
									std::cout << char(254);
									break;
								case (char)ARROW_KEYS::KEY_LEFT:
									outputPosition(x, y);
									std::cout << " ";
									x += 1;
									outputPosition(x, y);
									std::cout << char(254);
									break;
								case (char)ARROW_KEYS::KEY_RIGHT:
									outputPosition(x, y);
									std::cout << " ";
									x -= 1;
									outputPosition(x, y);
									std::cout << char(254);
									break;
								case (char)ARROW_KEYS::KEY_ENTER:
									printFullyOpenedBook();
									break;
								}
							}
							eventManager->setSingleValueField((
								eventManager->getEventWithName(
									approveEvents[__int64(selectedOption) - 1].title)
								)->coordinates.X, (short)x);
							eventManager->setSingleValueField((
								eventManager->getEventWithName(
									approveEvents[__int64(selectedOption) - 1].title)
								)->coordinates.Y, (short)y);
							break;
						}
					}
				}
			}
			(void)_getch();
			clearConsole();
			printClosedBook();
			printBookDecorations();
			printSnakeSword();
			printTeamLogo();
		}
	}
}

void displayEvents(EventManager* eventManager, bool getAllEvents)
{
	outputPosition(81, 10);
	std::cout << "How you want to display the events?" << std::endl;
	int selectedOption = 1;
	char pressedKey = ' ';
	const std::vector<std::string> visualizationOptions =
	{
		"As a map",
		"As an encyclopedia"
	};

	while (pressedKey != (int)ARROW_KEYS::KEY_ENTER)
	{
		for (int i = 0; i < visualizationOptions.size(); i++)
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
			std::cout << visualizationOptions[i] << std::endl << std::endl;
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
			if (selectedOption == visualizationOptions.size() + 1)
			{
				selectedOption -= 1;
			}
			break;
		case (int)ARROW_KEYS::KEY_ENTER:
			switch (selectedOption)
			{
			case 1:
				printFullyOpenedBook();
				printAsMap(eventManager, getAllEvents);
				break;
			case 2:
				printFullyOpenedBook();
				printBy(eventManager, getAllEvents);
				break;
			}
		}
	}

	clearConsole();
	printClosedBook();
	printBookDecorations();
	printSnakeSword();
	printTeamLogo();
}

void approveEvent(EventManager* eventManager)
{
	std::vector<Event> allUnapprovedEvents = eventManager->getAllEvents(false);

	if (allUnapprovedEvents.empty())
	{
		outputPosition(81, 10);
		std::cout << "There are no events to display";
		outputPosition(81, 12);
		std::cout << "Press Enter to go back!";
		(void)_getch();
		return;
	}

	printFullyOpenedBook();
	outputPosition(81, 10);
	std::cout << "Choose events that you want to approve:";

	int selectedOption = 1;
	char pressedKey = ' ';

	while (pressedKey != (int)ARROW_KEYS::KEY_ENTER)
	{
		for (int i = 0; i < allUnapprovedEvents.size(); i++)
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
			std::cout << allUnapprovedEvents[i].title << std::endl << std::endl;
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
			if (selectedOption == allUnapprovedEvents.size() + 1)
			{
				selectedOption -= 1;
			}
			break;
		case (int)ARROW_KEYS::KEY_ENTER:
			displayEvent(
				allUnapprovedEvents[__int64(selectedOption) - 1],
				true,
				eventManager
			);
			return;
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