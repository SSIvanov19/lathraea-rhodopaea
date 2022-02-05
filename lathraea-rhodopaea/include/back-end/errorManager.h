/*! @file errorManager.cpp
*   @brief A source file for the logs.
*/

#pragma once

#include <string>
#include <Windows.h>

/**
 * @brief Struct that will be used when there is an exception
*/
struct ErrorHandler
{
	std::string fileName; /*!< The name of the file at which the exception happened */
	std::string functionName; /*!< The name of the function at which the exception happened */
	DWORD errorCode; /*!< Code of the error */
	std::string errorMsg; /*!< Message of the error */

	/**
	 * @brief Constructor for an exception
	 * @param fileName_ The name of the file at which the exception happened
	 * @param functionName_ The name of the function at which the exception happened
	 * @param errorCode_ Code of the error
	*/
	ErrorHandler(
		std::string fileName_,
		std::string functionName_,
		DWORD errorCode_
	);

	/**
	 * @brief Constructor for an exception
	 * @param fileName_ The name of the file at which the exception happened
	 * @param functionName_ The name of the function at which the exception happened
	 * @param errorMsg_ Message of the error
	*/
	ErrorHandler(
		std::string fileName_,
		std::string functionName_,
		std::string errorMsg_
	);
};