/*! @file graphics.cpp
*   @brief A source file for the graphics.
*/

#include <iostream>
#include <front-end/output.h>

enum class CHARACTERS
{
	DOT = 250, /*Space dot*/
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
 * @brief Function for printing the opened book
*/
void printOpenedBook()
{ 
	outputPosition(4, 6);
	std::cout << "                         . " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " .                       . ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " ." << std::endl;
	outputPosition(4, 7);
	std::cout << "                   " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " '                         " << "' ' " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " .     . " << (char)CHARACTERS::HORIZONTAL_LINE << " ' '                         ' ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << std::endl;
	outputPosition(4, 8);
	std::cout << "  " << (char)CHARACTERS::DOUBLE_UPPER_LEFT_CORNER << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " '                                      \\   /                                      ' ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_UPPER_RIGHT_CORNER << std::endl;
	outputPosition(4, 9);
	std::cout << (char)CHARACTERS::UPPER_LEFT_CORNER << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << "                                                      \\ /                                                      ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::UPPER_RIGHT_CORNER << std::endl;
	for (int i = 0; i < 29; i++)
	{
		outputPosition(4, 10 + i);
		std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
		std::cout << "                                                       |                                                       ";
		std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	}
	outputPosition(4, 39);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                                                       |                                                       ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 40);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                   " << (char)CHARACTERS::DOT << " ' " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " ' " << (char)CHARACTERS::DOT << " .         |         . " << (char)CHARACTERS::DOT;
	std::cout << " ' " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ' " << (char)CHARACTERS::DOT;
	std::cout << "                   " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 41);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "              " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << "   " << " ' " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " ' " << (char)CHARACTERS::DOT;
	std::cout << " .    " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::DOT << " .  |  . " << (char)CHARACTERS::DOT << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE << "    . ";
	std::cout << (char)CHARACTERS::DOT << " ' " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " '    " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << "              " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 42);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_LOWER_LEFT_CORNER;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << " " << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << " ' " << "                              ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOT << " .  \\ | /  . " << (char)CHARACTERS::DOT << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << "                     " << (char)CHARACTERS::DOT << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ' " << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << " " << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_LOWER_RIGHT_CORNER;
	std::cout << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 43);
	std::cout << (char)CHARACTERS::LOWER_LEFT_CORNER << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 25; i++) {
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << " \\         / " << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 25; i++) {
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::LOWER_RIGHT_CORNER << std::endl;
	outputPosition(4, 44);
	std::cout << "                                                      ' ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " '" << std::endl;
}

/**
 * @brief Function for printing the book with only one page leafed
*/
void printOnePageLeafedBook()
{
	outputPosition(4, 6);
	std::cout << "                         . " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " .                       . ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ." << std::endl;
	outputPosition(4, 7);
	std::cout << "                   " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " '                         " << "' ' ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " .     . " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " ' '                         ' " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE << std::endl;
	outputPosition(4, 8);
	std::cout << "  " << (char)CHARACTERS::DOUBLE_UPPER_LEFT_CORNER << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " '                                      \\   /                                      ' ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_UPPER_RIGHT_CORNER << std::endl;
	outputPosition(4, 9);
	std::cout << (char)CHARACTERS::UPPER_LEFT_CORNER << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << "                                                      \\ /                                                      ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::UPPER_RIGHT_CORNER << std::endl;

	for (int i = 0; i < 29; i++)
	{
		outputPosition(4, 10 + i);
		std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
		std::cout << "                                                       |                                                       ";
		std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	}
	outputPosition(4, 39);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                                                       |                                                       ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 40);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                                                       |         . ";
	std::cout << (char)CHARACTERS::DOT << " ' " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " ' " << (char)CHARACTERS::DOT << "                   " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 41);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "              " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << "   " << " ' " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << "  " << (char)CHARACTERS::DOT << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::DOT << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::DOT;
	std::cout << " .  |  . " << (char)CHARACTERS::DOT << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << "    . " << (char)CHARACTERS::DOT << " ' ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " '    " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << "              " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 42);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_LOWER_LEFT_CORNER;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << " " << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << " " << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << " ' " << "                                       \\ | /  . " << (char)CHARACTERS::DOT;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << "                     " << (char)CHARACTERS::DOT << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ' " << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << " " << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_LOWER_RIGHT_CORNER;
	std::cout << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 43);
	std::cout << (char)CHARACTERS::LOWER_LEFT_CORNER << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 25; i++) {
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << " \\         / " << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 25; i++) {
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::LOWER_RIGHT_CORNER << std::endl;
	outputPosition(4, 44);
	std::cout << "                                                      ' ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " '" << std::endl;
}

