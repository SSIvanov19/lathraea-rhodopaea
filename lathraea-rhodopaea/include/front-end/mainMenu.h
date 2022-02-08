/*! @file graphics.h
*   @brief A header file for the functions used for the main menu.
*/
#pragma once

#include <iostream>
#include <conio.h>
#include <vector>
#include <string>

void outputOptions(std::vector<std::string> possibleOptions, int& selectedOption); // Function for printing the main menu options
void addEvent(EventManager eventManager); // Function for adding historical events
bool isValidMonthName(std::string month); // Function for checking whether the month is entered correctly
bool isDayInRange(std::string day); // Function for checking whether the day is in range
bool checkDatesValidation(std::string str); // Function for checking whether the date is entered in the correct way
std::vector <std::string> separateDates(std::string str); // Function for passing the date/s as vector
void addUprisingEvent(EventManager eventManager); // Function for adding events of type "uprising"
void addWarEvent(EventManager eventManager); // Function for adding events of type "war"
void addMovementEvent(EventManager eventManager); // Function for adding events of type "movement"
void deleteEvent(EventManager eventManager); // Function for deleting historical events
void switchMenuOptions(EventManager* eventManager, char key, int& selectedOption, std::vector<std::string> possibleOptions); // Function for coloring hovered options
