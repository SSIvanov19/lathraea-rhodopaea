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
				reverseBookAnimation();
				addUprisingEvent(eventManager);
				break;
			case 2:
				bookAnimation();
				addWarEvent(eventManager);
				break;
			case 3:
				bookAnimation();
				addMovementEvent(eventManager);
				break;
			case 4:
				bookAnimation();
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
	}

	result += " ";

	return result;
}

/**
 * @brief Function for displaying information about a particular event
 * @param e Given event
*/
void displayEvent(const Event& e)
{
	DateManager  dateManager;
	printFullyOpenedBook();
	outputPosition(81, 10);
	std::cout << "Press Enter if you want to go back!";
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
		std::cout << "Epoch: ";
		for (int i = 0; i < e.epochs.size(); i++)
		{
			std::cout << e.epochs[i];
		}
		if (e.period.size() == 2)
		{
			outputPosition(81, 20);
			std::cout << "Start date: " << std::put_time(&e.period[0], "%x") << std::endl;
			outputPosition(81, 22);
			std::cout << "End date: " << std::put_time(&e.period[1], "%x") << std::endl;
			outputPosition(81, 24);
			std::cout << "Duration in days: " << dateManager.getDifference(e.period[0], e.period[1]) << std::endl;
			outputPosition(81, 26);
			std::cout << "Success: ";
			switch (e.isItSuccessful)
			{
			case 0: std::cout << "No";
			case 1: std::cout << "Yes";
			}
			outputPosition(81, 28);
			std::cout << "Number of rebilions: " << e.numberOfRebelions;
			outputPosition(81, 30);
			std::cout << "Additional notes: " << e.additionalNotes;
		}
		else
		{
			outputPosition(81, 20);
			std::cout << "Date: " << std::put_time(&e.period[0], "%x") << std::endl;
			outputPosition(81, 22);
			std::cout << "Success: ";
			switch (e.isItSuccessful)
			{
			case 0: std::cout << "No";
			case 1: std::cout << "Yes";
			}
			outputPosition(81, 24);
			std::cout << "Number of rebilions: " << e.numberOfRebelions;
			outputPosition(81, 26);
			std::cout << "Additional notes: " << e.additionalNotes;
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
		std::cout << "Epoch: ";
		for (int i = 0; i < e.epochs.size(); i++)
		{
			std::cout << e.epochs[i];
		}
		if (e.period.size() == 2)
		{
			outputPosition(81, 20);
			std::cout << "Start date: " << std::put_time(&e.period[0], "%x") << std::endl;
			outputPosition(81, 22);
			std::cout << "End date: " << std::put_time(&e.period[1], "%x") << std::endl;
			outputPosition(81, 24);
			std::cout << "Duration in days: " << dateManager.getDifference(e.period[0], e.period[1]) << std::endl;
			outputPosition(81, 26);
			std::cout << "Participting countries: " << separate(e.participatingCountries);
			outputPosition(81, 28);
			std::cout << "Winner: " << e.winner;
			outputPosition(81, 30);
			std::cout << "Reason " << e.reason;
			outputPosition(81, 32);
			std::cout << "Rulers: " << separate(e.rulers);
			outputPosition(81, 34);
			std::cout << "Additional notes: " << e.additionalNotes;
		}
		else
		{
			outputPosition(81, 20);
			std::cout << "Date: " << std::put_time(&e.period[0], "%x") << std::endl;
			outputPosition(81, 22);
			std::cout << "Participting countries: " << separate(e.participatingCountries);
			outputPosition(81, 24);
			std::cout << "Winner:  " << e.winner;
			outputPosition(81, 26);
			std::cout << "Reason " << e.reason;
			outputPosition(81, 28);
			std::cout << "Rulers: " << separate(e.rulers);
			outputPosition(81, 30);
			std::cout << "Additional notes: " << e.additionalNotes;
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
		std::cout << "Epoch: ";
		for (int i = 0; i < e.epochs.size(); i++)
		{
			std::cout << e.epochs[i];
		}
		if (e.period.size() == 2)
		{
			outputPosition(81, 20);
			std::cout << "Start date: " << std::put_time(&e.period[0], "%x") << std::endl;
			outputPosition(81, 22);
			std::cout << "End date: " << std::put_time(&e.period[1], "%x") << std::endl;
			outputPosition(81, 24);
			std::cout << "Duration in days: " << dateManager.getDifference(e.period[0], e.period[1]) << std::endl;
			outputPosition(81, 26);
			std::cout << "How it started: " << e.howItStarted;
			outputPosition(81, 28);
			std::cout << "Ideas " << e.ideas;
			outputPosition(81, 30);
			std::cout << "Aims " << e.aims;
			outputPosition(81, 32);
			std::cout << "Representatives: " << separate(e.representatives);
			outputPosition(81, 34);
			std::cout << "Additional notes: " << e.additionalNotes;
		}
		else
		{
			outputPosition(81, 20);
			std::cout << "Date: " << std::put_time(&e.period[0], "%x") << std::endl;
			outputPosition(81, 22);
			std::cout << "How it started: " << e.howItStarted;
			outputPosition(81, 24);
			std::cout << "Ideas " << e.ideas;
			outputPosition(81, 26);
			std::cout << "Aims " << e.aims;
			outputPosition(81, 28);
			std::cout << "Representatives: " << separate(e.representatives);
			outputPosition(81, 30);
			std::cout << "Additional notes: " << e.additionalNotes;
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
		std::cout << "Epoch: ";
		for (int i = 0; i < e.epochs.size(); i++)
		{
			std::cout << e.epochs[i];
		}
		if (e.period.size() == 2)
		{
			outputPosition(81, 20);
			std::cout << "Start date: " << std::put_time(&e.period[0], "%x") << std::endl;
			outputPosition(81, 22);
			std::cout << "End date: " << std::put_time(&e.period[1], "%x") << std::endl;
			outputPosition(81, 24);
			std::cout << "Duration in days: " << dateManager.getDifference(e.period[0], e.period[1]) << std::endl;
			outputPosition(81, 26);
			std::cout << "Additional notes: " << e.additionalNotes;
		}
		else
		{
			outputPosition(81, 20);
			std::cout << "Date: " << std::put_time(&e.period[0], "%x") << std::endl;
			outputPosition(81, 22);
			std::cout << "Additional notes: " << e.additionalNotes;
		}

		break;
	}

	_getch();
	system("CLS");
	printClosedBook();
	prinyBookDecorations();
	printSnakeSword();
	printTeamLogo();
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
void displayAllEvents(EventManager* eventManager, int sorting, int& type)
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
void chooseSorting(EventManager* eventManager, int type)
{
	printFullyOpenedBook();
	outputPosition(81, 10);
	std::cout << "How do you want to sort the events?" << std::endl;
	int selectedOption = 1;
	char pressedKey = ' ';
	const std::vector<std::string> yåarSortingOptions =
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
				displayAllEvents(eventManager, 1, type);
				break;
			case 2:
				printFullyOpenedBook();
				displayAllEvents(eventManager, 2, type);
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
				chooseSorting(eventManager, 1);
				break;
			case 2:
				printFullyOpenedBook();
				chooseSorting(eventManager, 2);
				break;
			case 3:
				printFullyOpenedBook();
				chooseSorting(eventManager, 3);
				break;
			}
		}
	}
}