/**
 * @brief Function for printing the first part of the book's leafing to the left
*/
void pageLeafingLeft1()
{
	outputPosition(4, 4);
	std::cout << "         /" << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 5);
	std::cout << "        " << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                           . ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ." << std::endl;
	outputPosition(4, 6);
	std::cout << "        " << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE;
	for (int i = 0; i < 14; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " .     . " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " ' '                         ' " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << std::endl;
	outputPosition(4, 7);
	std::cout << "        " << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                             \\   /                                      ' ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_UPPER_RIGHT_CORNER << std::endl;
	outputPosition(4, 8);
	std::cout << (char)CHARACTERS::UPPER_LEFT_CORNER << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                              \\ /                                                      ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::UPPER_RIGHT_CORNER << std::endl;
	for (int i = 0; i < 29; i++)
	{
		outputPosition(4, 9 + i);
		std::cout << (char)CHARACTERS::VERTICAL_LINE << "       " << (char)CHARACTERS::VERTICAL_LINE;
		std::cout << " " << (char)CHARACTERS::VERTICAL_LINE << "                                               |                                                       ";
		std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	}
	outputPosition(4, 38);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "       " << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << " " << (char)CHARACTERS::VERTICAL_LINE << "                                               |                                                       ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 39);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "       " << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "/                                                |                                                       ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 40);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "        \\                                                |         . ";
	std::cout << (char)CHARACTERS::DOT << " ' " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " ' " << (char)CHARACTERS::DOT << "                   ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 41);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "         '" << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 8; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << "  " << (char)CHARACTERS::DOT << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::DOT << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::DOT << " .  |  . " << (char)CHARACTERS::DOT;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE << "    . ";
	std::cout << (char)CHARACTERS::DOT << " ' " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " '    " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << "              " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 42);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                                                       \\ | /  . ";
	std::cout << (char)CHARACTERS::DOT << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << "                     " << (char)CHARACTERS::DOT << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " ' " << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << " " << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_LOWER_RIGHT_CORNER;
	std::cout << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 43);
	std::cout << (char)CHARACTERS::LOWER_LEFT_CORNER << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 25; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << " \\         / " << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 25; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::LOWER_RIGHT_CORNER << std::endl;
	outputPosition(4, 44);
	std::cout << "                                                      ' ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " '" << std::endl;
}


