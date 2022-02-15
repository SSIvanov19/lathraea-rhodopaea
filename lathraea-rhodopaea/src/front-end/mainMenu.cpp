#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <algorithm>
#include <conio.h>
#include <front-end/output.h>
#include <front-end/graphics.h>
#include <front-end/animations.h>
#include <front-end/enumerations.h>
#include <back-end/eventManager.h>
#include <back-end/datetimeManager.h>
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
 * @brief Function for checking whether the month is entered correctly
 * @param month The month that needs to be checked
 * @return true/false
*/
bool isValidMonthName(std::string month)
{
	std::string months[12] = {
		"jan", "feb", "mar",
		"apr", "may", "jun",
		"jul", "aug", "sep",
		"oct", "nov", "dec"
	};

	for (size_t i = 0; i < 12; i++)
	{
		if (month == months[i])
		{
			return true;
		}
	}

	return false;
}

/**
 * @brief Function for checking whether the day is in range
 * @param day A day that needs to be checked
 * @return true/false
*/
bool isDayInRange(std::string day)
{
	if (stoi(day) >= 1 && stoi(day) <= 31)
	{
		return true;
	}
	return false;
}

/**
 * @brief Function for checking whether the date is entered in the correct way
 * @param str The string containing the date/s
 * @return true/false
*/
bool checkDatesValidation(std::string str)
{
	bool twoDates = false;
	int whiteSpaces = 0;

	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == ',')
		{
			twoDates = true;
		}
		if (str[i] == ' ')
		{
			whiteSpaces++;
		}
	}

	if (whiteSpaces != 5 && twoDates == 1)
	{
		return false;
	}

	if (whiteSpaces != 2 && twoDates == 0)
	{
		return false;
	}

	whiteSpaces = 0;

	std::string day, month, year, dayTwo, monthTwo, yearTwo;

	for (size_t i = 0; i < str.size(); i++)
	{

		if (str[i] == ' ')
		{
			whiteSpaces++;
			continue;
		}

		if (whiteSpaces == 0)
		{
			day += str[i];
		}
		if (whiteSpaces == 1)
		{
			month += str[i];
		}
		if (whiteSpaces == 2)
		{
			year += str[i];
		}

		if (twoDates)
		{
			if (whiteSpaces == 3)
			{
				dayTwo += str[i];
			}
			if (whiteSpaces == 4)
			{
				monthTwo += str[i];
			}
			if (whiteSpaces == 5)
			{
				yearTwo += str[i];
			}
		}

	}

	if (!isDayInRange(day))
	{
		return false;
	}

	if (twoDates && !isDayInRange(dayTwo))
	{
		return false;
	}

	if (!isValidMonthName(month) || (!isValidMonthName(monthTwo) && twoDates))
	{
		return false;
	}

	return true;
}

/**
 * @brief Function for passing the date/s as vector
 * @param str The string containing the date/s
 * @return The date/s as vector
*/
std::vector <std::string> separateDates(std::string str)
{
	std::string startDate;
	std::string endDate;
	std::string day, month, year, dayTwo, monthTwo, yearTwo;

	std::vector <std::string> dates;

	bool twoDates = false;
	int whiteSpaces = 0;

	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == ',')
		{
			twoDates = true;
		}
	}

	for (size_t i = 0; i < str.size(); i++)
	{

		if (str[i] == ' ')
		{
			whiteSpaces++;
			continue;
		}

		if (str[i] != ',')
		{
			if (whiteSpaces == 0)
			{
				day += str[i];
			}
			if (whiteSpaces == 1)
			{
				month += str[i];
			}
			if (whiteSpaces == 2)
			{
				year += str[i];
			}
		}

		if (twoDates)
		{
			if (whiteSpaces == 3)
			{
				dayTwo += str[i];
			}
			if (whiteSpaces == 4)
			{
				monthTwo += str[i];
			}
			if (whiteSpaces == 5)
			{
				yearTwo += str[i];
			}
		}

	}

	startDate += day + ' ' + month + ' ' + year;
	endDate += dayTwo + ' ' + monthTwo + ' ' + yearTwo;

	if (twoDates)
	{
		dates.push_back(startDate);
		dates.push_back(endDate);
	}
	else
	{
		dates.push_back(startDate);
	}
	return dates;
}

/**
 * @brief Function for adding events of type "other"
 * @param eventManager Variable for an event manager
*/
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
	int x = 56;
	int y = 20;
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

/**
 * @brief Function for adding events of type "uprising"
 * @param eventManager Variable for an event manager
*/
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
	int x = 56;
	int y = 20;
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
	std::cout << "Enter the number of rebilions of the event: ";
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
		eventManager->addUprisingEvent(title, separateDates(period), coordinates, organizersV, isItSuccessful, numberOfRebelions, additionalNotes);
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

