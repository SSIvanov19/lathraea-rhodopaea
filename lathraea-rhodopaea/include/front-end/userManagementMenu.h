/*! @file userManagementMenu.h
*   @brief A header file for the user management menu handaling system.
*/

#pragma once
#include <iostream>
#include <conio.h>
#include <back-end/accountSystem.h>

/**
 * @brief Function for registering an admin
 * @param accountManager Account manager
*/
void addNewAdmin(AccountManager* accountManager);

/**
 * @brief Function for showing user's info
 * @param account 
 * @param accountManager 
*/
void showUserInfo(Account account, AccountManager* accountManager);

/**
 * @brief Function for displaying all users
 * @param accountManager Account manager
*/
void viewAllUsers(AccountManager* accountManager);