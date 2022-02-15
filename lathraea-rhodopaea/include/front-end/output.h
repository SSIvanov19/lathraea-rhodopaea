/*! @file output.h
*   @brief A header file for setting the output color and position.
*/
#pragma once
#include <windows.h>
#include <string>

void outputPosition(int x, int y); // Function for setting the output position
void setConsoleColorTo(int color); // Function for setting the output color
void setCursorVisibilityTo(bool shown); // Function for showing/hideing the cursor
void clearConsole();