/**
 * @brief Function for adding events of type "war"
 * @param eventManager Variable for an event manager
*/
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
	int x = 56;
	int y = 20;
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
		eventManager->addWarEvent(title, separateDates(period), coordinates, participatingCountriesV, winner, reasons, rulersV, additionalNotes);
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

/**
 * @brief Function for adding events of type "movement"
 * @param eventManager Variable for an event manager
*/
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
	int x = 56;
	int y = 20;
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
		eventManager->addMovementEvent(title, separateDates(period), coordinates, howItStarted, ideas, aims, representativesV, additionalNotes);
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

/**
 * @brief Function for adding historical events
 * @param eventManager Variable for an event manager
*/
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

/**
 * @brief Function for deleting historical events
 * @param eventManager Variable for an event manager
*/
void deleteEvent(EventManager* eventManager)
{
	std::vector<Event> approveEvents = eventManager->getAllEvents(1);
	std::vector<Event> unApproveEvents = eventManager->getAllEvents(0);
	
	approveEvents.insert(approveEvents.end(), unApproveEvents.begin(), unApproveEvents.end());

	if (approveEvents.empty())
	{
		outputPosition(81, 10);
		std::cout << "There are no sorylines to display";
		outputPosition(81, 11);
		std::cout << "Press any key to go back!";
		_getch();
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
			if (!eventManager->removeEvent(&eventManager->eventList, approveEvents[selectedOption - 1].title))
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

/**
 * @brief Function for converting information in vector to string
 * @param information Given vector
 * @return Information as string
*/
std::string separate(const std::vector<std::string> information)
{
	std::string result = " ";

	for (size_t i = 0; i < information.size(); i++)
	{
		result += information[i];
		result += ", ";
	}

	return result;
}

/**
 * @brief Function for displaying information about a particular event
 * @param e Given event
*/
void displayEvent(const Event& e, bool approve = false, EventManager* eventManager = nullptr)
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
		outputPosition(81, 14);
		std::cout << "Time of creation: " << e.timeOfCreation;
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
			std::cout << "Duration in days: " << dateManager.getDifference(e.period[0], e.period[1]) << std::endl;
			outputPosition(81, 27);
			std::cout << "Success: ";
			switch (e.isItSuccessful)
			{
			case 0: std::cout << "No";
			case 1: std::cout << "Yes";
			}
			outputPosition(81, 29);
			std::cout << "Number of rebilions: " << e.numberOfRebelions;
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
			case 0: std::cout << "No";
			case 1: std::cout << "Yes";
			}
			outputPosition(81, 25);
			std::cout << "Number of rebilions: " << e.numberOfRebelions;
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
		outputPosition(81, 14);
		std::cout << "Time of creation: " << e.timeOfCreation;
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
			std::cout << "Duration in days: " << dateManager.getDifference(e.period[0], e.period[1]) << std::endl;
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
		outputPosition(81, 14);
		std::cout << "Time of creation: " << e.timeOfCreation;
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
			std::cout << "Duration in days: " << dateManager.getDifference(e.period[0], e.period[1]) << std::endl;
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
		outputPosition(81, 14);
		std::cout << "Time of creation: " << e.timeOfCreation;
		outputPosition(81, 16);
		std::cout << "Type: Other";
		outputPosition(81, 18);
		std::cout << "Epoch: " << e.epochs[0];
		if (e.period.size() == 2)
		{
			outputPosition(81, 21);
			std::cout << "Start date: " << std::put_time(&e.period[0], "%x") << std::endl;
			outputPosition(81, 23);
			std::cout << "End date: " << std::put_time(&e.period[1], "%x") << std::endl;
			outputPosition(81, 25);
			std::cout << "Duration in days: " << dateManager.getDifference(e.period[0], e.period[1]) << std::endl;
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
		int xCord;

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
		_getch();
		clearConsole();
		printClosedBook();
		printBookDecorations();
		printSnakeSword();
		printTeamLogo();
	}
}

/**
 * @brief Function for choosing event to display
 * @param events Vector with all the events to show
 * @param output The way the events should be displayed
*/
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
					std::cout << events[i].title << " - " << events[i].period[j].tm_mday << " " << events[i].period[j].tm_mon + 1 << " " << events[i].period[j].tm_year + 1900 << std::endl;
				}
			}
			else if (output == 2)
			{
				for (int i = 0; i < events.size(); i++)
				{
					for (int j = 0; j < events[i].period.size(); j++)
					{
						outputPosition(84, 10 + i * 2);
						std::cout << events[i].period[j].tm_mday << " " << events[i].period[j].tm_mon + 1 << " " << events[i].period[j].tm_year + 1900 << " - " << events[i].title;
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
			displayEvent(events[selectedOption - 1]);
		}
	}
}

