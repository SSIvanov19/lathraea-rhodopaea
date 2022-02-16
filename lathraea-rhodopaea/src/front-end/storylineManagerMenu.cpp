/*! @file storylineManagerMenu.cpp
*   @brief A source file for the storyline menu handaling system.
*/

#include <front-end/storylineManagerMenu.h>
#include <front-end/enumerations.h>
#include <front-end/graphics.h>
#include <front-end/output.h>

/**
 * @brief Helper function for counting elements from vector
 * @param v The vector
 * @return The number of "1" in the vector
*/
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

void createStoryline(
	EventManager* eventManager,
	StorylineManager* storylineManager,
	AccountManager* accountManager,
	bool getEvents
)
{
	std::vector<Event> events = eventManager->getAllEvents(true);
	if (accountManager->isAdmin())
	{
		std::vector<Event> eventsForApproving = eventManager->getAllEvents(false);
		events.insert(
			events.end(),
			eventsForApproving.begin(),
			eventsForApproving.end()
		);
	}

	if (events.empty())
	{
		outputPosition(81, 10);
		std::cout << "There are no events to add to storyline";
		outputPosition(81, 12);
		std::cout << "Press Enter to go back!";
		(void)_getch();
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
		outputPosition(81, 12 + int(i));
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

	outputPosition(81, 12 + int(events.size()));

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
					outputPosition(81, 13 + int(events.size()));
					std::cout << "                                                  ";
				}
				else
				{
					outputPosition(81, 13 + int(events.size()));
					std::cout << "Can not add more than 6 events to single storyline";
				}
			}
			else
			{
				outputPosition(81, 13 + int(events.size()));
				std::cout << "                                                  ";
				indexSelectedEvents[selectedOptions] = !indexSelectedEvents[selectedOptions];
			}
		}
		else
		{
			outputPosition(81, 13 + int(events.size()));
			std::cout << "                                                  ";

			std::string title;
			outputPosition(81, 13 + int(events.size()));
			std::cout << "Please, enter title for the new storyline";
			outputPosition(81, 14 + int(events.size()));
			getline(std::cin, title);

			while (title.empty())
			{
				outputPosition(81, 13 + int(events.size()));
				std::cout << "Please, enter title for the new storyline";
				outputPosition(81, 14 + int(events.size()));
				getline(std::cin, title);
			}

			std::string desc;
			outputPosition(81, 15 + int(events.size()));
			std::cout << "Please, enter description for the new storyline";
			outputPosition(81, 16 + int(events.size()));
			getline(std::cin, desc);

			std::vector<Event> storylineEvents;

			for (size_t i = 0; i < indexSelectedEvents.size(); i++)
			{
				if (indexSelectedEvents[i])
				{
					storylineEvents.push_back(events[i]);
				}
			}

			storylineEvents = eventManager->sortAndGetAllEventsByDate(
				storylineEvents
			);

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
				outputPosition(81, 17 + int(events.size()));
				std::cout << error;
				(void)_getch();
				outputPosition(81, 13 + int(events.size()));
				for (int i = 0; i < 10; i++)
				{
					std::cout << "                                                  ";
					outputPosition(81, int(13 + events.size() + i));
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

void approveStoryline(StorylineManager* storylineManager)
{
	std::vector<Storyline> storylines = storylineManager->getAllStorylines(false);

	if (storylines.empty())
	{
		outputPosition(81, 10);
		std::cout << "There are no storylines to display";
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
				storylineManager->approveStoryline(storylines[__int64(selectedOption) - 1].title);
				return;
			}
			catch (std::string msg)
			{
				outputPosition(81, 18);
				std::cout << "There was problem approving the storyline:";
				outputPosition(81, 19);
				std::cout << msg;
				outputPosition(81, 20);
				std::cout << "Please try again!";
				(void)_getch();
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

void deleteStoryline(StorylineManager* storylineManager)
{
	std::vector<Storyline> approveStorylines = storylineManager->getAllStorylines(1);
	std::vector<Storyline> unApproveStorylines = storylineManager->getAllStorylines(0);

	approveStorylines.insert(
		approveStorylines.end(),
		unApproveStorylines.begin(),
		unApproveStorylines.end()
	);

	if (approveStorylines.empty())
	{
		outputPosition(81, 10);
		std::cout << "There are no storylines to display";
		outputPosition(81, 12);
		std::cout << "Press Enter to go back!";
		(void)_getch();
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
			if (!storylineManager->removeStoryline(
				&storylineManager->storylineList, 
				approveStorylines[__int64(selectedOption) - 1].title
			))
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

void printStorylineOnMap(StorylineManager* storylineManager, bool getAllEvents)
{
	std::vector<Storyline> allStorylines = storylineManager->getAllStorylines(true);
	if (getAllEvents)
	{
		std::vector<Storyline> unApproveStorylines = storylineManager->getAllStorylines(false);
		allStorylines.insert(
			allStorylines.end(),
			unApproveStorylines.begin(),
			unApproveStorylines.end()
		);
	}

	if (allStorylines.empty())
	{
		outputPosition(81, 10);
		std::cout << "There are no storylines to display";
		outputPosition(81, 12);
		std::cout << "Press Enter to go back!";
		(void)_getch();
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
				for (size_t i = 0; i < allStorylines[__int64(selectedOption) - 1].events.size(); i++)
				{
					size_t middlePos = allStorylines[__int64(selectedOption) - 1].events[i].title.size() / 2;

					outputPosition(
						int(allStorylines[__int64(selectedOption) - 1].events[i].coordinates.X - middlePos),
						int(allStorylines[__int64(selectedOption) - 1].events[i].coordinates.Y - 1)
					);
					ShowCursor(true);
					std::cout << allStorylines[__int64(selectedOption) - 1].events[i].title;

					outputPosition(
						allStorylines[__int64(selectedOption) - 1].events[i].coordinates.X,
						allStorylines[__int64(selectedOption) - 1].events[i].coordinates.Y
					);
					std::cout << char(254);
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

void printAsTimeline(StorylineManager* storylineManager, bool getAllEvents)
{
	std::vector<Storyline> allStorylines = storylineManager->getAllStorylines(true);
	if (getAllEvents)
	{
		std::vector<Storyline> unApproveStorylines = storylineManager->getAllStorylines(false);
		allStorylines.insert(
			allStorylines.end(),
			unApproveStorylines.begin(),
			unApproveStorylines.end()
		);
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
				for (size_t i = 0; i < allStorylines[__int64(selectedOption) - 1].events.size(); i++)
				{
					short xY;
					short yY;

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

					size_t sizeOfTitle = allStorylines[__int64(selectedOption) - 1].events[i].title.size();

					if (sizeOfTitle <= 14)
					{
						size_t middlePos = sizeOfTitle / 2;

						outputPosition(int(xY - middlePos + 2), int(yY - 1));
						std::cout << allStorylines[__int64(selectedOption) - 1].events[i].title;

						outputPosition(xY, yY);
						std::cout << allStorylines[__int64(selectedOption) - 1].events[i].period[0].tm_year + 1900;
					}
					else
					{
						outputPosition(xY, yY);
						std::cout << allStorylines[__int64(selectedOption) - 1].events[i].period[0].tm_year + 1900;
					}
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

void displayStoryline(StorylineManager* storylineManager, bool getAllEvents)
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
