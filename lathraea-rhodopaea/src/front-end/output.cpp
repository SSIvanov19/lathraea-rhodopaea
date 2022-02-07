/*! @file output.cpp
*   @brief A source file for setting the output color and position.
*/
#include <windows.h>

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