/**
 * @brief Function for displaying all the events
 * @param eventManager Variable for an event manager
 * @param sorting The way of sorting
 * @param type The parameter we sort
*/
void displayAllEvents(EventManager* eventManager, int sorting, int& type, bool getAllEvents = false)
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
		_getch();
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


/**
 * @brief Function for choosing the way of sorting the events by year
 * @param eventManager Variable for an event manager
*/
void chooseSorting(EventManager* eventManager, int type, bool getAllEvents = false)
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

/**
 * @brief Function for choosing the type of printing the events
 * @param eventManager Variable for an event manager
*/
void printBy(EventManager* eventManager, bool getAllEvents = false)
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
		}
	}
}

/**
 * @brief Function for printing event coordinates on map
 * @param eventManager Variable for an event manager
*/
void printAsMap(EventManager* eventManager, bool getAllEvents = false)
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
		_getch();
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
				std::cout << allEvents[i].title << " - " << allEvents[i].period[j].tm_mday << " " << allEvents[i].period[j].tm_mon + 1 << " " << allEvents[i].period[j].tm_year + 1900 << std::endl;
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
			outputPosition((allEvents[selectedOption - 1].coordinates.X), (allEvents[selectedOption - 1].coordinates.Y));
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

	approveEvents.insert(approveEvents.end(), unApproveEvents.begin(), unApproveEvents.end());


	if (approveEvents.empty())
	{
		outputPosition(81, 10);
		std::cout << "There are no events to display";
		outputPosition(81, 12);
		std::cout << "Press Enter to go back!";
		_getch();
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
				std::cout << approveEvents[i].title << " - " << approveEvents[i].period[j].tm_mday << " " << approveEvents[i].period[j].tm_mon + 1 << " " << approveEvents[i].period[j].tm_year + 1900 << std::endl;
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
				"Number of rebilions",
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
			if ((approveEvents[selectedOption - 1].type == TypeOfEvent::UPRISING))
			{
				printFullyOpenedBook();
				outputPosition(81, 10);
				std::cout << "What do you want to edit?";

				std::string title;
				std::string period;
				std::string organizers;
				bool isItSuccessful = true;
				int rebilions;
				const std::vector<std::string> successOfEventOptions = {
					"Successful",
					"Unsuccessful"
				};
				int x = 56;
				int y = 20;
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

							eventManager->setSingleValueField((eventManager->getEventWithName(approveEvents[selectedOption - 1].title))->title, title);
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
							eventManager->setMultiValueField((eventManager->getEventWithName(approveEvents[selectedOption - 1].title))->period, dateManager.converVectorOfStringsToVectorOfDate(separateDates(period)));
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
							eventManager->setSingleValueField((eventManager->getEventWithName(approveEvents[selectedOption - 1].title))->coordinates.X, (short)x);
							eventManager->setSingleValueField((eventManager->getEventWithName(approveEvents[selectedOption - 1].title))->coordinates.Y, (short)y);
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
							eventManager->setMultiValueField((eventManager->getEventWithName(approveEvents[selectedOption - 1].title))->organizers, { organizers });
							break;
						case 5:
							printFullyOpenedBook();
							outputPosition(81, 10);
							std::cout << "Enter the numbers of rebilions: " << std::endl;
							outputPosition(81, 12);
							std::cin >> rebilions;

							outputPosition(81, 14);
							std::cout << "Changes saved successfully!";
							eventManager->setSingleValueField((eventManager->getEventWithName(approveEvents[selectedOption - 1].title))->numberOfRebelions, rebilions);
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

										break;
									case 2:
										isItSuccessful = false;
										break;
									}
								}
							}
							eventManager->setSingleValueField((eventManager->getEventWithName(approveEvents[selectedOption - 1].title))->isItSuccessful, isItSuccessful);
							break;
						}
					}
				}
			}
			else if ((approveEvents[selectedOption - 1].type == TypeOfEvent::WAR))
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
				int x = 56;
				int y = 20;
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

							eventManager->setSingleValueField((eventManager->getEventWithName(approveEvents[selectedOption - 1].title))->title, title);
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
							eventManager->setMultiValueField((eventManager->getEventWithName(approveEvents[selectedOption - 1].title))->period, dateManager.converVectorOfStringsToVectorOfDate(separateDates(period)));
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
							eventManager->setSingleValueField((eventManager->getEventWithName(approveEvents[selectedOption - 1].title))->coordinates.X, (short)x);
							eventManager->setSingleValueField((eventManager->getEventWithName(approveEvents[selectedOption - 1].title))->coordinates.Y, (short)y);
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
							eventManager->setMultiValueField((eventManager->getEventWithName(approveEvents[selectedOption - 1].title))->participatingCountries, { participatingCountries });
							break;
						case 5:
							printFullyOpenedBook();
							outputPosition(81, 10);
							std::cout << "Enter the winner of the event: " << std::endl;
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

							eventManager->setSingleValueField((eventManager->getEventWithName(approveEvents[selectedOption - 1].title))->winner, winner);
							break;
						case 6:
							printFullyOpenedBook();
							outputPosition(81, 10);
							std::cout << "Enter the reasons of the event: " << std::endl;
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

							eventManager->setSingleValueField((eventManager->getEventWithName(approveEvents[selectedOption - 1].title))->reason, reasons);
							break;
						case 7:
							printFullyOpenedBook();
							outputPosition(81, 10);
							std::cout << "Enter the rulers of the event: " << std::endl;
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

							eventManager->setSingleValueField((eventManager->getEventWithName(approveEvents[selectedOption - 1].title))->rulers, { rulers });
							break;
						}
					}
				}
			}
			else if ((approveEvents[selectedOption - 1].type == TypeOfEvent::MOVEMENT))
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
				int x = 56;
				int y = 20;
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

							eventManager->setSingleValueField((eventManager->getEventWithName(approveEvents[selectedOption - 1].title))->title, title);
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
							eventManager->setMultiValueField((eventManager->getEventWithName(approveEvents[selectedOption - 1].title))->period, dateManager.converVectorOfStringsToVectorOfDate(separateDates(period)));
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
							eventManager->setSingleValueField((eventManager->getEventWithName(approveEvents[selectedOption - 1].title))->coordinates.X, (short)x);
							eventManager->setSingleValueField((eventManager->getEventWithName(approveEvents[selectedOption - 1].title))->coordinates.Y, (short)y);
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

							eventManager->setSingleValueField((eventManager->getEventWithName(approveEvents[selectedOption - 1].title))->howItStarted, howItStarted);
							break;
						case 5:
							printFullyOpenedBook();
							outputPosition(81, 10);
							std::cout << "Enter the ideas of the event: " << std::endl;
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

							eventManager->setSingleValueField((eventManager->getEventWithName(approveEvents[selectedOption - 1].title))->ideas, ideas);
							break;
						case 6:
							printFullyOpenedBook();
							outputPosition(81, 10);
							std::cout << "Enter the aims of the event: " << std::endl;
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

							eventManager->setSingleValueField((eventManager->getEventWithName(approveEvents[selectedOption - 1].title))->aims, aims);
							break;
						case 7:
							printFullyOpenedBook();
							outputPosition(81, 10);
							std::cout << "Enter the representatives of the event: " << std::endl;
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

							eventManager->setSingleValueField((eventManager->getEventWithName(approveEvents[selectedOption - 1].title))->representatives, { representatives });
							break;
						}
					}
				}
			}
			else if ((approveEvents[selectedOption - 1].type == TypeOfEvent::OTHER))
			{
				printFullyOpenedBook();
				outputPosition(81, 10);
				std::cout << "What do you want to edit?";

				std::string title;
				std::string period;
				int x = 56;
				int y = 20;
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

							eventManager->setSingleValueField((eventManager->getEventWithName(approveEvents[selectedOption - 1].title))->title, title);
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
							eventManager->setMultiValueField((eventManager->getEventWithName(approveEvents[selectedOption - 1].title))->period, dateManager.converVectorOfStringsToVectorOfDate(separateDates(period)));
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
							eventManager->setSingleValueField((eventManager->getEventWithName(approveEvents[selectedOption - 1].title))->coordinates.X, (short)x);
							eventManager->setSingleValueField((eventManager->getEventWithName(approveEvents[selectedOption - 1].title))->coordinates.Y, (short)y);
							break;
						}
					}
				}
			}
			_getch();
			clearConsole();
			printClosedBook();
			printBookDecorations();
			printSnakeSword();
			printTeamLogo();
		}
	}
}

