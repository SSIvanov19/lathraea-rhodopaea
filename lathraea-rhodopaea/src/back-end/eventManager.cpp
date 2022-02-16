/*! @file eventManager.cpp
*   @brief A source file for the event managing system.
*/

#include <back-end/eventManager.h>
#include <external/strptime.h>
#include <back-end/logs.h>

/**
 * @brief Function for getting epoch based on the year
 * @param d The date in form of tm
 * @return The epoch as a string
*/
std::string getTheEpoch(tm d)
{
	int year = d.tm_year + 1900;

	if (year < 681)
	{
		return "Antiquity and the Early Middle Ages (up to the 7th century)";
	}

	if (year >= 681 && year <= 1018)
	{
		return "Bulgarian Middle Ages -> First Bulgarian country (681 - 1018)";
	}

	if (year > 1018 && year <= 1185)
	{
		return "Bulgarian Middle Ages -> Byzantine rule (1018 - 1185)";
	}

	if (year > 1185 && year <= 1396)
	{
		return "Bulgarian Middle Ages -> Second Bulgarian Country (1185 - 1396)";
	}

	if (year > 1396 && year <= 1601)
	{
		return "Ottoman rule (1396 - 1878) -> Bulgarian lands in the XV and XVI centuries (1396 - 1600)";
	}

	if (year > 1601 && year <= 1760)
	{
		return "Ottoman rule (1396 - 1878) -> Bulgarian lands in the XVII centuryand the first half of the XVIII century(1601 - 1760)";
	}

	if (year > 1760 && year <= 1878)
	{
		return "Ottoman rule (1396 - 1878) -> Revival (18th - 19th century)";
	}

	if (year > 1878 && year <= 1912)
	{
		return "Third Bulgarian state (since 1878) -> From the Liberation to the Balkan Wars";
	}

	if (year > 1912 && year <= 1918)
	{
		return "Third Bulgarian state (since 1878) -> Wars of national unification";
	}

	if (year > 1918 && year <= 1945)
	{
		return "Third Bulgarian state (since 1878) -> After the First and during Second World Wars (1918 - 1945)";
	}

	if (year > 1945 && year <= 1989)
	{
		return "Third Bulgarian state (since 1878) -> People's Republic of Bulgaria (1946 - 1989)";
	}

	time_t rawtime = time(0);
	struct tm timeinfo;
	localtime_s(&timeinfo, &rawtime);

	if (year > 1989 && year <= (timeinfo.tm_year + 1900))
	{
		return "Third Bulgarian state (since 1878) -> Republic of Bulgaria (since 1990)";
	}

	return "Are you a time traveller?";
}

/**
 * @brief Returns the type of the event as a string
 * @param typeOfEvent The type of event
 * @return The type of event as a string
*/
std::string enumToString(TypeOfEvent typeOfEvent)
{
	switch (typeOfEvent)
	{
	case TypeOfEvent::UPRISING:
		return "Uprising";
		break;
	case TypeOfEvent::WAR:
		return "War";
		break;
	case TypeOfEvent::MOVEMENT:
		return "Movement";
		break;
	case TypeOfEvent::OTHER:
		return "Other";
		break;
	default:
		return "Other";
		break;
	}
}

Event::Event(
	std::string title_,
	std::vector<std::string> period_,
	Coordinates coordinates_,
	std::vector<std::string> organizers_,
	bool isItSuccessful_,
	int numberOfRebelions_,
	std::string additionalNotes_
)
{
	title = title_;
	period = dateManager.converVectorOfStringsToVectorOfDate(period_);
	coordinates = coordinates_;
	organizers = organizers_;
	isItSuccessful = isItSuccessful_;
	numberOfRebelions = numberOfRebelions_;
	additionalNotes = additionalNotes_;
	type = TypeOfEvent::UPRISING;
	isAdminApproved = false;
	timeOfCreation = time(0);
	for (const tm& date : period)
	{
		epochs.push_back(getTheEpoch(date));
	}
}

