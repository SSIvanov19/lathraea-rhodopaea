#pragma once
#include <string>
#include <vector>

/**
 * @brief Function for checking whether the month is entered correctly
 * @param month The month that needs to be checked
 * @return true/false
*/
bool isValidMonthName(std::string month);

/**
 * @brief Function for checking whether the day is in range
 * @param day A day that needs to be checked
 * @return true/false
*/
bool isDayInRange(std::string day);

/**
 * @brief Function for checking whether the date is entered in the correct way
 * @param str The string containing the date/s
 * @return true/false
*/
bool checkDatesValidation(std::string str);

/**
 * @brief Function for passing the date/s as vector
 * @param str The string containing the date/s
 * @return The date/s as vector
*/
std::vector <std::string> separateDates(std::string str);

/**
 * @brief Function for converting information in vector to string
 * @param information Given vector
 * @return Information as string
*/
std::string separate(const std::vector<std::string> information);