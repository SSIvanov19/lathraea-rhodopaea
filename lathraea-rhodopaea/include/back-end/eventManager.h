/*! @file eventManager.h
*   @brief A header file for the event managing system.
*/

#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <back-end/datetimeManager.h>

/**
 * @brief An enum for different typed of event
*/
enum class TypeOfEvent
{
	UPRISING = 1, /*!< Uprising */
	WAR = 2, /*!< War */
	MOVEMENT = 3, /*!< Movement */
	OTHER = 4 /*!< Other (Undefined)*/
};


/**
 * @brief Struct for coordinates
*/
struct Coordinates
{
	short X; //!< X coordinate
	short Y; //!< Y coordinate
};

/**
 * @brief Struct for an event
*/
struct Event
{
	std::string title; //!< Title of the event
	std::vector<tm> period; //!< Period/Year of the event
	std::vector<std::string> epochs; //!< Epoch of the event (Determine by the year)
	Coordinates coordinates = { 0, 0 }; //!< Coordinates of the event
	TypeOfEvent type; //!< Type of the event
	std::string additionalNotes; //!< Description of the event
	time_t timeOfCreation; //!< Time of creation of the event
	bool isAdminApproved = false; //!< Is the event approved by an admin

	// Uprising event
	std::vector<std::string> organizers; //!< Organizers of the uprising
	int numberOfRebelions; //!< Number of rebelions participation in the uprising
	bool isItSuccessful; //!< Is the uprising successful

	// War event
	std::vector<std::string> participatingCountries; //!< Participating countries in the war
	std::string winner; //!< The winier of the war
	std::string reason; //!< The reasong for the war
	std::vector<std::string> rulers; //!< The rulers of the countries Participating in the war

	// Movement event
	std::string howItStarted; //!< How does the movement start
	std::string ideas; //!< The ideas of the movement
	std::string aims; //!< The aims of the movement
	std::vector<std::string> representatives; //!< The representatives of the movement

	DateManager dateManager; //!< Date manager

	/**
	 * @brief Constructor for a uprising event
	 * @param title_ Title of the uprising
	 * @param period_ Period of the uprising
	 * @param coordinates_ Coordinates of the uprising on the map
	 * @param organizers_ Organizers of the uprising
	 * @param isItSuccessful_ Is the uprising successful
	 * @param numberOfRebelions_ The number of rebelions participation in the uprising
	 * @param additionalNotes_ Additional notes for the uprising
	*/
	Event(
		std::string title_,
		std::vector<std::string> period_,
		Coordinates coordinates_,
		std::vector<std::string> organizers_,
		bool isItSuccessful_,
		int numberOfRebelions_ = NULL,
		std::string additionalNotes_ = ""
	);

	/**
	 * @brief Constructor for a war event
	 * @param title_ Title of the war
	 * @param period_ Period of the war
	 * @param coordinates_ Coordinates of the war on the map
	 * @param participatingCountries_ Participating countries in the war
	 * @param winner_ Winner in the war
	 * @param reasons_ Reasons for the war
	 * @param rulers_ Rulers of the countries Participating in the war
	 * @param additionalNotes_ Additional notes for the war
	*/
	Event(
		std::string title_,
		std::vector<std::string> period_,
		Coordinates coordinates_,
		std::vector<std::string> participatingCountries_,
		std::string winner_,
		std::string reasons_,
		std::vector<std::string> rulers_ = std::vector<std::string>(),
		std::string additionalNotes_ = ""
	);

	/**
	 * @brief Constructor for a movement event
	 * @param title_ Title for the movement
	 * @param period_ Period for the movement
	 * @param coordinates_ Coordinates of the movement on the map
	 * @param howItStarted_ How does the movement start
	 * @param ideas_ ideas of the movement
	 * @param aims_ Aims of the movement
	 * @param representatives_ Representatives of the movement
	 * @param additionalNotes_ Additional notes for the movement
	*/
	Event(
		std::string title_,
		std::vector<std::string> period_,
		Coordinates coordinates_,
		std::string howItStarted_,
		std::string ideas_,
		std::string aims_,
		std::vector<std::string> representatives_ = std::vector<std::string>(),
		std::string additionalNotes_ = ""
	);

	/**
	 * @brief Constructor for a undefined (other) event
	 * @param title_ Title for the event
	 * @param period_ Period for the event
	 * @param coordinates_ Coordinates of the movement on the map
	 * @param additionalNotes_ Additional notes for the event
	*/
	Event(
		std::string title_,
		std::vector<std::string> period_,
		Coordinates coordinates_,
		std::string additionalNotes_ = ""
	);

	/**
	 * @brief Default constructor for a Event
	*/
	Event();
};

/**
 * @brief Struct for an event list
*/
struct EventList
{
	Event event; //!< The data of the event
	EventList* next = nullptr; //!< The next node

	/**
	 * @brief A constructor for EventList
	 * @param event_ The data of the first event (Admin)
	 * @param next_ A pointer to the next event
	*/
	EventList(Event event_, EventList* next_);

	/**
	 * @brief Function for adding an event
	 * @param data The data of the event
	*/
	void addEvent(Event data);

	/**
	 * @brief Function for adding an event at the end of the list
	 * @param head Head of the list
	 * @param data The data of the event
	*/
	void insertEventAtFront(EventList** head, Event data);

	/**
	 * @brief Function for checking if there is already a event with the same name
	 * @param titleToCheck Title of the event to be checked
	*/
	bool doesEventExist(std::string titleToCheck);
};

/**
 * @brief Struct for an event manager
*/
struct EventManager
{
	EventList* eventList = nullptr; //!< List with all events 

	DateManager dateManager; //!< Date manager