Event::Event(
	std::string title_,
	std::vector<std::string> period_,
	Coordinates coordinates_,
	std::vector<std::string> participatingCountries_,
	std::string winner_,
	std::string reasons_,
	std::vector<std::string> rulers_,
	std::string additionalNotes_
)
{
	title = title_;
	period = dateManager.converVectorOfStringsToVectorOfDate(period_);
	coordinates = coordinates_;
	participatingCountries = participatingCountries_;
	winner = winner_;
	reason = reasons_;
	rulers = rulers_;
	additionalNotes = additionalNotes_;
	type = TypeOfEvent::WAR;
	isAdminApproved = false;
	timeOfCreation = time(0);
	for (const tm& date : period)
	{
		epochs.push_back(getTheEpoch(date));
	}
}

Event::Event(
	std::string title_,
	std::vector<std::string> period_,
	Coordinates coordinates_,
	std::string howItStarted_,
	std::string ideas_,
	std::string aims_,
	std::vector<std::string> representatives_,
	std::string additionalNotes_
)
{
	title = title_;
	period = dateManager.converVectorOfStringsToVectorOfDate(period_);
	coordinates = coordinates_;
	howItStarted = howItStarted_;
	ideas = ideas_;
	aims = aims_;
	representatives = representatives_;
	additionalNotes = additionalNotes_;
	type = TypeOfEvent::MOVEMENT;
	isAdminApproved = false;
	timeOfCreation = time(0);
	for (const tm& date : period)
	{
		epochs.push_back(getTheEpoch(date));
	}
}

Event::Event(
	std::string title_,
	std::vector<std::string> period_,
	Coordinates coordinates_,
	std::string additionalNotes_
)
{
	title = title_;
	period = dateManager.converVectorOfStringsToVectorOfDate(period_);
	coordinates = coordinates_;
	additionalNotes = additionalNotes_;
	type = TypeOfEvent::OTHER;
	isAdminApproved = false;
	timeOfCreation = time(0);
	for (const tm& date : period)
	{
		epochs.push_back(getTheEpoch(date));
	}
}

Event::Event() = default;

EventList::EventList(Event event_, EventList * next_)
{
	event = event_;
	next = next_;
}

void EventList::addEvent(Event data)
{
	EventList* newNode = new EventList(data, nullptr);

	EventList* temp = this;

	while (temp)
	{
		if (temp->next == NULL)
		{
			temp->next = newNode;
			return;
		}
		else
		{
			temp = temp->next;
		}
	}
}

void EventList::insertEventAtFront(EventList * *head, Event data)
{
	EventList* newNode = new EventList(data, *head);

	*head = newNode;
}

bool EventList::doesEventExist(std::string titleToCheck)
{
	EventList* temp = this;

	while (temp != NULL)
	{
		if (temp->event.title == titleToCheck)
		{

			return true;
		}
		temp = temp->next;
	}

	return false;
}

void EventManager::addUprisingEvent(
	std::string title,
	std::vector<std::string> period,
	Coordinates coordinates,
	std::vector<std::string> organizers,
	bool isItSuccessful,
	int numberOfRebelions,
	std::string additionalNotes
)
{
	LoggerManager loggerManager;
	loggerManager.log(
		LogSeverity::INFO,
		"Trying to add new event with title: " + title
	);

	// Validate the data
	if (title.size() == 0)
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registered, because the title is NULL."
		);

		throw std::string("Title can not be empty!");
	}

	if (period.size() == 0)
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registered, because the period is NULL."
		);

		throw std::string("Period can not be empty!");
	}

	if (organizers.size() == 0)
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registered, because the organizers is NULL."
		);

		throw std::string("Organizers can not be empty");
	}

	// Check for duplicate names
	if (eventList->doesEventExist(title))
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registered, because there is already"
			" an event with the same name."
		);

		throw std::string("There is already an event with the same name");
	}

	// Add the event to the linked list
	if (eventList != nullptr)
	{
		eventList->addEvent(
			Event(
				title,
				period,
				coordinates,
				organizers,
				isItSuccessful,
				numberOfRebelions,
				additionalNotes
			)
		);
	}
	else
	{
		eventList->insertEventAtFront(
			&eventList, Event(
				title,
				period,
				coordinates,
				organizers,
				isItSuccessful,
				numberOfRebelions,
				additionalNotes
			)
		);
	}

	// Log
	loggerManager.log(
		LogSeverity::INFO,
		"Event with title: " + title + " is registered successfully."
	);
}

