/*! @file mainMenu.h
*   @brief A header file for the main menu handaling system.
*/

#pragma once

#include <iostream>
#include <back-end/eventManager.h>
#include <back-end/storylineManager.h>
#include <back-end/accountSystem.h>

/**
 * @brief Function for printing the main menu options
 * @param possibleOptions Possible options
 * @param selectedOption Selected option
*/
void outputOptions(
	std::vector<std::string> possibleOptions,
	int& selectedOption
);

/**
 * @brief Function for handaling the main menu
 * @param eventManager Event manager
 * @param storylineManager Storyline manager
 * @param accountManager Account manager
 * @param key Key
 * @param selectedOption Selected options
 * @param possibleOptions Possible options
*/
void switchMenuOptions(
	EventManager* eventManager,
	StorylineManager* storylineManager,
	AccountManager* accountManager,
	char key,
	int& selectedOption,
	std::vector<std::string> possibleOptions
);