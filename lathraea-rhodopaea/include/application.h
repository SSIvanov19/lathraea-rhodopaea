/*! @file application.h
*   @brief A header file for the application.
*/

#pragma once
#include <back-end/accountSystem.h>
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
	 * @brief Entry point for the application
	 * @param accountManager Account manager
	*/
	void run(AccountManager accountManager); /*!< entry point for the application */
};