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
	AccountManager accountManager; /*!< Account manager */

	/**
	 * @brief Event manager
	*/
	EventManager eventManager; /*!< Event manager */

	/**
	 * @brief Logger manager
	*/
	LoggerManager loggerManager; /*!< Logger manager */

	/**
	 * @brief Entry point for the application
	 * @param accountManager Account manager
	*/
	void run(AccountManager accountManager, EventManager eventManager); /*!< entry point for the application */
};