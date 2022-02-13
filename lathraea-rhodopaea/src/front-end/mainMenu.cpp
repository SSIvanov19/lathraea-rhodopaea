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
void addOtherEvent(EventManager* eventManager)
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
void addUprisingEvent(EventManager* eventManager)
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
void addWarEvent(EventManager* eventManager)
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
void addMovementEvent(EventManager* eventManager)
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
void addEvent(EventManager* eventManager)
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
				addUprisingEvent(eventManager);
				break;
			case 2:
				addWarEvent(eventManager);
				break;
			case 3:
				addMovementEvent(eventManager);
				break;
			case 4:
				addOtherEvent(eventManager);
				break;
			}
		}
	}

	if (_getch())
	{
		system("CLS");
		printClosedBook();
		prinyBookDecorations();
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
	printFullyOpenedBook();
	std::string title;
	outputPosition(81, 10);
	std::cout << "Enter the title of the event you want to remove: ";
	outputPosition(81, 12);
	getline(std::cin, title);

	if (eventManager->removeEvent(&eventManager->eventList, title))
	{
		outputPosition(81, 14);
		std::cout << "You've successfully deleted the event!";
	}
	else
	{
		outputPosition(81, 14);
		std::cout << "The event wasn't found";
		while (!eventManager->removeEvent(&eventManager->eventList, title))
		{
			outputPosition(81, 16);
			std::cout << "Enter the title of the event you want to remove: ";

			outputPosition(81, 18);
			std::cout << "                                                  ";
			outputPosition(81, 18);
			getline(std::cin, title);
			if (eventManager->removeEvent(&eventManager->eventList, title))
			{
				outputPosition(81, 20);
				std::cout << "You've successfully deleted the event!";
			}
		}
	}

	if (_getch())
	{
		system("CLS");
		printClosedBook();
		prinyBookDecorations();
		printSnakeSword();
		printTeamLogo();
	}
}

/**
 * @brief Function for displaying all the events by their title
 * @param eventManager Variable for an event manager
*/
void displayAllEventsByTitle(EventManager* eventManager, int sorting)
{
	std::vector<Event> allEvents = eventManager->getAllEvents(0);
	if (allEvents.empty())
	{
		outputPosition(81, 10);
		std::cout << "There are no events to display";
		outputPosition(81, 11);
		std::cout << "Press any key to go back!";
		_getch();
		system("CLS");
		printClosedBook();
		prinyBookDecorations();
		printSnakeSword();
		printTeamLogo();
		return;
	}
	if (sorting == 1)
	{
		allEvents = eventManager->sortAndGetAllEventsByTitle(allEvents);
	}
	else if (sorting == 2)
	{
		allEvents = eventManager->sortAndGetAllEventsByTitle(allEvents);
		reverse(allEvents.begin(), allEvents.end());
	}

	outputPosition(81, 10);
	std::cout << "Press Enter if you want to go back!";
	for (int i = 0; i < allEvents.size(); i++)
	{
		outputPosition(81, 12 + i * 2);
		std::cout << allEvents[i].title << std::endl;
	}
	int key;
	key = _getch();
	if (key == (int)ARROW_KEYS::KEY_ENTER)
	{
		system("CLS");
		printClosedBook();
		prinyBookDecorations();
		printSnakeSword();
		printTeamLogo();
		return;
	}
}

/**
 * @brief Function for displaying all the events by their period
 * @param eventManager Variable for an event manager
*/
void displayAllEventsByYear(EventManager* eventManager, int sorting)
{
	std::vector<Event> allEvents = eventManager->getAllEvents(0);
	if (allEvents.empty())
	{
		outputPosition(81, 10);
		std::cout << "There are no events to display";
		outputPosition(81, 11);
		std::cout << "Press any key to go back!";
		_getch();
		system("CLS");
		printClosedBook();
		prinyBookDecorations();
		printSnakeSword();
		printTeamLogo();
		return;
	}
	if (sorting == 1)
	{
		allEvents = eventManager->sortAndGetAllEventsByDate(allEvents);
	}
	else if (sorting == 2)
	{
		allEvents = eventManager->sortAndGetAllEventsByDate(allEvents);
		reverse(allEvents.begin(), allEvents.end());
	}
	outputPosition(81, 10);
	std::cout << "Press Enter if you want to go back!";
	for (int i = 0; i < allEvents.size(); i++)
	{
		outputPosition(81, 12 + i * 2);
		for (int j = 0; j < allEvents[i].period.size(); j++)
		{
			outputPosition(81, 12 + i * 2);
			std::cout << allEvents[i].period[j].tm_mday << " " << allEvents[i].period[j].tm_mon + 1 << " " << allEvents[i].period[j].tm_year + 1900;
		}
	}
	int key;
	key = _getch();
	if (key == (int)ARROW_KEYS::KEY_ENTER)
	{
		system("CLS");
		printClosedBook();
		prinyBookDecorations();
		printSnakeSword();
		printTeamLogo();
		return;
	}
}

