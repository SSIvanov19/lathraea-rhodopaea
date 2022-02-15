/*! @file output.cpp
*   @brief A source file for setting the output color and position.
*/

#include <back-end/errorManager.h>

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
 * @brief A function that get the output handle.
 * @return HANDLE
*/
HANDLE getOutputHandle()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	if (checkForInvalidHandle(handle))
	{
		throw ErrorHandler("output.cpp", "getOutputHandle()", GetLastError());
	}

	return handle;
}


/**
 * @brief Function for setting the output position
 * @param x The X coordinates
 * @param y The Y coordinates
*/
void outputPosition(int x, int y)
{
	HANDLE STD_OUTPUT = getOutputHandle();
	COORD cords;
	cords.X = x;
	cords.Y = y;

	if (SetConsoleCursorPosition(STD_OUTPUT, cords) == 0)
	{
		throw ErrorHandler("output.cpp", "outputPosition()", GetLastError());
	}
}

/**
 * @brief Function for setting the output color
 * @param color The set color
*/
void setConsoleColorTo(int color)
{
	HANDLE STD_OUTPUT = getOutputHandle();
	
	if (SetConsoleTextAttribute(STD_OUTPUT, color) == 0)
	{
		throw ErrorHandler("output.cpp", "setConsoleColorTo()", GetLastError());
	}
}



void setCursorVisibilityTo(bool shown)
{
	HANDLE consoleHandle = getOutputHandle();
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = shown;

	if (SetConsoleCursorInfo(consoleHandle, &info) == 0)
	{
		throw ErrorHandler("output.cpp", "SetConsoleCursorInfo()", GetLastError());
	}
}

void clearConsole()
{
	COORD topLeft = { 0, 0 };
	HANDLE console = getOutputHandle();
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	if (GetConsoleScreenBufferInfo(console, &screen) == 0)
	{
		throw ErrorHandler("output.cpp", "setCursorVisibilityTo()", GetLastError());
	}

	if (FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	) == 0)
	{
		throw ErrorHandler("output.cpp", "setCursorVisibilityTo()", GetLastError());
	}

	if (FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	) == 0)
	{
		throw ErrorHandler("output.cpp", "setCursorVisibilityTo()", GetLastError());
	}

	outputPosition(topLeft.X, topLeft.Y);
}