void EventManager::addWarEvent(
	std::string title,
	std::vector<std::string> period,
	Coordinates coordinates,
	std::vector<std::string> participatingCountries,
	std::string winner,
	std::string reasons,
	std::vector<std::string> rulers,
	std::string additionalNotes
)
{
	LoggerManager loggerManager;
	loggerManager.log(
		LogSeverity::INFO,
		"Trying to add new event with title: " + title
	);

	// Validate the data
	if (title.size() == 0)
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registered, because the title is NULL."
		);

		throw std::string("Title can not be empty!");
	}

	if (period.size() == 0)
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registered, because the period is NULL."
		);

		throw std::string("Period can not be empty!");
	}

	if (participatingCountries.size() == 0)
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registered, because the participating countries is NULL."
		);

		throw std::string("Participating countries can not be empty");
	}

	if (winner.size() == 0)
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registered, because the winner is NULL."
		);

		throw std::string("Winner can not be empty!");
	}

	if (reasons.size() == 0)
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registered, because the reasons is NULL."
		);

		throw std::string("Reasons can not be empty!");
	}

	// Check for duplicate names
	if (eventList->doesEventExist(title))
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registered, because there is already"
			" an event with the same name."
		);

		throw std::string("There is already an event with the same name");
	}

	// Add the event to the linked list
	if (eventList != nullptr)
	{
		eventList->addEvent(
			Event(
				title,
				period,
				coordinates,
				participatingCountries,
				winner,
				reasons,
				rulers,
				additionalNotes
			)
		);
	}
	else
	{
		eventList->insertEventAtFront(
			&eventList,
			Event(
				title,
				period,
				coordinates,
				participatingCountries,
				winner,
				reasons,
				rulers,
				additionalNotes
			)
		);
	}

	// Log
	loggerManager.log(
		LogSeverity::INFO,
		"Event with title: " + title + " is registered successfully."
	);
}


void EventManager::addMovementEvent(
	std::string title,
	std::vector<std::string> period,
	Coordinates coordinates,
	std::string howItStarted,
	std::string ideas,
	std::string aims,
	std::vector<std::string> representatives,
	std::string additionalNotes
)
{
	LoggerManager loggerManager;
	loggerManager.log(
		LogSeverity::INFO,
		"Trying to add new event with title: " + title
	);

	// Validate the data
	if (title.size() == 0)
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registered, because the title is NULL."
		);

		throw std::string("Title can not be empty!");
	}

	if (period.size() == 0)
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registered, because the period is NULL."
		);

		throw std::string("Period can not be empty!");
	}

	if (howItStarted.size() == 0)
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registered, because the how it started is NULL."
		);

		throw std::string("How it started can not be empty!");
	}

	if (ideas.size() == 0)
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registered, because the ideas is NULL."
		);

		throw std::string("Ideas can not be empty!");
	}

	if (aims.size() == 0)
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registered, because the aims is NULL."
		);

		throw std::string("Aims can not be empty!");
	}

	// Check for duplicate names
	if (eventList->doesEventExist(title))
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registered, because there is already"
			" an event with the same name."
		);

		throw std::string("There is already an event with the same name");
	}

	// Add the event to the linked list
	if (eventList != nullptr)
	{
		eventList->addEvent(
			Event(
				title,
				period, coordinates,
				howItStarted,
				ideas,
				aims,
				representatives,
				additionalNotes
			)
		);
	}
	else
	{
		eventList->insertEventAtFront(
			&eventList,
			Event(
				title,
				period,
				coordinates,
				howItStarted,
				ideas,
				aims,
				representatives,
				additionalNotes
			)
		);
	}

	// Log
	loggerManager.log(
		LogSeverity::INFO,
		"Event with title: " + title + " is registered successfully."
	);
}