void printStorylineOnMap(StorylineManager* storylineManager, bool getAllEvents = false)
{
	std::vector<Storyline> allStorylines = storylineManager->getAllStorylines(true);
	if (getAllEvents)
	{
		std::vector<Storyline> unApproveStorylines = storylineManager->getAllStorylines(false);
		allStorylines.insert(allStorylines.end(), unApproveStorylines.begin(), unApproveStorylines.end());
	}

	if (allStorylines.empty())
	{
		outputPosition(81, 10);
		std::cout << "There are no storylines to display";
		outputPosition(81, 12);
		std::cout << "Press Enter to go back!";
		_getch();
		return;
	}

	if (allStorylines.empty())
	{
		outputPosition(81, 10);
		std::cout << "There are no storylines to display";
		outputPosition(81, 12);
		std::cout << "Press Enter to go back!";
	}
	else
	{
		outputPosition(81, 10);
		std::cout << "Which storyline do you want to display?";
		int selectedOption = 1;
		char pressedKey = ' ';

		while (pressedKey != (int)ARROW_KEYS::KEY_ENTER)
		{
			for (int i = 0; i < allStorylines.size(); i++)
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
				outputPosition(84, 12 + i * 2);
				std::cout << allStorylines[i].title << std::endl;
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
				if (selectedOption == allStorylines.size() + 1)
				{
					selectedOption -= 1;
				}
				break;
			case (int)ARROW_KEYS::KEY_ENTER:
				printTimelinePopUp();
				printMapPopUp();
				printBulgarianMap();
				for (size_t i = 0; i < allStorylines[selectedOption - 1].events.size(); i++)
				{
					size_t middlePos = allStorylines[selectedOption - 1].events[i].title.size() / 2;

					outputPosition(
						allStorylines[selectedOption - 1].events[i].coordinates.X  - middlePos,
						allStorylines[selectedOption - 1].events[i].coordinates.Y - 1
					);
					ShowCursor(true);
					std::cout << allStorylines[selectedOption - 1].events[i].title;

					outputPosition(
						allStorylines[selectedOption - 1].events[i].coordinates.X,
						allStorylines[selectedOption - 1].events[i].coordinates.Y
					);
					std::cout << char(254);
				}
			}
		}
	}
	_getch();
	clearConsole();
	printClosedBook();
	printBookDecorations();
	printSnakeSword();
	printTeamLogo();
}

