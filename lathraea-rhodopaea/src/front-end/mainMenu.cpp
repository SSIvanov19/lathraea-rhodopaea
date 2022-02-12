#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
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
	system("CLS");
	std::string title;
	std::cout << "Enter the title of the event you want to add: " << std::endl;
	std::cin.ignore(INT_MAX, '\n');
	getline(std::cin, title);

	while (title.empty())
	{
		std::cout << "Title can not be empty, please enter again: ";
		getline(std::cin, title);
	}

	system("CLS");
	std::string period;
	std::cout << "Enter the starting and ending year and date - ex.(20 apr 1876, 15 may 1876)";
	getline(std::cin, period);

	while (!checkDatesValidation(period))
	{
		std::cout << "The data you've entered is incorrect, please enter a date/s - ex(24 apr 2004, 27 apr 2005)";
		getline(std::cin, period);
	}
	separateDates(period);

	system("CLS");
	int x = 0, y = 0;
	std::cout << "Enter X coordinates of the event: ";
	std::cin >> x;
	std::cout << "Enter Y coordinates of the event: ";
	std::cin >> y;
	Coordinates coordinates{ x, y };

	system("CLS");
	std::string additionalNotes;
	std::cout << "Enter some additional notes for the event, if any: ";
	std::cin.ignore(INT_MAX, '\n');
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
	std::cin.ignore(INT_MAX, '\n');
	getline(std::cin, title);

	while (title.empty())
	{
		outputPosition(81, 12);
		std::cout << "Title can not be empty, please enter again: ";
		outputPosition(81, 13);
		getline(std::cin, title);
	}
	printFullyOpenedBook();
	std::string period;
	outputPosition(81, 10);
	std::cout << "Enter the starting and ending year and date";
	outputPosition(81, 12);
	std::cout << "Example - (20 apr 1876, 15 may 1876)";
	outputPosition(81, 13);
	getline(std::cin, period);

	while (!checkDatesValidation(period))
	{
		outputPosition(81, 14);
		std::cout << "The data you've entered is incorrect!";
		outputPosition(81, 15);
		std::cout << "Please enter a date/s - ex(24 apr 809, 27 apr 810)";
		outputPosition(81, 16);
		getline(std::cin, period);
	}
	separateDates(period);

	printFullyOpenedBook();
	printMapPopUp();
	printBulgarianMap();
	int x = 56, y = 20;
	char key;
	std::cout << char(254);
	key = _getch();
	switch (key)
	{
	case (char)ARROW_KEYS::KEY_UP:
		outputPosition(x, y);
		std::cout << " ";
		outputPosition(x, y - 1);
		std::cout << char(256);
		break;
	case (char)ARROW_KEYS::KEY_DOWN:
		outputPosition(x, y);
		std::cout << " ";
		outputPosition(x, y + 1);
		break;
	case (char)ARROW_KEYS::KEY_LEFT:
		outputPosition(x, y);
		std::cout << " ";
		outputPosition(x - 1, y);
		break;
	case (char)ARROW_KEYS::KEY_RIGHT:
		outputPosition(x, y);
		std::cout << " ";
		outputPosition(x + 1, y);
		break;
	case (char)ARROW_KEYS::KEY_ENTER:		
		printFullyOpenedBook();
		break;
	}
	Coordinates coordinates{ x, y };

	std::string organizers;
	outputPosition(81, 10);
	std::cout << "Enter the organizers of the event you want to add: ";
	outputPosition(81, 11);
	getline(std::cin, organizers);

	while (organizers.empty())
	{
		outputPosition(81, 12);
		std::cout << "Organizers can not be empty, please enter again: ";
		outputPosition(81, 13);
		getline(std::cin, organizers);
	}

	std::vector<std::string> organizersV;
	organizersV.push_back(organizers);

	system("CLS");
	bool isItSuccessful;
	std::cout << "Enter 1 if the event is successful and 0 if it is unsuccessful: ";
	std::cin >> isItSuccessful;

	system("CLS");
	int numberOfRebelions;
	std::cout << "Enter the number of rebilions of the event: ";
	std::cin >> numberOfRebelions;

	system("CLS");
	std::string additionalNotes;
	std::cout << "Enter some additional notes for the event, if any: ";
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
	system("CLS");
	std::string title;
	std::cout << "Enter the title of the event you want to add: " << std::endl;
	std::cin.ignore(INT_MAX, '\n');
	getline(std::cin, title);

	while (title.empty())
	{
		std::cout << "Title can not be empty, please enter again: ";
		getline(std::cin, title);
	}

	system("CLS");
	std::string period;
	std::cout << "Enter the starting and ending year and date - ex.(20 apr 1876, 15 may 1876)";
	getline(std::cin, period);

	while (!checkDatesValidation(period))
	{
		std::cout << "The data you've entered is incorrect, please enter a date/s - ex(24 apr 2004, 27 apr 2005)";
		getline(std::cin, period);
	}
	separateDates(period);

	system("CLS");
	int x = 0, y = 0;
	std::cout << "Enter X coordinates of the event: ";
	std::cin >> x;
	std::cout << "Enter Y coordinates of the event: ";
	std::cin >> y;
	Coordinates coordinates{ x, y };

	system("CLS");
	std::string participatingCountries;
	std::cout << "Enter the countries participating in the event you want to add: ";
	std::cin.ignore(INT_MAX, '\n');
	getline(std::cin, participatingCountries);

	while (participatingCountries.empty())
	{
		std::cout << "ParticipatingCountries can not be empty, please enter again: ";
		getline(std::cin, participatingCountries);
	}

	std::vector<std::string> participatingCountriesV;
	participatingCountriesV.push_back(participatingCountries);

	system("CLS");
	std::string winner;
	std::cout << "Enter the winner of the event you want to add: " << std::endl;
	getline(std::cin, winner);

	while (winner.empty())
	{
		std::cout << "Winner can not be empty, please enter again: ";
		getline(std::cin, winner);
	}

	system("CLS");
	std::string reasons;
	std::cout << "Enter the reason that led to the event: " << std::endl;
	std::cin.ignore(INT_MAX, '\n');
	getline(std::cin, reasons);

	while (reasons.empty())
	{
		std::cout << "Reasons can not be empty, please enter again: ";
		getline(std::cin, reasons);
	}

	system("CLS");
	std::string rulers;
	std::cout << "Enter the rulers of the event you want to add: ";
	std::cin.ignore(INT_MAX, '\n');
	getline(std::cin, rulers);

	while (rulers.empty())
	{
		std::cout << "Rulers can not be empty, please enter again: ";
		getline(std::cin, rulers);
	}

	std::vector<std::string> rulersV;
	rulersV.push_back(rulers);

	system("CLS");
	std::string additionalNotes;
	std::cout << "Enter some additional notes for the event, if any: ";
	std::cin.ignore(INT_MAX, '\n');
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
	system("CLS");
	std::string title;
	std::cout << "Enter the title of the event you want to add: " << std::endl;
	std::cin.ignore(INT_MAX, '\n');
	getline(std::cin, title);

	while (title.empty())
	{
		std::cout << "Title can not be empty, please enter again: ";
		getline(std::cin, title);
	}

	system("CLS");
	std::string period;
	std::cout << "Enter the starting and ending year and date - ex.(20 apr 1876, 15 may 1876)";
	getline(std::cin, period);

	while (period.empty())
	{
		std::cout << "Date can not be empty, please enter again: ";
		getline(std::cin, period);
	}

	while (!checkDatesValidation(period))
	{
		std::cout << "The data you've entered is incorrect, please enter a date/s - ex(24 apr 2004, 27 apr 2005)";
		getline(std::cin, period);
	}

	separateDates(period);

	system("CLS");
	int x = 0, y = 0;
	std::cout << "Enter X coordinates of the event: ";
	std::cin >> x;

	std::cout << "Enter Y coordinates of the event: ";
	std::cin >> y;
	Coordinates coordinates{ x, y };

	system("CLS");
	std::string howItStarted;
	std::cout << "Enter the way the event started: " << std::endl;
	getline(std::cin, howItStarted);

	while (howItStarted.empty())
	{
		std::cout << "The way it started can not be empty, please enter again: ";
		getline(std::cin, howItStarted);
	}

	system("CLS");
	std::string ideas;
	std::cout << "Enter ideas of the event you want to add: " << std::endl;
	std::cin.ignore(INT_MAX, '\n');
	getline(std::cin, ideas);

	while (ideas.empty())
	{
		std::cout << "The ideas can not be empty, please enter again: ";
		getline(std::cin, ideas);
	}

	system("CLS");
	std::string aims;
	std::cout << "Enter the aims of the event you want to add: " << std::endl;
	std::cin.ignore(INT_MAX, '\n');
	getline(std::cin, aims);

	while (aims.empty())
	{
		std::cout << "The aims can not be empty, please enter again: ";
		getline(std::cin, aims);
	}

	system("CLS");
	std::string representatives;
	std::cout << "Enter the representatives of the event you want to add: ";
	std::cin.ignore(INT_MAX, '\n');
	getline(std::cin, representatives);

	while (representatives.empty())
	{
		std::cout << "The representatives can not be empty, please enter again: ";
		getline(std::cin, representatives);
	}

	std::vector<std::string> representativesV;
	representativesV.push_back(representatives);

	system("CLS");
	std::string additionalNotes;
	std::cout << "Enter some additional notes for the event, if any: ";
	std::cin.ignore(INT_MAX, '\n');
	getline(std::cin, additionalNotes);

	system("CLS");
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
	std::vector<std::string> eventTypeOptions = {
		"Uprising",
		"War",
		"Movement",
		"Other"
	};

	int selectedOption = 1;
	char pressedKey;

	while (selectedOption)
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
	}
}

/**
 * @brief Function for deleting historical events
 * @param eventManager Variable for an event manager
*/
void deleteEvent(EventManager* eventManager)
{
	system("CLS");
	std::string title;
	std::cout << "Enter the title of the event you want to remove: ";
	getline(std::cin, title);

	if (eventManager->removeEvent(&eventManager->eventList, title))
	{
		std::cout << "You've successfully deleted the event!";
	}
	else
	{
		std::cout << "The event wasn't deleted";
	}

	if (_getch())
	{
		system("CLS");
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
			bookOpeningAnimation();
			addEvent(eventManager);
			break;
		case 2: deleteEvent(eventManager);
			break;
		case 7:
			system("CLS");
			exit(0);
			break;
		}
	}

}