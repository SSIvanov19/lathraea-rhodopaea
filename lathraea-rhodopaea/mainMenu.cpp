#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <conio.h>
#include <front-end/output.h>

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
void addEvent(int& selectedOption)
{
	struct addEvent
	{
		std::string title;
		std::string period;
		std::string coordinates;
		std::string participatingCountries;
		std::string winner;
		std::string reasons;
		std::string rulers;
		std::string additionalNotes;
	};
	if (selectedOption == 1)
	{
		system("CLS");
		addEvent currentEvent;
		std::cout << "Enter the title of the event you want to add: ";
		getline(std::cin, currentEvent.title);
		system("CLS");
		std::cout << "Enter the duration of the event: ";
		getline(std::cin, currentEvent.period);
		system("CLS");
		std::cout << "Enter the location where the event took place: ";
		getline(std::cin, currentEvent.coordinates);
		system("CLS");
		std::cout << "Enter the winner of the event: ";
		getline(std::cin, currentEvent.winner);
		system("CLS");
		std::cout << "Enter the reasons why the event took place: ";
		getline(std::cin, currentEvent.reasons);
		system("CLS");
		std::cout << "Enter the event leader/s: ";
		getline(std::cin, currentEvent.rulers);
		system("CLS");
		std::cout << "Enter some additional notes for the event, if any: ";
		getline(std::cin, currentEvent.additionalNotes);
		system("CLS");
		std::cout << "Your event has been saved successfully!" << std::endl << "Press any key to go back";

		if (_getch())
		{
			system("CLS");
		}
	}
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
		// TO DO - CONNECT BACK-END TO FORNT-END
		addEvent(selectedOption);
	}
	// TO DO - ADD THE OTHER OPTIONS
}

int main()
{
	std::vector<std::string> loginOptions =
	{
		"Login",
		"Register"
	};

	std::vector<std::string> menuOptions =
	{
		"Add historical event",
		"Delete historical event",
		"Edit historical events",
		"Visualize added events",
		"Connect events",
		"About us",
		"Exit"
	};

	std::vector<std::string> visualizationOptions =
	{
		"As a map",
		"As a timeline",
		"As an encyclopedia"
	};

	char pressedKey;
	int selectedOption = 1;

	while (selectedOption)
	{
		outputOptions(menuOptions, selectedOption);
		pressedKey = _getch();
		hoverMenuOptions(pressedKey, selectedOption, menuOptions);
	}

}
