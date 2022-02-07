/*! @file eventManager.cpp
*   @brief A source file for the event managing system.
*/

#include <back-end/eventManager.h>
#include <external/strptime.h>
#include <back-end/logs.h>

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
	type = TypeOfEvent::MOVEMENT;
}

Event::Event() = default;

void Event::displayEventInfo()
{
	std::cout << "Title: " << title << std::endl;
	
	if (period.size() == 2)
	{
		std::cout << "Start date: " << std::put_time(&period[0], "%x") << std::endl;
		std::cout << "End date: " << std::put_time(&period[1], "%x") << std::endl;
		std::cout << "Duration in days: " << dateManager.getDifference(period[0], period[1]) << std::endl;
	}
	else
	{
		std::cout << "Date: " << period[0].tm_mday << "." << 1 + period[0].tm_mon << "." << 1900 + period[0].tm_year << std::endl;
	}

	std::cout << "Type: " << int(type);
}

EventList::EventList(Event event_, EventList* next_)
{
	event = event_;
	next = next_;
}

void EventList::addEvent(EventList* head, Event data)
{
	EventList* newNode = new EventList(data, nullptr);

	EventList* temp = head;
	
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

void EventList::insertEventAtFront(EventList** head, Event data)
{
	EventList* newNode = new EventList(data, *head);

	*head = newNode;
}

bool EventList::doesEventExist(EventList* head, std::string titleToCheck)
{
	EventList* temp = head;

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

void EventList::displayAllEvents(EventList* head)
{
	while (head != NULL)
	{
		head->event.displayEventInfo();
		std::cout << std::endl << std::endl;
		head = head->next;
	}
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
	loggerManager.log(LogSeverity::INFO, "Trying to add new event with title: " + title);

	// Validate the data
	if (title.size() == 0)
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " + 
			title + 
			" can not be registerd, because the title is NULL."
		);

		throw std::string("Title can not be empty!");
	}

	if (period.size() == 0)
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " + 
			title + 
			" can not be registerd, because the period is NULL."
		);

		throw std::string("Period can not be empty!");
	}
	
	if (organizers.size() == 0)
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registerd, because the organizers is NULL."
		);

		throw std::string("Organizers can not be empty");
	}

	// Check for duplicate names
	if (eventList->doesEventExist(eventList, title))
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registerd, because there is already"
			" an event with the same name."
		);

		throw std::string("There is already an event with the same name");
	}

	// Add the event to the linked list
	if (eventList != nullptr)
	{
		eventList->addEvent(eventList, 
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
	loggerManager.log(LogSeverity::INFO, "Event with title: " + title + " is registerd successfully.");

	//Should be removed
	std::cout << "Event added successfully. All events data:\n\n";
	eventList->displayAllEvents(eventList);
	std::cout << std::endl;
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
	loggerManager.log(LogSeverity::INFO, "Trying to add new event with title: " + title);

	// Validate the data
	if (title.size() == 0)
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registerd, because the title is NULL."
		);

		throw std::string("Title can not be empty!");
	}

	if (period.size() == 0)
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registerd, because the period is NULL."
		);

		throw std::string("Period can not be empty!");
	}

	if (participatingCountries.size() == 0)
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registerd, because the participating countries is NULL."
		);

		throw std::string("Participating countries can not be empty");
	}

	if (winner.size() == 0)
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registerd, because the winner is NULL."
		);

		throw std::string("Winner can not be empty!");
	}

	if (reasons.size() == 0)
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registerd, because the reasons is NULL."
		);

		throw std::string("Reasons can not be empty!");
	}

	// Check for duplicate names
	if (eventList->doesEventExist(eventList, title))
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registerd, because there is already"
			" an event with the same name."
		);

		throw std::string("There is already an event with the same name");
	}

	// Add the event to the linked list
	if (eventList != nullptr)
	{
		eventList->addEvent(
			eventList, 
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
	loggerManager.log(LogSeverity::INFO, "Event with title: " + title + " is registerd successfully.");

	//Should be removed
	std::cout << "Event added successfully. All events data:\n\n";
	eventList->displayAllEvents(eventList);
	std::cout << std::endl;
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
	loggerManager.log(LogSeverity::INFO, "Trying to add new event with title: " + title);

	// Validate the data
	if (title.size() == 0)
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registerd, because the title is NULL."
		);

		throw std::string("Title can not be empty!");
	}

	if (period.size() == 0)
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registerd, because the period is NULL."
		);

		throw std::string("Period can not be empty!");
	}

	if (howItStarted.size() == 0)
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registerd, because the how it started is NULL."
		);

		throw std::string("How it started can not be empty!");
	}

	if (ideas.size() == 0)
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registerd, because the ideas is NULL."
		);

		throw std::string("Ideas can not be empty!");
	}

	if (aims.size() == 0)
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registerd, because the aims is NULL."
		);

		throw std::string("Aims can not be empty!");
	}

	// Check for duplicate names
	if (eventList->doesEventExist(eventList, title))
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registerd, because there is already"
			" an event with the same name."
		);

		throw std::string("There is already an event with the same name");
	}

	// Add the event to the linked list
	if (eventList != nullptr)
	{
		eventList->addEvent(
			eventList, 
			Event(
				title, 
				period,coordinates, 
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
	loggerManager.log(LogSeverity::INFO, "Event with title: " + title + " is registerd successfully.");

	//Should be removed
	std::cout << "Event added successfully. All events data:\n\n";
	eventList->displayAllEvents(eventList);
	std::cout << std::endl;
}

void EventManager::addOtherEvent(
	std::string title, 
	std::vector<std::string> period, 
	Coordinates coordinates, 
	std::string additionalNotes
)
{
	LoggerManager loggerManager;
	loggerManager.log(LogSeverity::INFO, "Trying to add new event with title: " + title);

	// Validate the data
	if (title.size() == 0)
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registerd, because the title is NULL."
		);

		throw std::string("Title can not be empty!");
	}

	if (period.size() == 0)
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registerd, because the period is NULL."
		);

		throw std::string("Period can not be empty!");
	}

	// Check for duplicate names
	if (eventList->doesEventExist(eventList, title))
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Event with title: " +
			title +
			" can not be registerd, because there is already"
			" an event with the same name."
		);

		throw std::string("There is already an event with the same name");
	}

	// Add the event to the linked list
	if (eventList != nullptr)
	{
		eventList->addEvent(
			eventList,
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
	loggerManager.log(LogSeverity::INFO, "Event with title: " + title + " is registerd successfully.");

	//Should be removed
	std::cout << "Event added successfully. All events data:\n\n";
	eventList->displayAllEvents(eventList);
	std::cout << std::endl;
}

bool EventManager::removeEvent(EventList** head, std::string searchTitle)
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
			temp->event.title + 
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
				temp->event.title +
				" can not be deleted, because there is not an event with such title: " + 
				searchTitle
			);

			return false;
		}

		prev->next = temp->next;

		loggerManager.log(
			LogSeverity::INFO,
			"Event with title: " +
			temp->event.title +
			" is successfully deleted."
		);

		delete temp;
	}

	return true;
}

