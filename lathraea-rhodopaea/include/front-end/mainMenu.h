/*! @file graphics.h
*   @brief A header file for the functions used for the main menu.
*/
#pragma once

#include <iostream>
#include <conio.h>
#include <vector>
#include <string>

void outputOptions(std::vector<std::string> possibleOptions, int& selectedOption);
void addEvent();
void addUprisingEvent();
void addWarEvent();
void addMovementEvent();
void deleteEvent();
void hoverMenuOptions(char key, int& selectedOption, std::vector<std::string> possibleOptions);