/**
 * @brief Function for choosing the way of sorting the events by title
 * @param eventManager Variable for an event manager
*/
void chooseTitleSorting(EventManager* eventManager)
{
	printFullyOpenedBook();
	outputPosition(81, 10);
	std::cout << "How do you want to sort the events?" << std::endl;
	int selectedOption = 1;
	char pressedKey = ' ';
	const std::vector<std::string> titleSortingOptions =
	{
		"A -> Z",
		"Z -> A",
	};
	while (pressedKey != (int)ARROW_KEYS::KEY_ENTER)
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
			if (selectedOption == titleSortingOptions.size() + 1)
			{
				selectedOption -= 1;
			}
			break;
		case (int)ARROW_KEYS::KEY_ENTER:
			switch (selectedOption)
			{
			case 1:
				printFullyOpenedBook();
				displayAllEventsByTitle(eventManager, 1);
				break;
			case 2:
				printFullyOpenedBook();
				displayAllEventsByTitle(eventManager, 2);
				break;
			}
		}
	}
}

/**
 * @brief Function for choosing the way of sorting the events by year
 * @param eventManager Variable for an event manager
*/
void chooseYearSorting(EventManager* eventManager)
{
	printFullyOpenedBook();
	outputPosition(81, 10);
	std::cout << "How do you want to sort the events?" << std::endl;
	int selectedOption = 1;
	char pressedKey = ' ';
	const std::vector<std::string> yåarSortingOptions =
	{
		"Ascending",
		"Descending"
	};
	while (pressedKey != (int)ARROW_KEYS::KEY_ENTER)
	{
		for (int i = 0; i < yåarSortingOptions.size(); i++)
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
			std::cout << yåarSortingOptions[i] << std::endl << std::endl;
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
			if (selectedOption == yåarSortingOptions.size() + 1)
			{
				selectedOption -= 1;
			}
			break;
		case (int)ARROW_KEYS::KEY_ENTER:
			switch (selectedOption)
			{
			case 1:
				printFullyOpenedBook();
				displayAllEventsByYear(eventManager, 1);
				break;
			case 2:
				printFullyOpenedBook();
				displayAllEventsByYear(eventManager, 2);
				break;
			}
		}
	}
}

/**
 * @brief Function for choosing the type of printing the events
 * @param eventManager Variable for an event manager
*/
void printBy(EventManager* eventManager)
{
	outputPosition(81, 10);
	std::cout << "How do you want to see the events?" << std::endl;
	int selectedOption = 1;
	char pressedKey = ' ';
	const std::vector<std::string> printByOptions =
	{
		"By title",
		"By year, month and day",
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
				chooseTitleSorting(eventManager);
				break;
			case 2:
				printFullyOpenedBook();
				chooseYearSorting(eventManager);
				break;
			}
		}
	}
}

/**
 * @brief Function for choosing the way of printing the events
 * @param eventManager Variable for an event manager
*/
void displayEvents(EventManager* eventManager)
{
	outputPosition(81, 10);
	std::cout << "How you want to display the events?" << std::endl;
	int selectedOption = 1;
	char pressedKey = ' ';
	const std::vector<std::string> visualizationOptions =
	{
		"As a map",
		"As a timeline",
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
				displayAllEventsByTitle(eventManager, 1);
				break;
			case 2:
				printFullyOpenedBook();
				displayAllEventsByTitle(eventManager, 2);
				break;
			case 3:
				printFullyOpenedBook();
				printBy(eventManager);
				break;
			}
		}
	}
}

/**
 * @brief Function for coloring hovered options
 * @param eventManager Variable for an event manager
 * @param key The pressed button
 * @param selectedOption The selected option
 * @param possibleOptions The possible options
*/
void switchMenuOptions(EventManager* eventManager, char key, int& selectedOption, std::vector<std::string> possibleOptions)
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
		switch (selectedOption)
		{
		case 1:
			system("CLS");
			bookOpeningAnimation();
			addEvent(eventManager);
			break;
		case 2:
			system("CLS");
			bookOpeningAnimation();
			deleteEvent(eventManager);
			break;
		case 4:
			system("CLS");
			bookOpeningAnimation();
			displayEvents(eventManager);
			break;
		case 7:
			system("CLS");
			exit(0);
			break;
		}
	}

}