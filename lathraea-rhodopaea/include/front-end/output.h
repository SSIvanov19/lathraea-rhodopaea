/*! @file output.h
*   @brief A header file for setting the output color and position.
*/
#pragma once
#include <windows.h>
#include <string>

/**
 * @brief Function for setting the output position
 * @param x X coordinate
 * @param y Y coordinate
*/
void outputPosition(int x, int y);

/**
 * @brief Function for setting the output color
 * @param color The code of the color
*/
void setConsoleColorTo(int color);

/**
 * @brief Function for showing/hideing the cursor
 * @param shown is shown
*/
void setCursorVisibilityTo(bool shown); 

/**
 * @brief Function for clearing the console
*/
void clearConsole();