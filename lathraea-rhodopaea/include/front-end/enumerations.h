/*! @file enumerations.h
*   @brief A header file for the enumerations used in the front-end
*/
#pragma once

/**
 * Enumeration representing the ASCII characters' codes
*/
enum class CHARACTERS
{

	DOT = 250, /*!< Space dot */
	BLOCK = 219, /*!< Block */
	T = 194, /*!< T */
	ROTATED_T = 193, /*!< Rotated T */
	HORIZONTAL_LINE = 196,  /*!< Horizontal line */
	VERTICAL_LINE = 179, /*!< Vertical line */
	DOUBLE_HORIZONTAL_LINE = 205, /*!< Double horizontal line */
	DOUBLE_VERTICAL_LINE = 186, /*!< Double vertical line */
	UPPER_LEFT_CORNER = 218, /*!< Upper left corner */
	UPPER_RIGHT_CORNER = 191, /*!< Upper right corner */
	LOWER_LEFT_CORNER = 192, /*!< Lower left corner */
	LOWER_RIGHT_CORNER = 217, /*!< Lower right corner */
	DOUBLE_UPPER_LEFT_CORNER = 201, /*!< Double upper left corner */
	DOUBLE_UPPER_RIGHT_CORNER = 187, /*!< Double upper right corner */
	DOUBLE_LOWER_LEFT_CORNER = 200, /*!< Double lower left corner */
	DOUBLE_LOWER_RIGHT_CORNER = 188, /*!< Double lower right corner */
};

/**
 * Enumeration representing the color codes
*/
enum class COLORS
{
	DARK_BLUE = 1, /*!< Dark Blue */
	DARK_GREEN = 2, /*!< Dark Green */
	DARK_CYAN = 3, /*!< Dark Cyan */
	DARK_RED = 4, /*!< Dark Red */
	DARK_MAGENTA = 5, /*!< Dark Magenta */
	DARK_YELLOW = 6, /*!< Dark yellow */
	DIRTY_WHITE = 7, /*!< Dirty white */
	GRAY = 8, /*!< Gray */
	BLUE = 9, /*!< Blue */
	GREEN = 10, /*!< Green */
	CYAN = 11, /*!< Cyan */
	RED = 12, /*!< Red */
	MAGENTA = 13, /*!< Magenta */
	YELLOW = 14, /*!< Yellow */
	WHITE = 15, /*!< White */
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