#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <conio.h>
#include <front-end/output.h>
#include <back-end/eventManager.h>
#include <back-end/datetimeManager.h>

/**
 * @brief Enumeration representing the color codes
*/
enum COLORS : int
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
enum ARROW_KEYS : int
{
	KEY_UP = 72,
	KEY_DOWN = 80,
	KEY_LEFT = 77,
	KEY_RIGHT = 75,
	KEY_ENTER = '\r'
};

/**
 * @brief Function for printing the main menu options
 * @param possibleOptions
 * @param selectedOption
*/
void outputOptions(std::vector<std::string> possibleOptions, int& selectedOption)
{
	for (int i = 0; i < possibleOptions.size(); i++)
	{
		try
		{
			if (i + 1 == selectedOption)
			{
				throw(selectedOption);
			}
			else
			{
				color(COLORS::GRAY);
			}

		}
		catch (int option)
		{
			color(COLORS::RED);
		}
		outputPosition(1, i + i + 1);
		std::cout << " -> " << possibleOptions[i] << std::endl << std::endl;
	}
}

/**
 * @brief Function for adding historical events
 * @param selectedOption
*/
void addEvent()
{
	system("CLS");
	std::cout << "Eneter the type of event yopu want to add!" << std::endl << "Enter 1 for an uprising, enter 2 for a war, enter 3 for a movement: ";
	int type = 0;

	// TO DO - FIX ROW 85
	/*while (type != 1 && type != 2 && type != 3)
	{*/
	/*
		std::cin >> type;
		switch (type)
		{
		case 1: addUprisingEvent();
			break;
		case 2: addWarEvent();
			break;
		case 3: addMovementEvent();
			break;
		/*default:
		std::cout << "Please enter a number between 1 and 3!";
		}
    }*/

	if (_getch())
	{
		system("CLS");
	}
}

/**
 * @brief Function for adding events of type "uprising"
*/
void addUprisingEvent()
{
	EventManager EventMenager;

	system("CLS");
	std::string title;
	std::cout << "Enter the title of the event you want to add: " << std::endl;
	getline(std::cin, title);

	system("CLS");
	std::string period;
	std::cout << "Enter the starting and ending year and date - ex.(20 apr 1876, 15 may 1876)";
	getline(std::cin, period);
	std::vector<std::string> periodV;
	periodV.push_back(period);

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
	std::cout << "Enter true if the event is successful and false if it is unsuccessful: ";
	std::cin >> isItSuccessful;

	system("CLS");
	int numberOfRebelions;
	std::cout << "Enter the number of rebilions of the event: ";
	std::cin >> numberOfRebelions;

	system("CLS");
	std::string additionalNotes;
	std::cout << "Enter some additional notes for the event, if any: ";
	getline(std::cin, additionalNotes);

	EventMenager.addUprisingEvent(title, periodV, coordinates, organizersV, isItSuccessful, numberOfRebelions, additionalNotes);
}

/**
 * @brief Function for adding events of type "war"
*/
void addWarEvent()
{
	EventManager EventMenager;

	system("CLS");
	std::string title;
	std::cout << "Enter the title of the event you want to add: " << std::endl;
	getline(std::cin, title);

	system("CLS");
	std::string period;
	std::cout << "Enter the starting and ending year and date - ex.(20 apr 1876, 15 may 1876)";
	getline(std::cin, period);
	std::vector<std::string> periodV;
	periodV.push_back(period);

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
	getline(std::cin, additionalNotes);

	EventMenager.addWarEvent(title, periodV, coordinates, participatingCountriesV, winner, reasons, rulersV, additionalNotes);
}

/**
 * @brief Function for adding events of type "movement"
*/
void addMovementEvent()
{
	EventManager EventMenager;

	system("CLS");
	std::string title;
	std::cout << "Enter the title of the event you want to add: " << std::endl;
	getline(std::cin, title);

	system("CLS");
	std::string period;
	std::cout << "Enter the starting and ending year and date - ex.(20 apr 1876, 15 may 1876)";
	getline(std::cin, period);
	std::vector<std::string> periodV;
	periodV.push_back(period);

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
	getline(std::cin, additionalNotes);

	EventMenager.addMovementEvent(title, periodV, coordinates, howItStarted, ideas, aims, representativesV, additionalNotes);
}

void deleteEvent()
{
	/*EventManager EventMenager;
	std::string title;
	std::cout << "Enter the title of the event you want to remove";
	getline(std::cin, title);
	EventMenager.removeEvent(EventManager, title);*/
}

/**
 * @brief Function for coloring hovered options
 * @param key
 * @param selectedOption
 * @param possibleOptions
*/
void hoverMenuOptions(char key, int& selectedOption, std::vector<std::string> possibleOptions)
{
	switch (key)
	{
	case ARROW_KEYS::KEY_UP:
		selectedOption--;
		if (selectedOption == 0)
		{
			selectedOption += 1;
		}
		break;

	case ARROW_KEYS::KEY_DOWN:
		selectedOption++;
		if (selectedOption == possibleOptions.size() + 1)
		{
			selectedOption -= 1;
		}
	case ARROW_KEYS::KEY_ENTER:
		switch (selectedOption)
		{
		case 1: addEvent();
		case 2: deleteEvent();
		}

	}
	// TO DO - ADD THE OTHER OPTIONS
}

//int main()
//{
//	std::vector<std::string> loginOptions =
//	{
//		"Login",
//		"Register"
//	};
//
//	std::vector<std::string> menuOptions =
//	{
//		"Add historical event",
//		"Remove historical event",
//		"Edit historical events",
//		"Visualize added events",
//		"Connect events",
//		"About us",
//		"Exit"
//	};
//
//	std::vector<std::string> visualizationOptions =
//	{
//		"As a map",
//		"As a timeline",
//		"As an encyclopedia"
//	};
//
//	char pressedKey;
//	int selectedOption = 1;
//
//	while (selectedOption)
//	{
//		outputOptions(menuOptions, selectedOption);
//		pressedKey = _getch();
//		hoverMenuOptions(pressedKey, selectedOption, menuOptions);
//	}
//
//}
