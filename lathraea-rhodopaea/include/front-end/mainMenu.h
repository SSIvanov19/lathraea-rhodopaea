/*! @file mainMenu.h
*   @brief A header file for the functions used for the main menu.
*/
#pragma once

#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <back-end/eventManager.h>

void outputOptions(std::vector<std::string> possibleOptions, int& selectedOption); // Function for printing the main menu options
bool isValidMonthName(std::string month); // Function for checking whether the month is entered correctly
bool isDayInRange(std::string day); // Function for checking whether the day is in range
bool checkDatesValidation(std::string str); // Function for checking whether the date is entered in the correct way
std::vector <std::string> separateDates(std::string str); // Function for passing the date/s as vector
void addOtherEvent(EventManager* eventManager); // Function for adding events of type "other"
void addUprisingEvent(EventManager* eventManager); // Function for adding events of type "uprising"
void addWarEvent(EventManager* eventManager); // Function for adding events of type "war"
void addMovementEvent(EventManager* eventManager); // Function for adding events of type "movement"
void addEvent(EventManager* eventManager); // Function for adding historical events
void deleteEvent(EventManager* eventManager); // Function for deleting historical events
std::string separate(const std::vector<std::string> information); // Function for converting information in vector to string
void displayEvent(const Event& e); // Function for displaying information about a particular event
void printEventInfo(const std::vector<Event> events, int output); // Function for choosing event to display
void displayAllEvents(EventManager* eventManager, int sorting, int& type); // Function for displaying all the events
void chooseSorting(EventManager* eventManager, int type); // Function for choosing the way of sorting the events by year
void printBy(EventManager* eventManager); // Function for choosing the type of printing the events
void displayEvents(EventManager* eventManager); // Function for choosing the way of printing the events
void switchMenuOptions(EventManager* eventManager, char key, int& selectedOption, std::vector<std::string> possibleOptions); // Function for coloring hovered options
