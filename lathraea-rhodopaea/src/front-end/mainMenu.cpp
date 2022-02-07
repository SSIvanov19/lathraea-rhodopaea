#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <conio.h>
#include <front-end/output.h>
#include <back-end/eventManager.h>
#include <back-end/datetimeManager.h>
#include <application.h>

/**
 * @brief Enumeration representing the color codes
*/
enum class COLORS : int
{
	DARK_BLUE = 1,
	DARK_GREEN = 2,
	DARK_CYAN = 3,
	DARK_RED = 4,
	DARK_MAGENTA = 5,
	DARK_YELLOW = 6,
	DIRTY_WHITE = 7,
	GRAY = 8,
	BLUE = 9,
	GREEN = 10,
	CYAN = 11,
	RED = 12,
	MAGENTA = 13,
	YELLOW = 14,
	WHITE = 15,
};

/**
 * @brief Enumeration representing the keys' codes
*/
enum class ARROW_KEYS : int
{
	KEY_UP = 72,
	KEY_DOWN = 80,
	KEY_LEFT = 77,
	KEY_RIGHT = 75,
	KEY_ENTER = '\r'
};

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
			color((int)COLORS::RED);
		}
		else
		{
			color((int)COLORS::GRAY);
		}
		outputPosition(1, i + i + 1);
		std::cout << " -> " << possibleOptions[i] << std::endl << std::endl;
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
	if (stoi(day) >= 1 and stoi(day) <= 31)
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

	if (whiteSpaces != 5 and twoDates == 1)
	{
		return false;
	}

	if (whiteSpaces != 2 and twoDates == 0)
	{
		return false;
	}

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

	if (twoDates and !isDayInRange(dayTwo))
	{
		return false;
	}

	if (!isValidMonthName(month) or (!isValidMonthName(monthTwo) and twoDates))
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
 * @brief Function for adding events of type "uprising"
*/
void addUprisingEvent()
{
	EventManager eventMenager; // event menijara da e edin i da sa podava s funkciq

	system("CLS");
	std::string title;
	std::cout << "Enter the title of the event you want to add: " << std::endl;
	std::cin.ignore();
	getline(std::cin, title);

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
	std::string organizers;
	std::cout << "Enter the organizers of the event you want to add: ";
	getline(std::cin, organizers);
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
	std::cin.ignore();
	getline(std::cin, additionalNotes);

	try
	{
		eventMenager.addUprisingEvent(title, separateDates(period), coordinates, organizersV, isItSuccessful, numberOfRebelions, additionalNotes);
	}
	catch (std::string errorMessage)
	{
		std::cout << errorMessage;
	}
}

/**
 * @brief Function for adding events of type "war"
*/
void addWarEvent()
{
	EventManager eventMenager;

	system("CLS");
	std::string title;
	std::cout << "Enter the title of the event you want to add: " << std::endl;
	std::cin.ignore();
	getline(std::cin, title);

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
	getline(std::cin, participatingCountries);
	std::vector<std::string> participatingCountriesV;
	participatingCountriesV.push_back(participatingCountries);

	system("CLS");
	std::string winner;
	std::cout << "Enter the winner of the event you want to add: " << std::endl;
	getline(std::cin, winner);

	system("CLS");
	std::string reasons;
	std::cout << "Enter the reason that led to the event: " << std::endl;
	getline(std::cin, reasons);

	system("CLS");
	std::string rulers;
	std::cout << "Enter the rulers of the event you want to add: ";
	getline(std::cin, rulers);
	std::vector<std::string> rulersV;
	rulersV.push_back(rulers);

	system("CLS");
	std::string additionalNotes;
	std::cout << "Enter some additional notes for the event, if any: ";
	std::cin.ignore();
	getline(std::cin, additionalNotes);

	try
	{
		eventMenager.addWarEvent(title, separateDates(period), coordinates, participatingCountriesV, winner, reasons, rulersV, additionalNotes);
	}
	catch (std::string errorMessage)
	{
		std::cout << errorMessage;
	}
}

/**
 * @brief Function for adding events of type "movement"
*/
void addMovementEvent()
{
	EventManager eventMenager;

	system("CLS");
	std::string title;
	std::cout << "Enter the title of the event you want to add: " << std::endl;
	std::cin.ignore();
	getline(std::cin, title);

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
	std::string howItStarted;
	std::cout << "Enter the way the event started: " << std::endl;
	getline(std::cin, howItStarted);

	system("CLS");
	std::string ideas;
	std::cout << "Enter ideas of the event you want to add: " << std::endl;
	getline(std::cin, ideas);

	system("CLS");
	std::string aims;
	std::cout << "Enter the aims of the event you want to add: " << std::endl;
	getline(std::cin, ideas);

	system("CLS");
	std::string representatives;
	std::cout << "Enter the crepresentatives of the event you want to add: ";
	getline(std::cin, representatives);
	std::vector<std::string> representativesV;
	representativesV.push_back(representatives);

	system("CLS");
	std::string additionalNotes;
	std::cout << "Enter some additional notes for the event, if any: ";
	std::cin.ignore();
	getline(std::cin, additionalNotes);

	system("CLS");
	try
	{
		eventMenager.addMovementEvent(title, separateDates(period), coordinates, howItStarted, ideas, aims, representativesV, additionalNotes);
	}
	catch (std::string errorMessage)
	{
		std::cout << errorMessage;
	}
}

/**
 * @brief Function for adding historical events
*/
void addEvent()
{
	system("CLS");
	std::cout << "Eneter the type of event yopu want to add!" << std::endl << "Enter 1 for an uprising, enter 2 for a war, enter 3 for a movement: ";
	int type = 0;

	while (type != 1 && type != 2 && type != 3)
	{

		std::cin >> type;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');

		switch (type)
		{
		case 1: addUprisingEvent();
			break;
		case 2: addWarEvent();
			break;
		case 3: addMovementEvent();
			break;
		default:
			std::cout << "Please enter a number between 1 and 3!";
		}
	}

	if (_getch())
	{
		system("CLS");
	}
}

/**
 * @brief Function for deleting historical events
*/
void deleteEvent()
{
	system("CLS");
	EventManager eventMenager;
	std::string title;
	std::cout << "Enter the title of the event you want to remove: ";
	getline(std::cin, title);
	eventMenager.removeEvent(&eventMenager.eventList, title);
}

/**
 * @brief Function for coloring hovered options
 * @param key The pressed button
 * @param selectedOption The selected option
 * @param possibleOptions The possible options
*/
void hoverMenuOptions(char key, int& selectedOption, std::vector<std::string> possibleOptions)
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
		case 1: addEvent();
			break;
		case 2: deleteEvent();
			break;
		}

	}
}