/*! @file storylineManagerMenu.h
*   @brief A header file for the storyline menu handaling system.
*/

#pragma once

#include <back-end/eventManager.h>
#include <back-end/storylineManager.h>
#include <back-end/accountSystem.h>
#include <conio.h>

/**
 * @brief Function for creating a storyline
 * @param eventManager Event manager
 * @param storylineManager Storyline manager
 * @param accountManager Account manager
 * @param getEvents Should get unapproved events
*/
void createStoryline(
	EventManager* eventManager,
	StorylineManager* storylineManager,
	AccountManager* accountManager,
	bool getEvents = false
);

/**
 * @brief Function for approving event
 * @param storylineManager Storyline manager
*/
void approveStoryline(StorylineManager* storylineManager);

/**
 * @brief Function for deleting historical events
 * @param eventManager Variable for an event manager
*/
void deleteStoryline(StorylineManager* storylineManager);

/**
 * @brief Function for printing events (storylines) on the map
 * @param storylineManager Storyline manager
 * @param getAllEvents Should get unapproved events
*/
void printStorylineOnMap(StorylineManager* storylineManager, bool getAllEvents = false);

/**
 * @brief Function for choosing the way of printing the events
 * @param eventManager Variable for an event manager
 * @param getAllEvents Should get unapproved events
*/
void displayStoryline(StorylineManager* storylineManager, bool getAllEvents);

/**
 * @brief Function for printing events (storylines) as a timeline
 * @param storylineManager Variable for an storyline manager
 * @param getAllEvents Should get unapproved events
*/
void printAsTimeline(StorylineManager* storylineManager, bool getAllEvents);

/**
 * @brief Function for displaying storyline's info
 * @param storylineManager Storyline manager
 * @param getAllEvents Should get unapproved events
*/
void displayStoryline(StorylineManager* storylineManager, bool getAllEvents = false);