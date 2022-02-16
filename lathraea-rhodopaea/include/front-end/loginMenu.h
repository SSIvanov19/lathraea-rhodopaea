/*! @file login.h
*   @brief A header file for the login and register menu options
*/

#pragma once

#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <back-end/accountSystem.h>

/**
 * @brief Function for entering and validating registration data.
 * @return Vector with email and password
*/
std::vector<std::string> enterRegisterData();

/**
 * @brief Function for registering user.
 * @param accountManager Account manager
*/
void registerUser(AccountManager* accountManager);

/**
 * @brief Function for loging in user.
 * @return Vector with email and password
*/
std::vector<std::string> enterLoginData(); 

/**
 * @brief Function for loging in user.
 * @param accountManager 
 * @return 
*/
bool isUserLogedIn(AccountManager* accountManager);

/**
 * @brief Function for switching hovered login/register options.
 * @param accountManager Account manager
 * @param key Key
 * @param selectedOption Selected options
 * @param possibleOptions Possible options
 * @return Is login successful
*/
bool switchLoginOptions(
	AccountManager* accountManager,
	char key, 
	int& selectedOption,
	std::vector<std::string> possibleOptions
); 

/**
 * @brief Function for handaling account menu
 * @param accountManager Account manager
*/
void accountMenu(AccountManager& accountManager);