/**
 * @brief Function for printing event coordinates on map
 * @param eventManager Variable for an event manager
*/
void printAsMap(EventManager* eventManager)
{
	std::vector<Event> allEvents = eventManager->getAllEvents(0);
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
			_getch();
			system("CLS");
			printClosedBook();
			prinyBookDecorations();
			printSnakeSword();
			printTeamLogo();
		}
	}
}

void editEvent(EventManager* eventManager)
{
	std::vector<Event> allEvents = eventManager->getAllEvents(0);
	int selectedOption = 1;
	char pressedKey = ' ';
	outputPosition(81, 10);
	std::cout << "Choose the event you want to edit!";
	while (pressedKey != (int)ARROW_KEYS::KEY_ENTER)
	{
		for (int i = 0; i < allEvents.size(); i++)
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

			for (int j = 0; j < allEvents[i].period.size(); j++)
			{
				outputPosition(84, 12 + i * 2);
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
			if ((allEvents[selectedOption - 1].type == TypeOfEvent::UPRISING))
			{
				printFullyOpenedBook();
				outputPosition(81, 10);
				std::cout << "What do you want to edit?";
				int selectedOption1 = 1;
				char pressedKey1 = ' ';

				while (pressedKey1 != (int)ARROW_KEYS::KEY_ENTER)
				{
					for (int i = 0; i < allEvents.size(); i++)
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
						if (selectedOption1 == allEvents.size() + 1)
						{
							selectedOption1 -= 1;
						}
						break;
					case (int)ARROW_KEYS::KEY_ENTER:
						break;
					}
				}
			}
			else if ((allEvents[selectedOption - 1].type == TypeOfEvent::WAR))
			{
				printFullyOpenedBook();
				outputPosition(81, 10);
				std::cout << "What do you want to edit?";
				int selectedOption1 = 1;
				char pressedKey1 = ' ';

				while (pressedKey1 != (int)ARROW_KEYS::KEY_ENTER)
				{
					for (int i = 0; i < allEvents.size(); i++)
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
						if (selectedOption1 == allEvents.size() + 1)
						{
							selectedOption1 -= 1;
						}
						break;
					case (int)ARROW_KEYS::KEY_ENTER:
						break;
					}
				}
			}
			else if ((allEvents[selectedOption - 1].type == TypeOfEvent::MOVEMENT))
			{
				printFullyOpenedBook();
				outputPosition(81, 10);
				std::cout << "What do you want to edit?";
				int selectedOption1 = 1;
				char pressedKey1 = ' ';

				while (pressedKey1 != (int)ARROW_KEYS::KEY_ENTER)
				{
					for (int i = 0; i < allEvents.size(); i++)
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
						if (selectedOption1 == allEvents.size() + 1)
						{
							selectedOption1 -= 1;
						}
						break;
					case (int)ARROW_KEYS::KEY_ENTER:
						break;
					}
				}
			}
			else if ((allEvents[selectedOption - 1].type == TypeOfEvent::OTHER))
			{
				printFullyOpenedBook();
				outputPosition(81, 10);
				std::cout << "What do you want to edit?";
				int selectedOption1 = 1;
				char pressedKey1 = ' ';

				while (pressedKey1 != (int)ARROW_KEYS::KEY_ENTER)
				{
					for (int i = 0; i < allEvents.size(); i++)
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
						std::cout << otherOptions[i];

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
						if (selectedOption1 == allEvents.size() + 1)
						{
							selectedOption1 -= 1;
						}
						break;
					case (int)ARROW_KEYS::KEY_ENTER:
						break;
					}
				}
			}
			printMapPopUp();
			printBulgarianMap();
			outputPosition((allEvents[selectedOption - 1].coordinates.X), (allEvents[selectedOption - 1].coordinates.Y));
			std::cout << char(254);
			_getch();
			system("CLS");
			printClosedBook();
			prinyBookDecorations();
			printSnakeSword();
			printTeamLogo();
		}
	}
}
/**
 * @brief Function for printing events as a timeline
 * @param storylineManager Variable for an storyline manager
*/
void printAsTimeline(StorylineManager* storylineManager)
{
	std::vector<Storyline> allEvents = storylineManager->getAllStorylines(0);
	EventManager ev;

	for (size_t i = 0; i < allEvents.size(); i++)
	{
		allEvents[i].events = ev.sortAndGetAllEventsByTimeOfCreation(allEvents[i].events);
	}

	if (allEvents.empty())
	{
		outputPosition(81, 10);
		std::cout << "There are no events to display";
		outputPosition(81, 12);
		std::cout << "Press Enter to go back!";
	}
	else
	{
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
				outputPosition(84, 10 + i * 2);
				std::cout << allEvents[i].title << std::endl;
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
				printSwordTimelinePopUp();
				printSwordTimeline();
				for (size_t i = 0; i < allEvents[selectedOption - 1].events.size(); i++)
				{
					switch (i)
					{
					case 0:
						outputPosition(55, 20);
						break;
					case 1:
						outputPosition(63, 27);
						break;
					case 2:
						outputPosition(71, 20);
						break;
					case 3:
						outputPosition(79, 27);
						break;
					case 4:
						outputPosition(87, 20);
						break;
					case 5:
						outputPosition(95, 27);
						break;
					}
					std::cout << allEvents[selectedOption - 1].events[i].period[0].tm_year + 1900;
				}
			}
		}
	}
	_getch();
	system("CLS");
	printClosedBook();
	prinyBookDecorations();
	printSnakeSword();
	printTeamLogo();
}

