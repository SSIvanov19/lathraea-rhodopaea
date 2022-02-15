#include <back-end/storylineManager.h>

Storyline::Storyline(
	std::string title_,
	std::vector<Event> events_,
	std::string desc_
)
{
	title = title_;
	events = events_;
	desc = desc_;
	isApproved = false;
}

Storyline::Storyline() = default;

void Storyline::displayStoryline()
{
	std::cout << "Storyline title: " << title << std::endl;
	std::cout << "Events: " << std::endl;

	for (Event event : events)
	{
		std::cout << "Event title: " << event.title << std::endl;
	}

	std::cout << "Storyline description: " << desc << std::endl;
}

StorylineList::StorylineList(Storyline storyline_, StorylineList* next_)
{
	storyline = storyline_;
	next = next_;
}

void StorylineList::addStoryline(StorylineList* head, Storyline data)
{
	StorylineList* newNode = new StorylineList(data, nullptr);

	StorylineList* temp = head;

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

void StorylineList::insertStorylineAtFront(StorylineList** head, Storyline data)
{
	StorylineList* newNode = new StorylineList(data, *head);

	*head = newNode;
}

bool StorylineList::doesStorylineExist(StorylineList* head, std::string titleToCheck)
{
	StorylineList* temp = head;

	while (temp != NULL)
	{
		if (temp->storyline.title == titleToCheck)
		{

			return true;
		}
		temp = temp->next;
	}

	return false;
}

void StorylineManager::addStoryline(
	std::string title,
	std::vector<Event> events, 
	std::string desc
)
{
	LoggerManager loggerManager;
	loggerManager.log(LogSeverity::INFO, "Trying to add new storyline with title: " + title);


	// Validate the data
	if (title.size() == 0)
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Storyline with title: " +
			title +
			" can not be registered, because the title is NULL."
		);

		throw std::string("Title can not be empty!");
	}

	if (events.size() == 0)
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Storyline with title: " +
			title +
			" can not be registered, because the events is NULL."
		);

		throw std::string("Events can not be empty!");
	}

	// Check for duplicate names
	if (storylineList->doesStorylineExist(storylineList, title))
	{
		loggerManager.log(
			LogSeverity::NOTICE,
			"Storyline with title: " +
			title +
			" can not be registered, because there is already"
			" an storyline with the same name."
		);

		throw std::string("There is already an storyline with the same name");
	}

	// Add the storyline to the linked list
	if (storylineList != nullptr)
	{
		storylineList->addStoryline(
			storylineList,
			Storyline(
				title,
				events,
				desc
			)
		);
	}
	else
	{
		storylineList->insertStorylineAtFront(
			&storylineList,
			Storyline(
				title,
				events,
				desc
			)
		);
	}

	// Log
	loggerManager.log(
		LogSeverity::INFO,
		"Storyline with title: " + title + " is registered successfully."
	);
}

bool StorylineManager::removeStoryline(StorylineList** head, std::string searchTitle)
{
	LoggerManager loggerManager;

	StorylineList* temp = *head;
	StorylineList* prev = NULL;

	if (temp != NULL && temp->storyline.title == searchTitle)
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
		while (temp != NULL && temp->storyline.title != searchTitle)
		{
			prev = temp;
			temp = temp->next;
		}

		if (temp == NULL)
		{
			loggerManager.log(
				LogSeverity::NOTICE,
				"Storyline with title: " +
				searchTitle +
				" can not be deleted, because there is not a Storyline with such title."
			);

			return false;
		}

		prev->next = temp->next;

		loggerManager.log(
			LogSeverity::INFO,
			"Storyline with title: " +
			searchTitle +
			" is successfully deleted."
		);

		delete temp;
	}

	return true;
}

void StorylineManager::approveStoryline(std::string title)
{
	LoggerManager loggerManager;
	StorylineList* temp = this->storylineList;

	loggerManager.log(
		LogSeverity::INFO,
		"Looking to approve storyline with title: " + title
	);

	while (temp)
	{
		if (temp->storyline.title == title)
		{
			temp->storyline.isApproved = true;

			loggerManager.log(
				LogSeverity::INFO,
				"Storyline with title: " + title + " is successfully approved."
			);

			return;
		}

		temp = temp->next;
	}

	loggerManager.log(
		LogSeverity::NOTICE,
		"There is no storyline with title: " + title
	);

	throw std::string("There is no storyline with such title: " + title);
}

std::vector<Storyline> StorylineManager::getAllStorylines(bool isApproved)
{
	LoggerManager loggerManager;
	std::vector<Storyline> returnVal;

	StorylineList* temp = this->storylineList;

	loggerManager.log(
		LogSeverity::INFO,
		"Getting all Storylines that are " +
		isApproved ? "approved." : "unapproved."
	);

	while (temp)
	{
		if (temp->storyline.isApproved == isApproved)
		{
			returnVal.push_back(temp->storyline);
		}

		temp = temp->next;
	}

	loggerManager.log(
		LogSeverity::INFO,
		"Found " + std::to_string(returnVal.size()) +
		" storylines that are " + (isApproved ? "approved." : "unapproved.")
	);

	return returnVal;
}
