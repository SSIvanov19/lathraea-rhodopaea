/*! @file logs.h
*   @brief A header file for the logs.
*/

#pragma once
#include <string>
#include <time.h>
#include <iostream>
#include <fstream>
#include <iomanip>

/**
 * @brief Enum that holds all the log severities
*/
enum class LogSeverity
{
	EMERG = 0, /*!< Emergency - System is unusable */
	ALERT = 1, /*!< Alert - Action must be taken immediately */
	CRIT = 2, /*!< Critical - Critical conditions */
	ERR = 3, /*!< Error - Error conditions */
	WARNING = 4, /*!< Warning - Warning conditions */
	NOTICE = 5, /*!< Notice - Normal but significant conditions */
	INFO = 6, /*!< Informational - Informational messages conditions */
	DEBUG = 7 /*!< Debug - Debug-level messages */
};

/**
 * @brief A struct that holds the functions for logging.
*/
struct LoggerManager
{
	/**
	 * @brief Function that logs
	 * @param msg Message to be logged
	*/
	void log(LogSeverity levelOfLog, std::string msg);
};