/**
 * @brief Function for choosing the way of printing the events
 * @param eventManager Variable for an event manager
*/
void displayEvents(EventManager* eventManager, StorylineManager* storylineManager)
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
				printAsMap(eventManager);
				break;
			case 2:
				printFullyOpenedBook();
				printAsTimeline(storylineManager);
				break;
			case 3:
				printFullyOpenedBook();
				printBy(eventManager);
				break;
			}
		}
	}
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

void createStoryline(EventManager* eventManager, StorylineManager* storylineManager, bool getEvents = false)
{
	std::vector<Event> events = eventManager->getAllEvents(false);
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
		createStoryline(eventManager, storylineManager);
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
		createStoryline(eventManager, storylineManager);
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

			try
			{
				storylineManager->addStoryline(title, storylineEvents, desc);
				indexSelectedEvents.clear();
				selectedOptions = 0;
				system("CLS");
				printClosedBook();
				prinyBookDecorations();
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

				createStoryline(eventManager, storylineManager);
			}
		}

		createStoryline(eventManager, storylineManager);
		break;
	case (int)ARROW_KEYS::KEY_ESC:
		indexSelectedEvents.clear();
		selectedOptions = 0;
		system("CLS");
		printClosedBook();
		prinyBookDecorations();
		printSnakeSword();
		printTeamLogo();
		return;
	default:
		createStoryline(eventManager, storylineManager);
	}
}

/**
 * @brief Function for coloring hovered options
 * @param eventManager Variable for an event manager
 * @param key The pressed button
 * @param selectedOption The selected option
 * @param possibleOptions The possible options
*/
void switchMenuOptions(EventManager* eventManager, StorylineManager* storylineManager, char key, int& selectedOption, std::vector<std::string> possibleOptions)
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
		case 3:
			system("CLS");
			bookOpeningAnimation();
			editEvent(eventManager);
			break;
		case 4:
			system("CLS");
			bookOpeningAnimation();
			displayEvents(eventManager, storylineManager);
			break;
		case 5:
			system("CLS");
			bookOpeningAnimation();
			createStoryline(eventManager, storylineManager, true);
			break;
		case 6:
			system("CLS");
			printaboutUs();
			printText();
			_getch();
			system("CLS");
			printClosedBook();
			prinyBookDecorations();
			printSnakeSword();
			printTeamLogo();
			break;
		case 7:
			system("CLS");
			exit(0);
			break;
		}
	}

}