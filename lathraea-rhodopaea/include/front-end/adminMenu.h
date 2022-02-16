#pragma once
#include <back-end/eventManager.h>
#include <back-end/storylineManager.h>
#include <back-end/accountSystem.h>
#include <conio.h>

/**
 * @brief Function for printing and handaling the menu for storyline management
 * @param eventManager Event manager
 * @param storylineManager Storyline manager
 * @param accountManager Account manager
*/
void adminStorylineManagement(
	EventManager* eventManager,
	StorylineManager* storylineManager,
	AccountManager* accountManager
);

/**
 * @brief Function for printing and handaling the menu for event management
 * @param eventManager Event manager
 * @param storylineManager Storyline manager
*/
void adminEventManagement(
	EventManager* eventManager,
	StorylineManager* storylineManager
);

/**
 * @brief Function for printing and handaling the menu for user management
 * @param accountManager Account manager
*/
void adminUserManagement(AccountManager* accountManager);