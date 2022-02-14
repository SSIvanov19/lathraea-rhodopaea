/*! @file application.h
*   @brief A header file for the application.
*/

#pragma once
#include <back-end/accountSystem.h>
#include <back-end/eventManager.h>
#include <back-end/datetimeManager.h>
#include <back-end/logs.h>
#include <back-end/errorManager.h>
#include <iostream>
#include <vector>
#include <string>
#include <iostream>

/**
 * @brief Main struct for the applications
*/
struct Application
{
	/**
	 * @brief Account manager
	*/
	AccountManager accountManager;

	/**
	 * @brief Event manager
	*/
	EventManager eventManager;

	/**
	 * @brief Logger manager
	*/
	LoggerManager loggerManager;

	/**
	 * @brief Function for initialising
	 * @param accountManager Account manager
	 * @param eventManager Event manager
	*/
	void init(AccountManager& accountManager, EventManager& eventManager);

	/**
	 * @brief Entry point for the application
	 * @param accountManager Account manager
	 * @param eventManager Event manager
	*/
	void run(AccountManager& accountManager, EventManager& eventManager);
};