/*! @file datetimeManager.h
*   @brief A header file for the date managing system.
*/

#pragma once
#include <time.h>
#include <string>
#include <vector>

/**
 * @brief Struct for date manager
*/
struct DateManager
{
	/**
	 * @brief Function for converting string to date(tm)
	 * @param dateInString Date in format of string
	 * @return Date in format of tm struct
	*/
	tm convertStringToDate(std::string dateInString);

	/**
	 * @brief Function for converting vector of strings to vector of dates(tm)
	 * @param dates Vector of strings
	 * @return Vector of tm struct
	*/
	std::vector<tm> converVectorOfStringsToVectorOfDate(std::vector<std::string> dates);

	/**
	 * @brief Function for counting leap years to given date
	 * @param d Date
	 * @return Number of leap years prior to this one
	*/
	int countLeapYears(tm d);
	
	/**
	 * @brief Function that return the number of days between two given dates
	 * @param dt1 The first date
	 * @param dt2 The second date
	 * @return Number of dates betwen the two dates
	*/
	int getDifference(tm dt1, tm dt2);

	/**
	 * @brief Function for checking if two dates are in order
	 * @param firstDate The first date
	 * @param secondDate The second date
	 * @return Are the two dates in order
	*/
	bool areDatesInOrder(tm firstDate, tm secondDate);

	/**
	 * @brief Function for checking if a date is betwen two other dates
	 * @param firstDate The first date
	 * @param middleDate The moddle date
	 * @param lastDate The last date
	 * @return Is the middle date betwen two other dates
	*/
	bool isDateBetweenTwoDates(tm firstDate, tm middleDate, tm lastDate);
};

extern DateManager dm;