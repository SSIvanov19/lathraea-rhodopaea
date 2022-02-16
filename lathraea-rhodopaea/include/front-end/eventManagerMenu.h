/*! @file eventManagerMenu.h
*   @brief A header file for the event menu handaling system.
*/

#pragma once
#include <back-end/eventManager.h>
#include <conio.h>
/**
 * @brief Function for adding events of type "other"
 * @param eventManager Variable for an event manager
 * @param approve Approve the new event automatically
*/
void addOtherEvent(EventManager* eventManager, bool approve);

/**
 * @brief Function for adding events of type "uprising"
 * @param eventManager Variable for an event manager
 * @param approve Approve the new event automatically
*/
void addUprisingEvent(EventManager* eventManager, bool approve);

/**
 * @brief Function for adding events of type "war"
 * @param eventManager Variable for an event manager
 * @param approve Approve the new event automatically
*/
void addWarEvent(EventManager* eventManager, bool approve);

/**
 * @brief Function for adding events of type "movement"
 * @param eventManager Variable for an event manager
 * @param approve Approve the new event automatically
*/
void addMovementEvent(EventManager* eventManager, bool approve);

/**
 * @brief Function for adding historical events
 * @param eventManager Variable for an event manager
 * @param approve Approve the new event automatically
*/
void addEvent(EventManager* eventManager, bool approve);

/**
 * @brief Function for deleting historical events
 * @param eventManager Variable for an event manager
*/
void deleteEvent(EventManager* eventManager);

/**
 * @brief Function for displaying information about a particular event
 * @param e Reference to the event
 * @param approve Get unapproved
 * @param eventManager Event Manager
*/
void displayEvent(
	const Event& e,
	bool approve = false,
	EventManager* eventManager = nullptr
);

/**
 * @brief Function for choosing event to display
 * @param events Vector with all the events to show
 * @param output The way the events should be displayed
*/
void printEventInfo(const std::vector<Event> events, int output);

/**
 * @brief Function for displaying all the events
 * @param eventManager Variable for an event manager
 * @param sorting The way of sorting
 * @param type The parameter we sort
 * @param getAllEvents Get unapproved events
*/
void displayAllEvents(
	EventManager* eventManager,
	int sorting,
	int& type,
	bool getAllEvents = false
);

/**
 * @brief Function for choosing the way of sorting the events by year
 * @param eventManager Variable for an event manager
 * @param type The parameter we sort
 * @param getAllEvents Get unapproved events
*/
void chooseSorting(
	EventManager* eventManager,
	int type, 
	bool getAllEvents = false
);

/**
 * @brief Function for choosing the type of printing the events
 * @param eventManager Variable for an event manager
 * @param getAllEvents Get unapproved events
*/
void printBy(EventManager* eventManager, bool getAllEvents = false);

/**
 * @brief Function for printing event coordinates on map
 * @param eventManager Variable for an event manager
 * @param getAllEvents Get unapproved events
*/
void printAsMap(EventManager* eventManager, bool getAllEvents = false);

/**
 * @brief Function for editing events
 * @param eventManager event manager
*/
void editEvent(EventManager* eventManager);

/**
 * @brief Function for choosing the way of printing the events
 * @param eventManager Variable for an event manager
 * @param getAllEvents Get unapproved events
*/
void displayEvents(EventManager* eventManager, bool getAllEvents = false);

/**
 * @brief Function for approving an event
 * @param eventManager Event manager
*/
void approveEvent(EventManager* eventManager);