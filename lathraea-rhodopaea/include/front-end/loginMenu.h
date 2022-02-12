/*! @file login.h
*   @brief A header file for the login and register menu options
*/

#pragma once

#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <back-end/accountSystem.h>

std::vector<std::string> enterRegisterData(); // Function for entering and validating regitestration data
void registerUser(AccountManager* accountManager); // Function for registrating user
std::vector<std::string> enterLoginData(); // Function for loging in user
bool isUserLogedIn(AccountManager* accountManager); // Function for loging in user
bool switchLoginOptions(AccountManager* accountManager, char key, int& selectedOption, std::vector<std::string> possibleOptions); // Function for coloring hovered login/register options
void accountMenu(AccountManager accountManager); // Function for login and register