/**
 * @brief Function for printing events as a timeline
 * @param storylineManager Variable for an storyline manager
*/
void printAsTimeline(StorylineManager* storylineManager, bool getAllEvents = false)
{
	std::vector<Storyline> allStorylines = storylineManager->getAllStorylines(true);
	if (getAllEvents)
	{
		std::vector<Storyline> unApproveStorylines = storylineManager->getAllStorylines(false);
		allStorylines.insert(allStorylines.end(), unApproveStorylines.begin(), unApproveStorylines.end());
	}


	if (allStorylines.empty())
	{
		outputPosition(81, 10);
		std::cout << "There are no storylines to display";
		outputPosition(81, 12);
		std::cout << "Press Enter to go back!";
	}
	else
	{
		outputPosition(81, 10);
		std::cout << "Which storyline do you want to display?";
		int selectedOption = 1;
		char pressedKey = ' ';

		while (pressedKey != (int)ARROW_KEYS::KEY_ENTER)
		{
			for (int i = 0; i < allStorylines.size(); i++)
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
				outputPosition(84, 12 + i * 2);
				std::cout << allStorylines[i].title << std::endl;
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
				if (selectedOption == allStorylines.size() + 1)
				{
					selectedOption -= 1;
				}
				break;
			case (int)ARROW_KEYS::KEY_ENTER:
				printTimelinePopUp();
				printTimeline();
				for (size_t i = 0; i < allStorylines[selectedOption - 1].events.size(); i++)
				{
					int xY;
					int yY;

					switch (i)
					{
					case 0:
						xY = 49;
						yY = 28;
						break;
					case 1:
						xY = 57;
						yY = 22;
						break;
					case 2:
						xY = 65;
						yY = 28;
						break;
					case 3:
						xY = 73;
						yY = 22;
						break;
					case 4:
						xY = 81;
						yY = 28;
						break;
					case 5:
						xY = 89;
						yY = 22;
						break;
					}

					size_t sizeOfTitle = allStorylines[selectedOption - 1].events[i].title.size();

					if (sizeOfTitle <= 14)
					{
						size_t middlePos = sizeOfTitle / 2;
						
						outputPosition(xY - middlePos + 2, yY - 1);
						std::cout << allStorylines[selectedOption - 1].events[i].title;
						
						outputPosition(xY, yY);
						std::cout << allStorylines[selectedOption - 1].events[i].period[0].tm_year + 1900;
					}
					else
					{
						outputPosition(xY, yY);
						std::cout << allStorylines[selectedOption - 1].events[i].period[0].tm_year + 1900;
					}
				}
			}
		}
	}
	_getch();
	clearConsole();
	printClosedBook();
	printBookDecorations();
	printSnakeSword();
	printTeamLogo();
}

