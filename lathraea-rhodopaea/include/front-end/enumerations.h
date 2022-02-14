/*! @file enumerations.h
*   @brief A header file for the enumerations used in the front-end
*/
#pragma once

/**
 * Enumeration representing the ASCII characters' codes
*/
enum class CHARACTERS
{
	DOT = 250, /*Space dot*/
	BLOCK = 219, /*Block*/
	T = 194, /*T*/
	ROTATED_T = 193, /*Rotated T*/
	HORIZONTAL_LINE = 196,  /*Horizontal line */
	VERTICAL_LINE = 179, /*Vertical line*/
	DOUBLE_HORIZONTAL_LINE = 205, /*Double horizontal line*/
	DOUBLE_VERTICAL_LINE = 186, /*Double vertical line*/
	UPPER_LEFT_CORNER = 218, /*Upper left corner*/
	UPPER_RIGHT_CORNER = 191, /*Upper right corner*/
	LOWER_LEFT_CORNER = 192, /*Lower left corner*/
	LOWER_RIGHT_CORNER = 217, /*Lower right corner*/
	DOUBLE_UPPER_LEFT_CORNER = 201, /*Double upper left corner*/
	DOUBLE_UPPER_RIGHT_CORNER = 187, /*Double upper right corner*/
	DOUBLE_LOWER_LEFT_CORNER = 200, /*Double lower left corner*/
	DOUBLE_LOWER_RIGHT_CORNER = 188, /*Double lower rigt corner*/
};

/**
 * Enumeration representing the color codes
*/
enum class COLORS
{
	DARK_BLUE = 1,
	DARK_GREEN = 2,
	DARK_CYAN = 3,
	DARK_RED = 4,
	DARK_MAGENTA = 5,
	DARK_YELLOW = 6,
	DIRTY_WHITE = 7,
	GRAY = 8,
	BLUE = 9,
	GREEN = 10,
	CYAN = 11,
	RED = 12,
	MAGENTA = 13,
	YELLOW = 14,
	WHITE = 15,
};

/**
 * @brief Enumeration representing the keys' codes
*/
enum class ARROW_KEYS
{
	KEY_UP = 72,
	KEY_DOWN = 80,
	KEY_LEFT = 77,
	KEY_RIGHT = 75,
	KEY_ENTER = '\r',
	KEY_ESC = 27
};