	/**
	 * @brief Function for adding an uprise event
	 * @param title Title of the uprise
	 * @param period Period of the uprise
	 * @param coordinates Coordinates of the uprise
	 * @param organizers Organizers of the uprise
	 * @param isItSuccessful Is the uprise successful
	 * @param numberOfRebelions Number of rebelions taking part in the uprise
	 * @param additionalNotes Additional notes for the uprise
	*/
	void addUprisingEvent(
		std::string title,
		std::vector<std::string> period,
		Coordinates coordinates,
		std::vector<std::string> organizers,
		bool isItSuccessful,
		int numberOfRebelions = NULL,
		std::string additionalNotes = ""
	);

	/**
	 * @brief Function for adding a war event
	 * @param title Title of the war
	 * @param period Period of the war
	 * @param coordinates Coordinates of the war
	 * @param participatingCountries Participating countries in the war
	 * @param winner Winner of the war
	 * @param reasons Reasons for the war
	 * @param rulers Rulers of the countries Participating in the war
	 * @param additionalNotes Additional notes
	*/
	void addWarEvent(
		std::string title,
		std::vector<std::string> period,
		Coordinates coordinates,
		std::vector<std::string> participatingCountries,
		std::string winner,
		std::string reasons,
		std::vector<std::string> rulers = std::vector<std::string>(),
		std::string additionalNotes = ""
	);

	/**
	 * @brief Function for adding a movement
	 * @param title TItle of the movement
	 * @param period Period of the movement
	 * @param coordinates Coordinates of the movement
	 * @param howItStarted How does the movement stared
	 * @param ideas Ideas of the movement
	 * @param aims Aims of the movement
	 * @param representatives Representatives of the movement
	 * @param additionalNotes Additional notes
	*/
	void addMovementEvent(
		std::string title,
		std::vector<std::string> period,
		Coordinates coordinates,
		std::string howItStarted,
		std::string ideas,
		std::string aims,
		std::vector<std::string> representatives = std::vector<std::string>(),
		std::string additionalNotes = ""
	);

	/**
	 * @brief Function for adding a undefined (other) event
	 * @param title TItle of the event
	 * @param period Period of the event
	 * @param coordinates Coordinates of the event
	 * @param additionalNotes Additional notes for the event
	*/
	void addOtherEvent(
		std::string title,
		std::vector<std::string> period,
		Coordinates coordinates,
		std::string additionalNotes = ""
	);

	/**
	 * @brief Function for deleting a node from the list
	 * @param head Head of the list
	 * @param searchTitle Title to be looked up
	 * @return Is removeing successful
	*/
	bool removeEvent(EventList** head, std::string searchTitle);

	/**
	 * @brief Function for editing single value filed of a struct
	 * @tparam T The type of filed and value
	 * @param field The filed to be edited
	 * @param value The new value of the field
	*/
	template<typename T>
	void setSingleValueField(T& field, T value);

	/**
	 * @brief Function for editing multi value filed of a struct
	 * @tparam T The type of vector of filed and value
	 * @param field The filed to be edited
	 * @param value The new value of the field
	*/
	template<typename T>
	void setMultiValueField(std::vector<T>& field, std::vector<T> value);

	/**
	 * @brief Function for approving an event by the admin
	 * @param titleOfTheEvent Title of the event to be approved
	*/
	void approveEvent(std::string titleOfTheEvent);


	/**
	 * @brief Function for getting all events that are approved/unapproved
	 * @param isApproved Are events approved/unapproved
	 * @return Vector with all the events
	*/
	std::vector<Event> getAllEvents(bool isApproved);

	/**
	 * @brief Function for getting event with specific title
	 * @param title Title of the event
	 * @return Pointer to the event
	*/
	Event* getEventWithName(std::string title);

	/**
	 * @brief Function for getting all elements with a keyword in the title
	 * @param head Head of the list
	 * @param searchTitle The keyword
	 * @return All events with this keyword in their title
	*/
	std::vector<Event> getAllEventsWithTitle(
		std::vector<Event> events,
		std::string searchTitle
	);

	/**
	 * @brief Function for getting all elements with a date
	 * @param date The date to be looked up
	 * @return All events that happend on this date
	*/
	std::vector<Event> getAllEventsWithDate(
		std::vector<Event> events,
		tm date
	);

	/**
	 * @brief Function for getting all events with same type from a vector
	 * @param events Events to be looked up
	 * @param typeOfEvent The type of the events
	 * @return Vector with all events of that type
	*/
	std::vector<Event> getAllEventsWithType(
		std::vector<Event> events,
		TypeOfEvent typeOfEvent
	);

	/**
	 * @brief Function for getting and sorting all events from a vector, based on the time of creations
	 * @param events Vector with events to be sorted
	 * @return new Vector with sorted events
	*/
	std::vector<Event> sortAndGetAllEventsByTimeOfCreation(
		std::vector<Event> events
	);

	/**
	 * @brief Function for getting and sorting all events from a vector, based on the title
	 * @param events Vector with events to be sorted
	 * @return new Vector with sorted events
	*/
	std::vector<Event> sortAndGetAllEventsByTitle(
		std::vector<Event> events
	);

	/**
	 * @brief Function for getting and sorting all events from a vector, based on the date of the event
	 * @param events Vector with events to be sorted
	 * @return new Vector with sorted events
	*/
	std::vector<Event> sortAndGetAllEventsByDate(
		std::vector<Event> events
	);
};

template<typename T>
void EventManager::setSingleValueField(T& field, T value)
{
	field = value;
}

template<typename T>
void EventManager::setMultiValueField(std::vector<T>& field, std::vector<T> value)
{
	field.swap(value);
}