void EventManager::addOtherEvent(
	std::string title,
	std::vector<std::string> period,
	Coordinates coordinates,
	std::string additionalNotes
)
{
	LoggerManager loggerManager;
	loggerManager.log(
		LogSeverity::INFO,
		"Trying to add new event with title: " + title
	);

	// Validate the data
	if (title.size() == 0)
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registered, because the title is NULL."
		);

		throw std::string("Title can not be empty!");
	}

	if (period.size() == 0)
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registered, because the period is NULL."
		);

		throw std::string("Period can not be empty!");
	}

	// Check for duplicate names
	if (eventList->doesEventExist(title))
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registered, because there is already"
			" an event with the same name."
		);

		throw std::string("There is already an event with the same name");
	}

	// Add the event to the linked list
	if (eventList != nullptr)
	{
		eventList->addEvent(
			Event(
				title,
				period,
				coordinates,
				additionalNotes
			)
		);
	}
	else
	{
		eventList->insertEventAtFront(
			&eventList,
			Event(
				title,
				period,
				coordinates,
				additionalNotes
			)
		);
	}

	// Log
	loggerManager.log(
		LogSeverity::INFO,
		"Event with title: " + title + " is registered successfully."
	);
}

bool EventManager::removeEvent(EventList * *head, std::string searchTitle)
{
	LoggerManager loggerManager;

	EventList* temp = *head;
	EventList* prev = NULL;

	if (temp != NULL && temp->event.title == searchTitle)
	{
		*head = temp->next;

		loggerManager.log(
			LogSeverity::INFO,
			"Event with title: " +
			searchTitle +
			" is successfully deleted."
		);

		delete temp;
		return true;
	}
	else
	{
		while (temp != NULL && temp->event.title != searchTitle)
		{
			prev = temp;
			temp = temp->next;
		}

		if (temp == NULL)
		{
			loggerManager.log(
				LogSeverity::NOTICE,
				"Event with title: " +
				searchTitle +
				" can not be deleted, because there is not an event with such title."
			);

			return false;
		}

		if (prev != NULL)
		{
			prev->next = temp->next;
		}

		loggerManager.log(
			LogSeverity::INFO,
			"Event with title: " +
			searchTitle +
			" is successfully deleted."
		);

		delete temp;
	}

	return true;
}

void EventManager::approveEvent(std::string titleOfTheEvent)
{
	LoggerManager loggerManager;
	EventList* temp = this->eventList;

	loggerManager.log(
		LogSeverity::INFO,
		"Looking to approve event with title: " + titleOfTheEvent
	);

	while (temp)
	{
		if (temp->event.title == titleOfTheEvent)
		{
			temp->event.isAdminApproved = true;

			loggerManager.log(
				LogSeverity::INFO,
				"Event with title: " + titleOfTheEvent + " is successfully approved."
			);

			return;
		}

		temp = temp->next;
	}

	loggerManager.log(
		LogSeverity::NOTICE,
		"There is no event with title: " + titleOfTheEvent
	);

	throw std::string("There is no a event with such title: " + titleOfTheEvent);
}

std::vector<Event> EventManager::getAllEvents(bool isApproved)
{
	LoggerManager loggerManager;
	std::vector<Event> returnVal;

	EventList* temp = this->eventList;

	loggerManager.log(
		LogSeverity::INFO,
		"Getting all events that are " +
		isApproved ? "approved." : "unapproved."
	);

	while (temp)
	{
		if (temp->event.isAdminApproved == isApproved)
		{
			returnVal.push_back(temp->event);
		}

		temp = temp->next;
	}

	loggerManager.log(
		LogSeverity::INFO,
		"Found " + std::to_string(returnVal.size()) +
		" events that are " + (isApproved ? "approved." : "unapproved.")
	);

	return returnVal;
}

Event* EventManager::getEventWithName(std::string title)
{
	LoggerManager loggerManager;
	EventList* temp = this->eventList;

	loggerManager.log(
		LogSeverity::INFO,
		"Start searching for event with title: " + title
	);

	while (temp)
	{
		if (temp->event.title == title)
		{
			loggerManager.log(
				LogSeverity::INFO,
				"Found event with title: " + title
			);
			return &temp->event;
		}

		temp = temp->next;
	}

	loggerManager.log(
		LogSeverity::NOTICE,
		"Could not find event with title: " + title
	);

	return nullptr;
}