/**
 * @brief Function for choosing the way of printing the events
 * @param eventManager Variable for an event manager
*/
void displayStoryline(StorylineManager* storylineManager, bool getAllEvents = false)
{
	outputPosition(81, 10);
	std::cout << "How you want to display the storylines?" << std::endl;
	int selectedOption = 1;
	char pressedKey = ' ';
	const std::vector<std::string> visualizationOptions =
	{
		"As a timeline",
		"As a map"
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
				printAsTimeline(storylineManager, getAllEvents);
				break;
			case 2:
				printFullyOpenedBook();
				printStorylineOnMap(storylineManager, getAllEvents);
			}
		}
	}
}

/**
 * @brief Function for choosing the way of printing the events
 * @param eventManager Variable for an event manager
*/
void displayEvents(EventManager* eventManager, bool getAllEvents = false)
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

int getNumberOfSelectedEvents(std::vector<int> v)
{
	int counter = 0;

	for (int el : v)
	{
		if (el)
		{
			counter++;
		}
	}

	return counter;
}

void createStoryline(EventManager* eventManager, StorylineManager* storylineManager, AccountManager* accountManager, bool getEvents = false)
{
	std::vector<Event> events = eventManager->getAllEvents(true);
	if (accountManager->isAdmin())
	{
		std::vector<Event> eventsForApproving = eventManager->getAllEvents(false);
		events.insert(events.end(), eventsForApproving.begin(), eventsForApproving.end());
	}

	if (events.empty())
	{
		outputPosition(81, 10);
		std::cout << "There are no events to add to storyline";
		outputPosition(81, 12);
		std::cout << "Press Enter to go back!";
		_getch();
		clearConsole();
		printClosedBook();
		printBookDecorations();
		printSnakeSword();
		printTeamLogo();
		return;
	}

	static std::vector<int> indexSelectedEvents(events.size(), 0);

	if (getEvents)
	{
		indexSelectedEvents = std::vector<int>(events.size(), 0);
	}

	static int selectedOptions = 0;

	outputPosition(81, 10);
	std::cout << "Chose up to six events to be added to storyline: " << std::endl;

	for (size_t i = 0; i < events.size(); i++)
	{
		outputPosition(81, 12 + i);
		selectedOptions == i ? std::cout << " -> " : std::cout << "    ";

		std::cout << events[i].title;

		if (indexSelectedEvents[i])
		{
			std::cout << " +";
		}
		else
		{
			std::cout << " -";
		}
	}

	outputPosition(81, 12 + events.size());

	int numOfSelEvents = getNumberOfSelectedEvents(indexSelectedEvents);

	if (numOfSelEvents > 1)
	{
		selectedOptions == events.size() ? std::cout << " -> Add events to storyline" : std::cout << "    Add events to storyline";
	}
	else
	{
		std::cout << "                           ";
	}

	char pressedKey = _getch();
	switch (pressedKey)
	{
	case (int)ARROW_KEYS::KEY_UP:
		if (selectedOptions != 0) selectedOptions--;
		createStoryline(eventManager, storylineManager, accountManager);
		break;

	case (int)ARROW_KEYS::KEY_DOWN:
		if (numOfSelEvents > 1)
		{
			if (selectedOptions != events.size()) selectedOptions++;
		}
		else
		{
			if (selectedOptions != events.size() - 1) selectedOptions++;
		}
		createStoryline(eventManager, storylineManager, accountManager);
		break;
	case (int)ARROW_KEYS::KEY_ENTER:
		if (selectedOptions >= 0 && selectedOptions < events.size())
		{

			if (numOfSelEvents > 5)
			{
				if (indexSelectedEvents[selectedOptions] == 1)
				{
					indexSelectedEvents[selectedOptions] = 0;
					outputPosition(81, 13 + events.size());
					std::cout << "                                                  ";
				}
				else
				{
					outputPosition(81, 13 + events.size());
					std::cout << "Can not add more than 6 events to single storyline";
				}
			}
			else
			{
				outputPosition(81, 13 + events.size());
				std::cout << "                                                  ";
				indexSelectedEvents[selectedOptions] = !indexSelectedEvents[selectedOptions];
			}
		}
		else
		{
			outputPosition(81, 13 + events.size());
			std::cout << "                                                  ";

			std::string title;
			outputPosition(81, 13 + events.size());
			std::cout << "Please, enter title for the new storyline";
			outputPosition(81, 14 + events.size());
			getline(std::cin, title);

			while (title.empty())
			{
				outputPosition(81, 13 + events.size());
				std::cout << "Please, enter title for the new storyline";
				outputPosition(81, 14 + events.size());
				getline(std::cin, title);
			}

			std::string desc;
			outputPosition(81, 15 + events.size());
			std::cout << "Please, enter description for the new storyline";
			outputPosition(81, 16 + events.size());
			getline(std::cin, desc);

			std::vector<Event> storylineEvents;

			for (size_t i = 0; i < indexSelectedEvents.size(); i++)
			{
				if (indexSelectedEvents[i])
				{
					storylineEvents.push_back(events[i]);
				}
			}

			storylineEvents = eventManager->sortAndGetAllEventsByDate(storylineEvents);

			try
			{
				storylineManager->addStoryline(title, storylineEvents, desc);
				if (accountManager->isAdmin())
				{
					storylineManager->approveStoryline(title);
				}
				indexSelectedEvents.clear();
				selectedOptions = 0;
				clearConsole();
				printClosedBook();
				printBookDecorations();
				printSnakeSword();
				printTeamLogo();
				return;
			}
			catch (std::string error)
			{
				outputPosition(81, 17 + events.size());
				std::cout << error;
				_getch();
				outputPosition(81, 13 + events.size());
				for (int i = 0; i < 10; i++)
				{
					std::cout << "                                                  ";
					outputPosition(81, 13 + events.size() + i);
				}

				createStoryline(eventManager, storylineManager, accountManager);
			}
		}

		createStoryline(eventManager, storylineManager, accountManager);
		break;
	case (int)ARROW_KEYS::KEY_ESC:
		indexSelectedEvents.clear();
		selectedOptions = 0;
		clearConsole();
		printClosedBook();
		printBookDecorations();
		printSnakeSword();
		printTeamLogo();
		return;
	default:
		createStoryline(eventManager, storylineManager, accountManager);
	}
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
		_getch();
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
			displayEvent(allUnapprovedEvents[selectedOption - 1], true, eventManager);
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

void adminEventManagment(EventManager* eventManager, StorylineManager* storylineManager)
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

void approveStoryline(StorylineManager* storylineManager)
{
	std::vector<Storyline> storylines = storylineManager->getAllStorylines(false);

	if (storylines.empty())
	{
		outputPosition(81, 10);
		std::cout << "There are no storylines to display";
		outputPosition(81, 12);
		std::cout << "Press Enter to go back!";
		_getch();
		return;
	}

	printFullyOpenedBook();
	outputPosition(81, 10);
	std::cout << "Choose events that you want to approve:";

	int selectedOption = 1;
	char pressedKey = ' ';

	while (pressedKey != (int)ARROW_KEYS::KEY_ENTER)
	{
		for (int i = 0; i < storylines.size(); i++)
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
			std::cout << storylines[i].title << std::endl << std::endl;
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
			if (selectedOption == storylines.size() + 1)
			{
				selectedOption -= 1;
			}
			break;
		case (int)ARROW_KEYS::KEY_ENTER:
			try
			{
				storylineManager->approveStoryline(storylines[selectedOption - 1].title);
				return;
			}
			catch (std::string msg)
			{
				outputPosition(81, 18);
				std::cout << "There was problem approving the storyline:";
				outputPosition(81, 19);
				std::cout << msg;
				outputPosition(81, 20);
				std::cout << "Plese try again!";
				_getch();
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

/**
 * @brief Function for deleting historical events
 * @param eventManager Variable for an event manager
*/
void deleteStoryline(StorylineManager* storylineManager)
{
	std::vector<Storyline> approveStorylines = storylineManager->getAllStorylines(1);
	std::vector<Storyline> unApproveStorylines = storylineManager->getAllStorylines(0);

	approveStorylines.insert(approveStorylines.end(), unApproveStorylines.begin(), unApproveStorylines.end());

	if (approveStorylines.empty())
	{
		outputPosition(81, 10);
		std::cout << "There are no storylines to display";
		outputPosition(81, 12);
		std::cout << "Press Enter to go back!";
		_getch();
		return;
	}

	printFullyOpenedBook();
	outputPosition(81, 10);
	std::cout << "Choose storyline that you want to remove:";

	int selectedOption = 1;
	char pressedKey = ' ';

	while (pressedKey != (int)ARROW_KEYS::KEY_ENTER)
	{
		for (int i = 0; i < approveStorylines.size(); i++)
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
			std::cout << approveStorylines[i].title;
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
			if (selectedOption == approveStorylines.size() + 1)
			{
				selectedOption -= 1;
			}
			break;
		case (int)ARROW_KEYS::KEY_ENTER:
			clearConsole();
			printFullyOpenedBook();
			if (!storylineManager->removeStoryline(&storylineManager->storylineList, approveStorylines[selectedOption - 1].title))
			{
				outputPosition(81, 20);
				std::cout << "The storyline wasn't found";
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

void adminStorylineManagment(EventManager* eventManager, StorylineManager* storylineManager, AccountManager* accountManager)
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
				createStoryline(eventManager, storylineManager, accountManager, true);
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

std::string enumToString(Roles role)
{
	switch (role)
	{
	case Roles::USER:
		return "User";
		break;
	case Roles::ADMIN:
		return "Admin";
		break;
	default:
		return "User";
		break;
	}
}

void showUserInfo(Account account, AccountManager* accountManager)
{
	std::vector<std::string> options = {
		"Make admin",
		"Remove user",
		"Back"
	};

	outputPosition(81, 10);
	std::cout << "Account info:";
	outputPosition(81, 11);
	std::cout << "Username: " << account.uname;
	outputPosition(81, 12);
	std::cout << "Email: " << account.email;
	outputPosition(81, 13);
	std::cout << "Role: " << enumToString(account.role);
	outputPosition(81, 15);
	std::cout << "Choose actions:";
	int selectedOption = 1;
	char pressedKey = ' ';

	while (pressedKey != (int)ARROW_KEYS::KEY_ENTER)
	{
		for (int i = 0; i < options.size(); i++)
		{
			if (i + 1 == selectedOption)
			{
				outputPosition(81, 16 + i);
				std::cout << "-> ";
			}
			else
			{
				outputPosition(81, 16 + i);
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
				// Make admin
				accountManager->changeUserRoleToAdmin(account.email);
				return;
				break;
			case 2:
				if (!accountManager->removeAccount(&accountManager->accountList, account.email))
				{
					throw std::string("There was a problem with the program. Error deleteing user");
				}

				return;
				break;
			case 3:
				// Back
				return;
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

void viewAllUsers(AccountManager* accountManager)
{
	std::vector<Account> allAccounts = accountManager->getAllUserData();

	printFullyOpenedBook();
	outputPosition(81, 10);
	std::cout << "Choose which user you want to view:";

	int selectedOption = 1;
	char pressedKey = ' ';

	while (pressedKey != (int)ARROW_KEYS::KEY_ENTER)
	{
		for (int i = 0; i < allAccounts.size(); i++)
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
			std::cout << allAccounts[i].uname << " - " << allAccounts[i].email << std::endl << std::endl;
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
			if (selectedOption == allAccounts.size() + 1)
			{
				selectedOption -= 1;
			}
			break;
		case (int)ARROW_KEYS::KEY_ENTER:
			clearConsole();
			printFullyOpenedBook();
			showUserInfo(allAccounts[selectedOption - 1], accountManager);
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

void addNewAdmin(AccountManager* accountManager)
{
	Validations validations;

	std::string email;
	std::string uname;
	std::string password;

	outputPosition(81, 10);
	std::cout << "Enter an email: ";

	std::getline(std::cin, email);

	while (!validations.isEmailValid(email))
	{
		outputPosition(81, 12);
		std::cout << "Please, enter a valid email: ";
		std::getline(std::cin, email);
		std::cout << std::endl;
		outputPosition(81, 12);
		std::cout << "                                                    " << std::endl;
	}

	std::cout << std::endl;
	outputPosition(81, 12);
	std::cout << "Enter a username: ";
	std::getline(std::cin, uname);
	while (!validations.isUnameValid(uname))
	{
		outputPosition(81, 14);
		std::cout << "Please, enter a valid uname: ";
		std::getline(std::cin, uname);
		std::cout << std::endl;
		outputPosition(81, 14);
		std::cout << "                                                    " << std::endl;
	}

	std::cout << std::endl;
	outputPosition(81, 14);
	std::cout << "Enter a password: ";
	std::getline(std::cin, password);
	while (!validations.isPassValid(password))
	{
		outputPosition(81, 16);
		std::cout << "Please, enter a valid password: ";
		std::getline(std::cin, password);
		std::cout << std::endl;
		outputPosition(81, 16);
		std::cout << "                                                    " << std::endl;
	}

	try
	{
		accountManager->registerUser(uname, email, password, Roles::ADMIN);
	}
	catch (std::string msg)
	{
		outputPosition(81, 18);
		std::cout << "There was problem with the regestration:";
		outputPosition(81, 19);
		std::cout << msg;
		outputPosition(81, 20);
		std::cout << "Plese try again!";
		_getch();
	}

}

void adminUserManagment(AccountManager* accountManager)
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
				//Event Managment
				bookOpeningAnimation();
				adminEventManagment(eventManager, storylineManager);
				break;
			case 2:
				//Storyline managment
				bookOpeningAnimation();
				adminStorylineManagment(eventManager, storylineManager, accountManager);
				break;
			case 3:
				// User Managment
				bookOpeningAnimation();
				adminUserManagment(accountManager);
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
				_getch();
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