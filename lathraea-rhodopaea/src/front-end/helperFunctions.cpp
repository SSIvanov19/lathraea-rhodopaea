/*! @file helperFunctions.cpp
*   @brief A source file with a bunch of small helper functions.
*/

#include <front-end/helperFunctions.h>

bool isValidMonthName(std::string month)
{
	std::string months[12] = {
		"jan", "feb", "mar",
		"apr", "may", "jun",
		"jul", "aug", "sep",
		"oct", "nov", "dec"
	};

	for (size_t i = 0; i < 12; i++)
	{
		if (month == months[i])
		{
			return true;
		}
	}

	return false;
}

bool isDayInRange(std::string day)
{
	if (stoi(day) >= 1 && stoi(day) <= 31)
	{
		return true;
	}
	return false;
}

bool checkDatesValidation(std::string str)
{
	bool twoDates = false;
	int whiteSpaces = 0;

	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == ',')
		{
			twoDates = true;
		}
		if (str[i] == ' ')
		{
			whiteSpaces++;
		}
	}

	if (whiteSpaces != 5 && twoDates == 1)
	{
		return false;
	}

	if (whiteSpaces != 2 && twoDates == 0)
	{
		return false;
	}

	whiteSpaces = 0;

	std::string day, month, year, dayTwo, monthTwo, yearTwo;

	for (size_t i = 0; i < str.size(); i++)
	{

		if (str[i] == ' ')
		{
			whiteSpaces++;
			continue;
		}

		if (whiteSpaces == 0)
		{
			day += str[i];
		}
		if (whiteSpaces == 1)
		{
			month += str[i];
		}
		if (whiteSpaces == 2)
		{
			year += str[i];
		}

		if (twoDates)
		{
			if (whiteSpaces == 3)
			{
				dayTwo += str[i];
			}
			if (whiteSpaces == 4)
			{
				monthTwo += str[i];
			}
			if (whiteSpaces == 5)
			{
				yearTwo += str[i];
			}
		}

	}

	if (!isDayInRange(day))
	{
		return false;
	}

	if (twoDates && !isDayInRange(dayTwo))
	{
		return false;
	}

	if (!isValidMonthName(month) || (!isValidMonthName(monthTwo) && twoDates))
	{
		return false;
	}

	return true;
}

std::vector <std::string> separateDates(std::string str)
{
	std::string startDate;
	std::string endDate;
	std::string day, month, year, dayTwo, monthTwo, yearTwo;

	std::vector <std::string> dates;

	bool twoDates = false;
	int whiteSpaces = 0;

	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == ',')
		{
			twoDates = true;
		}
	}

	for (size_t i = 0; i < str.size(); i++)
	{

		if (str[i] == ' ')
		{
			whiteSpaces++;
			continue;
		}

		if (str[i] != ',')
		{
			if (whiteSpaces == 0)
			{
				day += str[i];
			}
			if (whiteSpaces == 1)
			{
				month += str[i];
			}
			if (whiteSpaces == 2)
			{
				year += str[i];
			}
		}

		if (twoDates)
		{
			if (whiteSpaces == 3)
			{
				dayTwo += str[i];
			}
			if (whiteSpaces == 4)
			{
				monthTwo += str[i];
			}
			if (whiteSpaces == 5)
			{
				yearTwo += str[i];
			}
		}

	}

	startDate += day + ' ' + month + ' ' + year;
	endDate += dayTwo + ' ' + monthTwo + ' ' + yearTwo;

	if (twoDates)
	{
		dates.push_back(startDate);
		dates.push_back(endDate);
	}
	else
	{
		dates.push_back(startDate);
	}
	return dates;
}

std::string separate(const std::vector<std::string> information)
{
	std::string result = " ";

	for (size_t i = 0; i < information.size(); i++)
	{
		result += information[i];
		result += ", ";
	}

	return result;
}