std::vector<Event> EventManager::getAllEventsWithTitle(
	std::vector<Event> events,
	std::string searchTitle
)
{
	LoggerManager loggerManager;
	std::vector<Event> returnValue;

	loggerManager.log(
		LogSeverity::INFO,
		"Trying to get all events with title: " + searchTitle
	);

	for (auto hisEvent : events)
	{
		if (hisEvent.title.find(searchTitle) != std::string::npos)
		{
			returnValue.push_back(hisEvent);
		}
	}

	loggerManager.log(
		LogSeverity::INFO,
		"Found " + std::to_string(returnValue.size()) +
		" events with title: " + searchTitle);
	return returnValue;
}

std::vector<Event> EventManager::getAllEventsWithDate(
	std::vector<Event> events,
	tm date
)
{
	LoggerManager loggerManager;
	std::vector<Event> returnValue;

	loggerManager.log(
		LogSeverity::INFO,
		"Trying to get all events with date: " +
		std::to_string(date.tm_year + 1900) + "-" +
		std::to_string(date.tm_mon + 1) + "-" +
		std::to_string(date.tm_mday)
	);

	EventList* temp = this->eventList;

	while (temp != NULL)
	{
		if (temp->event.period.size() == 2)
		{
			if (dateManager.isDateBetweenTwoDates(
				temp->event.period[0],
				date,
				temp->event.period[1]
			))
			{
				returnValue.push_back(temp->event);
			}
		}
		else
		{
			if (temp->event.period[0].tm_mday == date.tm_mday &&
				temp->event.period[0].tm_mon == date.tm_mon &&
				temp->event.period[0].tm_year == date.tm_year
				)
			{
				returnValue.push_back(temp->event);
			}
		}

		temp = temp->next;
	}

	loggerManager.log(
		LogSeverity::INFO,
		"Found " + std::to_string(returnValue.size()) +
		" events with date: " +
		std::to_string(date.tm_year + 1900) + "-" +
		std::to_string(date.tm_mon + 1) + "-" +
		std::to_string(date.tm_mday)
	);

	return returnValue;
}

std::vector<Event> EventManager::getAllEventsWithType(std::vector<Event> events, TypeOfEvent typeOfEvent)
{
	LoggerManager loggerManager;
	std::vector<Event> returnVal;

	loggerManager.log(
		LogSeverity::INFO,
		"Trying to get all events of type: " + enumToString(typeOfEvent)
	);

	for (auto hisEvent : events)
	{
		if (hisEvent.type == typeOfEvent)
		{
			returnVal.push_back(hisEvent);
		}
	}

	loggerManager.log(
		LogSeverity::INFO,
		"Found " + std::to_string(returnVal.size()) +
		" events with type: " + enumToString(typeOfEvent)
	);

	return returnVal;
}

bool compareTimeOfCreation(Event e1, Event e2)
{
	return (double(e1.timeOfCreation) < double(e2.timeOfCreation));
}

bool compareTitle(Event e1, Event e2)
{
	return (int(e1.title[0]) < int(e2.title[0]));
}

bool compareDates(Event e1, Event e2)
{
	DateManager dateManager;
	return dateManager.areDatesInOrder(e1.period[0], e2.period[0]);
}

std::vector<Event> EventManager::sortAndGetAllEventsByTimeOfCreation(
	std::vector<Event> events
)
{
	LoggerManager loggerManager;

	loggerManager.log(
		LogSeverity::INFO,
		"Start sorting the vector by time of creations."
	);

	std::sort(events.begin(), events.end(), compareTimeOfCreation);

	loggerManager.log(
		LogSeverity::INFO,
		"Finish sorting the vector by time of creations."
	);

	return events;
}

std::vector<Event> EventManager::sortAndGetAllEventsByTitle(
	std::vector<Event> events
)
{
	LoggerManager loggerManager;

	loggerManager.log(
		LogSeverity::INFO,
		"Start sorting the vector by title."
	);

	std::sort(events.begin(), events.end(), compareTitle);

	loggerManager.log(
		LogSeverity::INFO,
		"Finish sorting the vector by title."
	);

	return events;
}

std::vector<Event> EventManager::sortAndGetAllEventsByDate(
	std::vector<Event> events
)
{
	LoggerManager loggerManager;

	loggerManager.log(
		LogSeverity::INFO,
		"Start sorting the vector by date."
	);

	std::sort(events.begin(), events.end(), compareDates);

	loggerManager.log(
		LogSeverity::INFO,
		"Finish sorting the vector by date."
	);

	return events;
}