/**
 * @brief Function for printing the first part of the book's leafing to the right
*/
void pageLeafingRight1()
{
	outputPosition(4, 5);
	std::cout << "                                                                                                           /";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 6);
	std::cout << "                         . " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " .                                                           ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 7);
	std::cout << "                   " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " '                         " << "' ' " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " .     . " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 20; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 8);
	std::cout << "  " << (char)CHARACTERS::DOUBLE_UPPER_LEFT_CORNER;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " '                                      \\   /                                             ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 9);
	std::cout << (char)CHARACTERS::UPPER_LEFT_CORNER << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << "                                                      \\ /                                              ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::UPPER_RIGHT_CORNER << std::endl;

	for (int i = 0; i < 29; i++)
	{
		outputPosition(4, 10 + i);
		std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
		std::cout << "                                                       |                                               ";
		std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE;
		std::cout << "       " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	}
	outputPosition(4, 38);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                                                       |                                               ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "       " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 39);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                                                       |                                                \\";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "       " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 40);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                   " << (char)CHARACTERS::DOT << " ' ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ' " << (char)CHARACTERS::DOT;
	std::cout << " .         |                                                /        ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 41);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "              " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << "   " << " ' " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " ' " << (char)CHARACTERS::DOT;
	std::cout << " .    " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::DOT << " .  |  . " << (char)CHARACTERS::DOT << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::DOT << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::DOT;
	std::cout << "  " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 13; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << "'         ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 42);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_LOWER_LEFT_CORNER;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << " " << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << " " << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << " ' " << "                              " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::DOT << " .  \\ | /                                                       ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 43);
	std::cout << (char)CHARACTERS::LOWER_LEFT_CORNER << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 25; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << " \\         / " << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 25; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::LOWER_RIGHT_CORNER << std::endl;
	outputPosition(4, 44);
	std::cout << "                                                      ' ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " '" << std::endl;
}

/**
 * @brief Function for printing the second part of the book's leafing to the left
*/
void pageLeafingLeft2()
{
	outputPosition(4, 1);
	std::cout << "                         /" << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 2);
	std::cout << "                        / " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 3);
	std::cout << "                       /  " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 4);
	std::cout << "                      /   " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 5);
	std::cout << "                     /    " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 6);
	std::cout << "                    " << (char)CHARACTERS::DOT << "     " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 7);
	std::cout << "                    " << (char)CHARACTERS::VERTICAL_LINE << "     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                                           . ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " ." << std::endl;
	outputPosition(4, 8);
	std::cout << "                    " << (char)CHARACTERS::VERTICAL_LINE << "     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 13; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << " .     . " << (char)CHARACTERS::HORIZONTAL_LINE << " ' '                         ' ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << std::endl;
	outputPosition(4, 9);
	std::cout << "                    " << (char)CHARACTERS::VERTICAL_LINE << "     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                             \\   /                                      ' ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_UPPER_RIGHT_CORNER << std::endl;
	outputPosition(4, 10);
	std::cout << (char)CHARACTERS::UPPER_LEFT_CORNER << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 9; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "     " << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                              \\ /                                                      ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::UPPER_RIGHT_CORNER << std::endl;

	for (int i = 0; i < 23; i++)
	{
		outputPosition(4, 11 + i);
		std::cout << (char)CHARACTERS::VERTICAL_LINE << "                   ";
		std::cout << (char)CHARACTERS::VERTICAL_LINE << "     ";
		std::cout << (char)CHARACTERS::VERTICAL_LINE << "                               |                                                       ";
		std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
		std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	}
	outputPosition(4, 33);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                   ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "     " << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                               |                                                       ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 34);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                   ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "    .'";
	std::cout << "                               |                                                       ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 35);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                   ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "  " << (char)CHARACTERS::DOT;
	std::cout << "'                                 |                                                       ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << std::endl;
	outputPosition(4, 36);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                   ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " /                                   |                                                       ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 37);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                   ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "/                                    |                                                       ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 38);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                    \\                                    |                                                       ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 39);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                     \\                                   |                                                       ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 40);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                      '";
	std::cout << (char)CHARACTERS::DOT << "_                                |         . ";
	std::cout << (char)CHARACTERS::DOT << " ' " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " ' " << (char)CHARACTERS::DOT << "                   " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 41);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                         '";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << "  " << (char)CHARACTERS::DOT;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::DOT << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::DOT << " .  |  . ";
	std::cout << (char)CHARACTERS::DOT << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << "    . " << (char)CHARACTERS::DOT << " ' ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " '    " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << "              ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 42);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                                                       \\ | /  . ";
	std::cout << (char)CHARACTERS::DOT << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << "                     ";
	std::cout << (char)CHARACTERS::DOT << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ' " << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << " " << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_LOWER_RIGHT_CORNER;
	std::cout << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 43);
	std::cout << (char)CHARACTERS::LOWER_LEFT_CORNER << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 25; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << " \\         / " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 24; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::LOWER_RIGHT_CORNER << std::endl;
	outputPosition(4, 44);
	std::cout << "                                                      ' ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " '" << std::endl;
}

