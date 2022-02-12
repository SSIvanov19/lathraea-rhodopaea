/*! @file output.cpp
*   @brief A source file for setting the output color and position.
*/
#include <windows.h>
#include <string>

/**
 * @brief Function for setting the output position
 * @param x The X coordinates
 * @param y The Y coordinates
*/
void outputPosition(int x, int y)
{
	COORD position;
	position.X = x;
	position.Y = y;
	if (SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position))
	{
		return;
	}
	else {}
}

/**
 * @brief Function for setting the output color
 * @param color The set color
*/
void color(int color)
{
	if (SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color))
	{
		return;
	}
	else {}
}

/**
 * @brief Check if the output that was returned from getOutputHandle() is INVALID_HANDLE_VALUE.
 * @param handle The handle given from getOutputHandle()
 * @return bool Is the handle invalid
*/
bool checkForInvalidHandle(HANDLE handle)
{
	return handle == INVALID_HANDLE_VALUE;
}

/**
 * @brief Function for showing/hideing the cursor
 * @param shown bool show/hide
*/
void setCursor(bool shown)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = shown;

	if (SetConsoleCursorInfo(consoleHandle, &info) == 0)
	{
		//Add error handaling
	}
}