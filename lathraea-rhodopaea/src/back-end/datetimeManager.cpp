/*! @file datetimeManager.cpp
*   @brief A source file for the date managing system.
*/

#include <back-end/datetimeManager.h>
#include <external/strptime.h>

tm DateManager::convertStringToDate(std::string dateInString)
{
	struct tm tm;

	if (strptime(dateInString.c_str(), "%d %b %Y", &tm) == NULL)
	{
		throw std::string("Problem with converting date from string to tm");
	}

	return tm;
}

std::vector<tm> DateManager::converVectorOfStringsToVectorOfDate(std::vector<std::string> dates)
{
	std::vector<tm> returnVal;

	for (std::string date: dates)
	{
		returnVal.push_back(convertStringToDate(date));
	}

	return returnVal;
}

int DateManager::countLeapYears(tm d)
{
	int years = d.tm_year + 1900;

	// Check if the current year needs to be
	//  considered for the count of leap years
	// or not
	if (d.tm_mon + 1 <= 2)
	{
		years--;
	}

	// An year is a leap year if it
	// is a multiple of 4,
	// multiple of 400 and not a
	 // multiple of 100.
	return years / 4
		- years / 100
		+ years / 400;
}

int DateManager::getDifference(tm dt1, tm dt2)
{
	const int monthDays[12]
		= { 31, 28, 31, 30, 31, 30,
		   31, 31, 30, 31, 30, 31 };

	// COUNT TOTAL NUMBER OF DAYS
	// BEFORE FIRST DATE 'dt1'

	// initialize count using years and day
	long int n1 = (dt1.tm_year + 1900) * 365 + dt1.tm_mday;

	// Add days for months in given date
	for (int i = 0; i < dt1.tm_mon; i++)
	{
		n1 += monthDays[i];
	}

	// Since every leap year is of 366 days,
	// Add a day for every leap year
	n1 += countLeapYears(dt1);

	// SIMILARLY, COUNT TOTAL NUMBER OF
	// DAYS BEFORE 'dt2'
	long int n2 = (dt2.tm_year + 1900) * 365 + dt2.tm_mday;

	for (int i = 0; i < dt2.tm_mon; i++)
	{
		n2 += monthDays[i];
	}

	n2 += countLeapYears(dt2);

	// return difference between two counts
	return (n2 - n1);
}

bool DateManager::areDatesInOrder(tm firstDate, tm secondDate)
{
	if ((firstDate.tm_year + 1900) < (secondDate.tm_year + 1900))
	{
		return true;
	}

	if (firstDate.tm_year == secondDate.tm_year)
	{
		if (firstDate.tm_mon < secondDate.tm_mon)
		{
			return true;
		}
	}

	if (firstDate.tm_mon == secondDate.tm_mon)
	{
		if (firstDate.tm_mday < secondDate.tm_mday)
		{
			return true;
		}
	}

	return false;

}

bool DateManager::isDateBetweenTwoDates(tm firstDate, tm middleDate, tm lastDate)
{
	if ((middleDate.tm_year - firstDate.tm_year) *
		(middleDate.tm_year - lastDate.tm_year) <= 0)
	{
		return true;
	}

	if (firstDate.tm_year == middleDate.tm_year)
	{
		return areDatesInOrder(firstDate, middleDate);
	}

	if (middleDate.tm_year == lastDate.tm_year)
	{
		return areDatesInOrder(middleDate, lastDate);
	}

	return false;
}
