#pragma once
#include <string>
#include <vector>
#include <time.h>
#include <back-end/eventManager.h>
#include <back-end/logs.h>

/**
 * @brief Struct for a storyline
*/
struct Storyline
{
	std::string title; //!< Title of the storyline
	std::vector<Event> events; //!< Events in the storyline
	std::string desc; //!< Description of the storyline

	/**
	 * @brief Constructor for the storyline
	 * @param title_ Title of the storyline
	 * @param events_ Events in the storyline
	 * @param desc_ Description of the storyline
	*/
	Storyline(
		std::string title_,
		std::vector<Event> events_,
		std::string desc_ = ""
	);

	/**
	 * @brief Default constructor for the storyline
	*/
	Storyline();

	// This shouldn't be here
	void displayStoryline();
};

/**
 * @brief A structure for a linked list that holds all of the storylines 
*/
struct StorylineList
{
	Storyline storyline; //!< The data of the storyline
	StorylineList* next = nullptr; //!< The next node

	/**
	 * @brief A constructor for StorylineList
	 * @param event_ The data of the storyline
	 * @param next_ A pointer to the next storyline
	*/
	StorylineList(Storyline storyline_, StorylineList* next_);

	/**
	 * @brief Function for adding a storyline
	 * @param head The head of the list
	 * @param data The data of the storyline
	*/
	void addStoryline(StorylineList* head, Storyline data);

	/**
	 * @brief Function for adding a storyline at the begging of the list
	 * @param head The head of the list
	 * @param data The data of the storyline
	*/
	void insertStorylineAtFront(StorylineList** head, Storyline data);

	/**
	 * @brief Function for checking if there is already a storyline with the same name
	 * @param head The head of the list
	 * @param titleToCheck Title of the storyline to be checked
	*/
	bool doesStorylineExist(StorylineList* head, std::string titleToCheck);

	// Only for debugging purposes
	// Should not be used in the final product
	void displayAllStorylines(StorylineList* head);
};

/**
 * @brief Struct for an storyline manager
*/
struct StorylineManager
{
	StorylineList* storylineList = nullptr; /*!< List with all storylines */
	
	/**
	 * @brief Function for adding a storyline
	 * @param title Title of the storyline
	 * @param events Events that are included in the storyline
	 * @param desc Description of the event
	*/
	void addStoryline(
		std::string title,
		std::vector<Event> events,
		std::string desc = ""
	);
};