/**
 * @brief Function for printing the second part of the book's leafing to the right
*/
void pageLeafingRight2()
{
	outputPosition(4, 1);
	std::cout << "                                                                                         ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "\\" << std::endl;
	outputPosition(4, 2);
	std::cout << "                                                                                         ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " \\" << std::endl;
	outputPosition(4, 3);
	std::cout << "                                                                                         ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "  \\" << std::endl;
	std::cout << "                                                                                         ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "   \\" << std::endl;
	outputPosition(4, 4);
	std::cout << "                                                                                         ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "    \\" << std::endl;
	outputPosition(4, 5);
	std::cout << "                                                                                         ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "     \\" << std::endl;
	outputPosition(4, 6);
	std::cout << "                                                                                         ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "      " << (char)CHARACTERS::DOT << std::endl;
	outputPosition(4, 7);
	std::cout << "                         . " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " .                                          ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "      " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 8);
	std::cout << "                   " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " '                         " << "' ' ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " .     . " << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 12; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "      " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 9);
	std::cout << "  " << (char)CHARACTERS::DOUBLE_UPPER_LEFT_CORNER;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " '                                      \\   /                            ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "      " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 10);
	std::cout << (char)CHARACTERS::UPPER_LEFT_CORNER << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << "                                                      \\ /                             ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "      " << (char)CHARACTERS::VERTICAL_LINE;
	for (int i = 0; i < 9; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::UPPER_RIGHT_CORNER << std::endl;
	for (int i = 0; i < 24; i++)
	{
		outputPosition(4, 11 + i);
		std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
		std::cout << "                                                       |                              ";
		std::cout << (char)CHARACTERS::VERTICAL_LINE << "      " << (char)CHARACTERS::VERTICAL_LINE;
		std::cout << "                   " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	}
	outputPosition(4, 34);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                                                       |                              ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "      " << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                   " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 35);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                                                       |                               '.    ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                   ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 36);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                                                       |                                 '.  ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                   ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 37);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                                                       |                                   \\ ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                   ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 38);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                                                       |                                    \\";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                   ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 39);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                                                       |                                    /                    ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	std::cout << "                                                       |                                   /                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 40);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                   " << (char)CHARACTERS::DOT << " ' " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " ' " << (char)CHARACTERS::DOT << " .         |                                _";
	std::cout << (char)CHARACTERS::DOT << "'                      ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 41);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "              " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << "   " << " ' " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " ' " << (char)CHARACTERS::DOT;
	std::cout << " .    " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::DOT << " .  |  . " << (char)CHARACTERS::DOT;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::DOT << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::DOT;
	std::cout << "  " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << "'                         ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 42);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_LOWER_LEFT_CORNER;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << " ' ";
	std::cout << "                              " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::DOT;
	std::cout << " .  \\ | /                                                       ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 43);
	std::cout << (char)CHARACTERS::LOWER_LEFT_CORNER << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 25; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << " \\         / " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 24; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::LOWER_RIGHT_CORNER << std::endl;
	outputPosition(4, 44);
	std::cout << "                                                      ' ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " '" << std::endl;
}