/*
template<typename T>
bool EventManager::editEvent(EventList* head, std::string searchTitle, std::string propertyToBeEdit, T newValue)
{
	EventList* temp = head;

	while (temp != NULL)
	{
		if (temp->event.title == searchTitle)
		{
			std::unordered_map<std::string, Event> map = temp->event;

			
			//std::cout << temp->event.propertyToBeEdit;// = static_cast<decltype(temp->event[propertyToBeEdit])>(newValue);
			return true;
		}
		temp = temp->next;
	}

	return false;
}
*/

std::vector<Event> EventManager::getAllEventsWithTitle(
	EventList* head, 
	std::string searchTitle
)
{
	LoggerManager loggerManager;
	std::vector<Event> returnValue;

	EventList* temp = head;

	loggerManager.log(LogSeverity::INFO, "Trying to get all events with title: " + searchTitle);

	while (temp != NULL)
	{
		if (temp->event.title.find(searchTitle) != std::string::npos)
		{
			returnValue.push_back(temp->event);
		}

		temp = temp->next;
	}

	loggerManager.log(LogSeverity::INFO, "Found " + std::to_string(returnValue.size()) + " events with title: " + searchTitle);
	return returnValue;
}

std::vector<Event> EventManager::getAllEventsWithDate(EventList* head, tm date)
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

	EventList* temp = head;

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
