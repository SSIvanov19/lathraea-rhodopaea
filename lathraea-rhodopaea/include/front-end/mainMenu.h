/*! @file mainMenu.h
*   @brief A header file for the functions used for the main menu.
*/
#pragma once

#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <back-end/eventManager.h>
#include <back-end/storylineManager.h>
#include <back-end/accountSystem.h>

void outputOptions(std::vector<std::string> possibleOptions, int& selectedOption); // Function for printing the main menu options
bool isValidMonthName(std::string month); // Function for checking whether the month is entered correctly
bool isDayInRange(std::string day); // Function for checking whether the day is in range
bool checkDatesValidation(std::string str); // Function for checking whether the date is entered in the correct way
std::vector <std::string> separateDates(std::string str); // Function for passing the date/s as vector
void addOtherEvent(EventManager* eventManager, bool approve); // Function for adding events of type "other"
void addUprisingEvent(EventManager* eventManager, bool approve); // Function for adding events of type "uprising"
void addWarEvent(EventManager* eventManager, bool approve); // Function for adding events of type "war"
void addMovementEvent(EventManager* eventManager, bool approve); // Function for adding events of type "movement"
void addEvent(EventManager* eventManager, bool approve); // Function for adding historical events
void deleteEvent(EventManager* eventManager); // Function for deleting historical events
std::string separate(const std::vector<std::string> information); // Function for converting information in vector to string
void displayEvent(const Event& e, bool approve = false, EventManager* eventManager = nullptr); // Function for displaying information about a particular event
void printEventInfo(const std::vector<Event> events, int output); // Function for choosing event to display
void displayAllEvents(EventManager* eventManager, int sorting, int& type, bool getAllEvents = false); // Function for displaying all the events
void chooseSorting(EventManager* eventManager, int type, bool getAllEvents = false); // Function for choosing the way of sorting the events by year
void printBy(EventManager* eventManager, bool getAllEvents = false); // Function for choosing the type of printing the events
void displayEvents(EventManager* eventManager, StorylineManager* storylineManager, bool getAllEvents = false); // Function for choosing the way of printing the events
void switchMenuOptions(
	EventManager* eventManager,
	StorylineManager* storylineManager,
	AccountManager* accountManager,
	char key,
	int& selectedOption,
	std::vector<std::string> possibleOptions
); // Function for coloring hovered options