/**
 * @brief Function for printing a sword with a snake
*/
void printSnakeSword()
{
	std::cout << "                               ,-." << std::endl;
	std::cout << "                              (\"O_)" << std::endl;
	std::cout << "                             / `-/" << std::endl;
	std::cout << "                            /-. /" << std::endl;
	std::cout << "                           /   )" << std::endl;
	std::cout << "                          /   /  " << std::endl;
	std::cout << "              _          /-. /" << std::endl;
	std::cout << "             (_)\"-.._   /   )" << std::endl;
	std::cout << "              \"-._   '\"\"( )/    " << std::endl;
	std::cout << "                   \"-/\"-._\"`. " << std::endl;
	std::cout << "                    /     \"-.'._" << std::endl;
	std::cout << "                   /\\       /-._\"-._" << std::endl;
	std::cout << "    _,---...__    /  ) _,-\"/    \"-(_)" << std::endl;
	std::cout << "___<__(|) _   \"\"-/  / /   /" << std::endl;
	std::cout << " '  `----' \"\"-.   \\/ /   /" << std::endl;
	std::cout << "               )  ] /   /" << std::endl;
	std::cout << "       ____..-'   //   /                       )" << std::endl;
	std::cout << "   ,-\"\"      __.,'/   /   ___                 /" << std::endl;
	std::cout << "  /    ,--\"\"/  / /   /,-\"\"   \"\"\"-          ,'/" << std::endl;
	std::cout << " [    (    /  / /   /  ,.---,_   `._   _,-','" << std::endl;
	std::cout << "  \\    `-./  / /   /  /       `-._  \"\"\"_.-'" << std::endl;
	std::cout << "   `-._  /  / /   /_,'            \"\"--\"" << std::endl;
	std::cout << "       \"/  / /   /\"         " << std::endl;
	std::cout << "       /  / /   /" << std::endl;
	std::cout << "      /  / /   /  " << std::endl;
	std::cout << "     /  |,'   /  " << std::endl;
	std::cout << "    :   /    /" << std::endl;
	std::cout << "    [  /   ,'  " << std::endl;
	std::cout << "    | /  ,'" << std::endl;
	std::cout << "    |/,-'" << std::endl;
	std::cout << "    /" << std::endl;
}

/**
 * @brief Function for printing the map of Bulgaria
*/
void printBulgarianMap()
{
	outputPosition(9, 4);
	std::cout << "  .-.                                                     _.--._" << std::endl;
	outputPosition(9, 5);
	std::cout << " _|  \\_                                              _.-'       ._   _" << std::endl;
	outputPosition(9, 6);
	std::cout << "/    .-'  _                                       .'              '-' '" << std::endl;
	outputPosition(9, 7);
	std::cout << "|    '-.-' '-._       _                        _.'                     '----'." << std::endl;
	outputPosition(9, 8);
	std::cout << " \\             '-.--.' '-.._._       _______.'                               \\" << std::endl;
	outputPosition(9, 9);
	std::cout << "  |                            '-_.-'                                    _.._/" << std::endl;
	outputPosition(9, 10);
	std::cout << "   \\_                                                                 .'" << std::endl;
	outputPosition(9, 11);
	std::cout << "     \\                                                              _.'" << std::endl;
	outputPosition(9, 12);
	std::cout << "      \\_                                                           '." << std::endl;
	outputPosition(9, 13);
	std::cout << "        |                                                         _.'" << std::endl;
	outputPosition(9, 14);
	std::cout << "        '.                                                         '." << std::endl;
	outputPosition(9, 15);
	std::cout << "       .'                                                           '." << std::endl;
	outputPosition(9, 16);
	std::cout << "      _/                                                            _'" << std::endl;
	outputPosition(9, 17);
	std::cout << "  .-_/                                                            .'" << std::endl;
	outputPosition(9, 18);
	std::cout << "  '.                                                             .'" << std::endl;
	outputPosition(9, 19);
	std::cout << "   /_                                                           .'" << std::endl;
	outputPosition(9, 20);
	std::cout << "   _/                                                           '-" << std::endl;
	outputPosition(9, 21);
	std::cout << "   \\.                                                    _._     '-." << std::endl;
	outputPosition(9, 22);
	std::cout << "     '--.                                             .-'    '-.    '-." << std::endl;
	outputPosition(9, 23);
	std::cout << "        |_                                           /         '-._.-.-'" << std::endl;
	outputPosition(9, 24);
	std::cout << "          '-.                                     _.'" << std::endl;
	outputPosition(9, 25);
	std::cout << "          .'                                   .-'" << std::endl;
	outputPosition(9, 26);
	std::cout << "          |        ._..-.-.                   '-." << std::endl;
	outputPosition(9, 27);
	std::cout << "         .'   ._.-'       '-._._              _.'" << std::endl;
	outputPosition(9, 28);
	std::cout << "        '__.-'                  '.    _._.'.-'" << std::endl;
	outputPosition(9, 29);
	std::cout << "                                  '-.'" << std::endl;
}

/**
 * @brief Function for printing a pop-up tab
*/
void printPopUp()
{
	outputPosition(5, 1);
	std::cout << (char)CHARACTERS::UPPER_LEFT_CORNER << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 20; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::UPPER_RIGHT_CORNER << std::endl;

	outputPosition(5, 2);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                                       X  " << (char)CHARACTERS::VERTICAL_LINE << std::endl;

	for (int i = 0; i < 7; i++)
	{
		outputPosition(5, 3 + i);
		std::cout << (char)CHARACTERS::VERTICAL_LINE << "                                          " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	}

	outputPosition(5, 10);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                                          " << (char)CHARACTERS::VERTICAL_LINE << std::endl;

	outputPosition(5, 11);
	std::cout << (char)CHARACTERS::LOWER_LEFT_CORNER << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 20; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::LOWER_RIGHT_CORNER << std::endl;
}

/**
 * @brief Function for printing a pop-up tab for the map
*/
void printMapPopUp()
{
	outputPosition(5, 1);
	std::cout << (char)CHARACTERS::UPPER_LEFT_CORNER << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 42; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::UPPER_RIGHT_CORNER << std::endl;

	outputPosition(5, 2);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                                                                                   X  " << (char)CHARACTERS::VERTICAL_LINE << std::endl;

	for (int i = 0; i < 28; i++)
	{
		outputPosition(5, 3 + i);
		std::cout << (char)CHARACTERS::VERTICAL_LINE << "                                                                                      " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	}

	outputPosition(5, 31);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                                                                                      " << (char)CHARACTERS::VERTICAL_LINE << std::endl;

	outputPosition(5, 32);
	std::cout << (char)CHARACTERS::LOWER_LEFT_CORNER << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 42; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::LOWER_RIGHT_CORNER << std::endl;
}

/**
 * @brief Function for printing a timeline
*/
void printTimeline() // Example
{
	outputPosition(4, 3);
	std::cout << "                    1987            1876            1967            1432" << std::endl;
	outputPosition(4, 4);
	std::cout << "                     v               v               v               v" << std::endl;
	outputPosition(4, 5);
	std::cout << "         />__________________________________________________________________" << std::endl;
	outputPosition(4, 6);
	std::cout << "[########[]__________________________________________________________________>" << std::endl;
	outputPosition(4, 7);
	std::cout << "         \\>" << std::endl;
	outputPosition(4, 8);
	std::cout << "                           ^               ^                ^" << std::endl;
	outputPosition(4, 9);
	std::cout << "                          1987            1876             1967" << std::endl;
}

/**
 * @brief Function for printing a timeline
*/
void printTimeLine1() // Example
{
	outputPosition(4, 3);
	std::cout << "                   1987            1876             1967" << std::endl;
	outputPosition(4, 4);
	std::cout << "                    v               v                v" << std::endl;
	outputPosition(4, 5);
	std::cout << "              /\\                               ______,....----," << std::endl;
	outputPosition(4, 6);
	std::cout << "/VVVVVVVVVVVVVV|===================\"\"\"\"\"\"\"\"\"\"\"\"       ___,..-' " << std::endl;
	outputPosition(4, 7);
	std::cout << "`^^^^^^^^^^^^^^|======================----------\"\"\"\"\"\"" << std::endl;
	outputPosition(4, 8);
	std::cout << "              \\/" << std::endl;
	outputPosition(4, 9);
	std::cout << "                    ^               ^                ^" << std::endl;
	outputPosition(4, 10);
	std::cout << "                   1987            1876             1967" << std::endl;
}