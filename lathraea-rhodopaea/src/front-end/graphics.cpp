/*! @file graphics.cpp
*   @brief A source file for the graphics.
*/

#include <iostream>
#include <front-end/output.h>

enum CHARACTERS : char
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
	std::cout << "                         . " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " <<CHARACTERS::HORIZONTAL_LINE << " " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout <<CHARACTERS::HORIZONTAL_LINE << " " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE << " .                       . ";
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE << " " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " <<CHARACTERS::HORIZONTAL_LINE << " " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE << " " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " <<CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout <<CHARACTERS::HORIZONTAL_LINE << " ." << std::endl;
	outputPosition(4, 7);
	std::cout << "                   " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << " '                         " << "' ' " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << " .     . " <<CHARACTERS::HORIZONTAL_LINE << " ' '                         ' ";
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE << std::endl;
	outputPosition(4, 8);
	std::cout << "  " << CHARACTERS::DOUBLE_UPPER_LEFT_CORNER << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << " " <<CHARACTERS::HORIZONTAL_LINE << " " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " <<CHARACTERS::HORIZONTAL_LINE << " '                                      \\   /                                      ' ";
	std::cout <<CHARACTERS::HORIZONTAL_LINE << " " <<CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout <<CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_UPPER_RIGHT_CORNER << std::endl;
	outputPosition(4, 9);
	std::cout << CHARACTERS::UPPER_LEFT_CORNER <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_VERTICAL_LINE << "                                                      \\ /                                                      ";
	std::cout << CHARACTERS::DOUBLE_VERTICAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::UPPER_RIGHT_CORNER << std::endl;
	for (int i = 0; i < 29; i++)
	{
		outputPosition(4, 10 + i);
		std::cout << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::DOUBLE_VERTICAL_LINE;
		std::cout << "                                                       |                                                       ";
		std::cout << CHARACTERS::DOUBLE_VERTICAL_LINE << " " << CHARACTERS::VERTICAL_LINE << std::endl;
	}
	outputPosition(4, 39);
	std::cout << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                                                       |                                                       ";
	std::cout << CHARACTERS::DOUBLE_VERTICAL_LINE << " " << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 40);
	std::cout << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                   " << CHARACTERS::DOT << " ' " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " <<CHARACTERS::HORIZONTAL_LINE << " " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " <<CHARACTERS::HORIZONTAL_LINE << " " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " <<CHARACTERS::HORIZONTAL_LINE << " " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " <<CHARACTERS::HORIZONTAL_LINE << " " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << " ' " << CHARACTERS::DOT << " .         |         . " << CHARACTERS::DOT;
	std::cout << " ' " <<CHARACTERS::HORIZONTAL_LINE << " " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " <<CHARACTERS::HORIZONTAL_LINE << " " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " <<CHARACTERS::HORIZONTAL_LINE << " " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " <<CHARACTERS::HORIZONTAL_LINE << " " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " <<CHARACTERS::HORIZONTAL_LINE << " ' " << CHARACTERS::DOT;
	std::cout << "                   " << CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 41);
	std::cout << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "              " <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE << "   " << " ' " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE << " ' " << CHARACTERS::DOT;
	std::cout << " .    " <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::DOT << " .  |  . " << CHARACTERS::DOT << " ";
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE << "    . ";
	std::cout << CHARACTERS::DOT << " ' " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE << " '    " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << "              " << CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 42);
	std::cout << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::DOUBLE_LOWER_LEFT_CORNER;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << " " << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::DOUBLE_HORIZONTAL_LINE << " ";
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << " ' " << "                              ";
	std::cout <<CHARACTERS::HORIZONTAL_LINE << " " <<CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << CHARACTERS::DOT << " .  \\ | /  . " << CHARACTERS::DOT << " ";
	std::cout <<CHARACTERS::HORIZONTAL_LINE << " " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << "                     " << CHARACTERS::DOT << " " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " <<CHARACTERS::HORIZONTAL_LINE << " " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " <<CHARACTERS::HORIZONTAL_LINE << " ' " << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::DOUBLE_HORIZONTAL_LINE << " " << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_LOWER_RIGHT_CORNER;
	std::cout << " " << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 43);
	std::cout << CHARACTERS::LOWER_LEFT_CORNER <<CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 25; i++) {
		std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << " \\         / " <<CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 25; i++) {
		std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << CHARACTERS::LOWER_RIGHT_CORNER << std::endl;
	outputPosition(4, 44);
	std::cout << "                                                      ' ";
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE << " '" << std::endl;
}

/**
 * @brief Function for printing the book with only one page leafed
*/
void printOnePageLeafedBook()
{
	outputPosition(4, 6);
	std::cout << "                         . " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " <<CHARACTERS::HORIZONTAL_LINE << " " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout <<CHARACTERS::HORIZONTAL_LINE << " " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE << " .                       . ";
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE << " " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " <<CHARACTERS::HORIZONTAL_LINE << " " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE << " " <<CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout <<CHARACTERS::HORIZONTAL_LINE << " " <<CHARACTERS::HORIZONTAL_LINE << " ." << std::endl;
	outputPosition(4, 7);
	std::cout << "                   " <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE << " '                         " << "' ' ";
	std::cout <<CHARACTERS::HORIZONTAL_LINE << " .     . " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << " ' '                         ' " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE << std::endl;
	outputPosition(4, 8);
	std::cout << "  " << CHARACTERS::DOUBLE_UPPER_LEFT_CORNER << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << " " <<CHARACTERS::HORIZONTAL_LINE << " " <<CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout <<CHARACTERS::HORIZONTAL_LINE << " '                                      \\   /                                      ' ";
	std::cout <<CHARACTERS::HORIZONTAL_LINE << " " <<CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout <<CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_UPPER_RIGHT_CORNER << std::endl;
	outputPosition(4, 9);
	std::cout << CHARACTERS::UPPER_LEFT_CORNER <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_VERTICAL_LINE << "                                                      \\ /                                                      ";
	std::cout << CHARACTERS::DOUBLE_VERTICAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::UPPER_RIGHT_CORNER << std::endl;

	for (int i = 0; i < 29; i++)
	{
		outputPosition(4, 10 + i);
		std::cout << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::DOUBLE_VERTICAL_LINE;
		std::cout << "                                                       |                                                       ";
		std::cout << CHARACTERS::DOUBLE_VERTICAL_LINE << " " << CHARACTERS::VERTICAL_LINE << std::endl;
	}
	outputPosition(4, 39);
	std::cout << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                                                       |                                                       ";
	std::cout << CHARACTERS::DOUBLE_VERTICAL_LINE << " " << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 40);
	std::cout << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                                                       |         . ";
	std::cout << CHARACTERS::DOT << " ' " <<CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout <<CHARACTERS::HORIZONTAL_LINE << " " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " <<CHARACTERS::HORIZONTAL_LINE << " " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " <<CHARACTERS::HORIZONTAL_LINE << " " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " <<CHARACTERS::HORIZONTAL_LINE << " " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << " ' " << CHARACTERS::DOT << "                   " << CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << " " << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 41);
	std::cout << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "              " <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE << "   " << " ' " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE << "  " << CHARACTERS::DOT << " ";
	std::cout <<CHARACTERS::HORIZONTAL_LINE << " " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::DOT << " " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::DOT;
	std::cout << " .  |  . " << CHARACTERS::DOT << " " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE << "    . " << CHARACTERS::DOT << " ' ";
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << " '    " <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE << "              " << CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << " " << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 42);
	std::cout << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::DOUBLE_LOWER_LEFT_CORNER;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << " " << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::DOUBLE_HORIZONTAL_LINE << " " << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << " ' " << "                                       \\ | /  . " << CHARACTERS::DOT;
	std::cout << " " <<CHARACTERS::HORIZONTAL_LINE << " " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << "                     " << CHARACTERS::DOT << " " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " <<CHARACTERS::HORIZONTAL_LINE << " " <<CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " <<CHARACTERS::HORIZONTAL_LINE << " ' " << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::DOUBLE_HORIZONTAL_LINE << " " << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_LOWER_RIGHT_CORNER;
	std::cout << " " << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 43);
	std::cout << CHARACTERS::LOWER_LEFT_CORNER <<CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 25; i++) {
		std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << " \\         / " <<CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 25; i++) {
		std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << CHARACTERS::LOWER_RIGHT_CORNER << std::endl;
	outputPosition(4, 44);
	std::cout << "                                                      ' ";
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE <<CHARACTERS::HORIZONTAL_LINE;
	std::cout <<CHARACTERS::HORIZONTAL_LINE << " '" << std::endl;
}

/**
 * @brief Function for printing the first part of the book's leafing to the left
*/
void pageLeafingLeft1()
{
	outputPosition(4, 4);
	std::cout << "         /" << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 5);
	std::cout << "        " << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                           . ";
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::HORIZONTAL_LINE << " ." << std::endl;
	outputPosition(4, 6);
	std::cout << "        " << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::VERTICAL_LINE;
	for (int i = 0; i < 14; i++)
	{
		std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << CHARACTERS::HORIZONTAL_LINE << " .     . " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " ' '                         ' " << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << std::endl;
	outputPosition(4, 7);
	std::cout << "        " << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::VERTICAL_LINE;
	std::cout << "                                             \\   /                                      ' ";
	std::cout << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_UPPER_RIGHT_CORNER << std::endl;
	outputPosition(4, 8);
	std::cout << CHARACTERS::UPPER_LEFT_CORNER << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::VERTICAL_LINE;
	std::cout << "                                              \\ /                                                      ";
	std::cout << CHARACTERS::DOUBLE_VERTICAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::UPPER_RIGHT_CORNER << std::endl;
	for (int i = 0; i < 29; i++)
	{
		outputPosition(4, 9 + i);
		std::cout << CHARACTERS::VERTICAL_LINE << "       " << CHARACTERS::VERTICAL_LINE;
		std::cout << " " << CHARACTERS::VERTICAL_LINE << "                                               |                                                       ";
		std::cout << CHARACTERS::DOUBLE_VERTICAL_LINE << " " << CHARACTERS::VERTICAL_LINE << std::endl;
	}
	outputPosition(4, 38);
	std::cout << CHARACTERS::VERTICAL_LINE << "       " << CHARACTERS::VERTICAL_LINE;
	std::cout << " " << CHARACTERS::VERTICAL_LINE << "                                               |                                                       ";
	std::cout << CHARACTERS::DOUBLE_VERTICAL_LINE << " " << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 39);
	std::cout << CHARACTERS::VERTICAL_LINE << "       " << CHARACTERS::VERTICAL_LINE;
	std::cout << "/                                                |                                                       ";
	std::cout << CHARACTERS::DOUBLE_VERTICAL_LINE << " " << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 40);
	std::cout << CHARACTERS::VERTICAL_LINE << "        \\                                                |         . ";
	std::cout << CHARACTERS::DOT << " ' " << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << CHARACTERS::HORIZONTAL_LINE << " ' " << CHARACTERS::DOT << "                   ";
	std::cout << CHARACTERS::DOUBLE_VERTICAL_LINE << " " << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 41);
	std::cout << CHARACTERS::VERTICAL_LINE << "         '" << CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 8; i++)
	{
		std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << CHARACTERS::HORIZONTAL_LINE << "  " << CHARACTERS::DOT << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::DOT << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::DOT << " .  |  . " << CHARACTERS::DOT;
	std::cout << " " << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE << "    . ";
	std::cout << CHARACTERS::DOT << " ' " << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << " '    " << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << "              " << CHARACTERS::DOUBLE_VERTICAL_LINE << " " << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 42);
	std::cout << CHARACTERS::VERTICAL_LINE << "                                                       \\ | /  . ";
	std::cout << CHARACTERS::DOT << " " << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << "                     " << CHARACTERS::DOT << " " << CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << CHARACTERS::HORIZONTAL_LINE << " ' " << CHARACTERS::DOUBLE_HORIZONTAL_LINE << " ";
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << " " << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_LOWER_RIGHT_CORNER;
	std::cout << " " << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 43);
	std::cout << CHARACTERS::LOWER_LEFT_CORNER << CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 25; i++)
	{
		std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << " \\         / " << CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 25; i++)
	{
		std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << CHARACTERS::LOWER_RIGHT_CORNER << std::endl;
	outputPosition(4, 44);
	std::cout << "                                                      ' ";
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << " '" << std::endl;
}


/**
 * @brief Function for printing the first part of the book's leafing to the right
*/
void pageLeafingRight1()
{
	outputPosition(4, 5);
	std::cout << "                                                                                                           /";
	std::cout << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 6);
	std::cout << "                         . " << CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << " .                                                           ";
	std::cout << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 7);
	std::cout << "                   " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " '                         " << "' ' " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " .     . " << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 20; i++)
	{
		std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::VERTICAL_LINE;
	std::cout << " " << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 8);
	std::cout << "  " << CHARACTERS::DOUBLE_UPPER_LEFT_CORNER;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " '                                      \\   /                                             ";
	std::cout << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 9);
	std::cout << CHARACTERS::UPPER_LEFT_CORNER << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_VERTICAL_LINE << "                                                      \\ /                                              ";
	std::cout << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::VERTICAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::UPPER_RIGHT_CORNER << std::endl;

	for (int i = 0; i < 29; i++)
	{
		outputPosition(4, 10 + i);
		std::cout << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::DOUBLE_VERTICAL_LINE;
		std::cout << "                                                       |                                               ";
		std::cout << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::VERTICAL_LINE;
		std::cout << "       " << CHARACTERS::VERTICAL_LINE << std::endl;
	}
	outputPosition(4, 38);
	std::cout << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                                                       |                                               ";
	std::cout << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::VERTICAL_LINE;
	std::cout << "       " << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 39);
	std::cout << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                                                       |                                                \\";
	std::cout << CHARACTERS::VERTICAL_LINE << "       " << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 40);
	std::cout << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                   " << CHARACTERS::DOT << " ' ";
	std::cout << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::HORIZONTAL_LINE << " ' " << CHARACTERS::DOT;
	std::cout << " .         |                                                /        ";
	std::cout << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 41);
	std::cout << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "              " << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << "   " << " ' " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << " ' " << CHARACTERS::DOT;
	std::cout << " .    " << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::DOT << " .  |  . " << CHARACTERS::DOT << " ";
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::DOT << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::DOT;
	std::cout << "  " << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 13; i++)
	{
		std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << CHARACTERS::HORIZONTAL_LINE << "'         ";
	std::cout << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 42);
	std::cout << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::DOUBLE_LOWER_LEFT_CORNER;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << " " << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::DOUBLE_HORIZONTAL_LINE << " " << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << " ' " << "                              " << CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::DOT << " .  \\ | /                                                       ";
	std::cout << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 43);
	std::cout << CHARACTERS::LOWER_LEFT_CORNER << CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 25; i++)
	{
		std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << " \\         / " << CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 25; i++)
	{
		std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << CHARACTERS::LOWER_RIGHT_CORNER << std::endl;
	outputPosition(4, 44);
	std::cout << "                                                      ' ";
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << " '" << std::endl;
}

/**
 * @brief Function for printing the second part of the book's leafing to the left
*/
void pageLeafingLeft2()
{
	outputPosition(4, 1);
	std::cout << "                         /" << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 2);
	std::cout << "                        / " << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 3);
	std::cout << "                       /  " << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 4);
	std::cout << "                      /   " << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 5);
	std::cout << "                     /    " << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 6);
	std::cout << "                    " << CHARACTERS::DOT << "     " << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 7);
	std::cout << "                    " << CHARACTERS::VERTICAL_LINE << "     ";
	std::cout << CHARACTERS::VERTICAL_LINE << "                                           . ";
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " ." << std::endl;
	outputPosition(4, 8);
	std::cout << "                    " << CHARACTERS::VERTICAL_LINE << "     ";
	std::cout << CHARACTERS::VERTICAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 13; i++)
	{
		std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << " .     . " << CHARACTERS::HORIZONTAL_LINE << " ' '                         ' ";
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << std::endl;
	outputPosition(4, 9);
	std::cout << "                    " << CHARACTERS::VERTICAL_LINE << "     ";
	std::cout << CHARACTERS::VERTICAL_LINE << "                             \\   /                                      ' ";
	std::cout << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_UPPER_RIGHT_CORNER << std::endl;
	outputPosition(4, 10);
	std::cout << CHARACTERS::UPPER_LEFT_CORNER << CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 9; i++)
	{
		std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << CHARACTERS::VERTICAL_LINE << "     " << CHARACTERS::VERTICAL_LINE;
	std::cout << "                              \\ /                                                      ";
	std::cout << CHARACTERS::DOUBLE_VERTICAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::UPPER_RIGHT_CORNER << std::endl;

	for (int i = 0; i < 23; i++)
	{
		outputPosition(4, 11 + i);
		std::cout << CHARACTERS::VERTICAL_LINE << "                   ";
		std::cout << CHARACTERS::VERTICAL_LINE << "     ";
		std::cout << CHARACTERS::VERTICAL_LINE << "                               |                                                       ";
		std::cout << CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
		std::cout << CHARACTERS::VERTICAL_LINE << std::endl;
	}
	outputPosition(4, 33);
	std::cout << CHARACTERS::VERTICAL_LINE << "                   ";
	std::cout << CHARACTERS::VERTICAL_LINE << "     " << CHARACTERS::VERTICAL_LINE;
	std::cout << "                               |                                                       ";
	std::cout << CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 34);
	std::cout << CHARACTERS::VERTICAL_LINE << "                   ";
	std::cout << CHARACTERS::VERTICAL_LINE << "    .'";
	std::cout << "                               |                                                       ";
	std::cout << CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 35);
	std::cout << CHARACTERS::VERTICAL_LINE << "                   ";
	std::cout << CHARACTERS::VERTICAL_LINE << "  " << CHARACTERS::DOT;
	std::cout << "'                                 |                                                       ";
	std::cout << CHARACTERS::DOUBLE_VERTICAL_LINE << " " << CHARACTERS::VERTICAL_LINE;
	std::cout << std::endl;
	outputPosition(4, 36);
	std::cout << CHARACTERS::VERTICAL_LINE << "                   ";
	std::cout << CHARACTERS::VERTICAL_LINE << " /                                   |                                                       ";
	std::cout << CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 37);
	std::cout << CHARACTERS::VERTICAL_LINE << "                   ";
	std::cout << CHARACTERS::VERTICAL_LINE << "/                                    |                                                       ";
	std::cout << CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 38);
	std::cout << CHARACTERS::VERTICAL_LINE;
	std::cout << "                    \\                                    |                                                       ";
	std::cout << CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 39);
	std::cout << CHARACTERS::VERTICAL_LINE << "                     \\                                   |                                                       ";
	std::cout << CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 40);
	std::cout << CHARACTERS::VERTICAL_LINE << "                      '";
	std::cout << CHARACTERS::DOT << "_                                |         . ";
	std::cout << CHARACTERS::DOT << " ' " << CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " ' " << CHARACTERS::DOT << "                   " << CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << " " << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 41);
	std::cout << CHARACTERS::VERTICAL_LINE << "                         '";
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << "  " << CHARACTERS::DOT;
	std::cout << " " << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::DOT << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::DOT << " .  |  . ";
	std::cout << CHARACTERS::DOT << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << "    . " << CHARACTERS::DOT << " ' ";
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " '    " << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << "              ";
	std::cout << CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 42);
	std::cout << CHARACTERS::VERTICAL_LINE << "                                                       \\ | /  . ";
	std::cout << CHARACTERS::DOT << " " << CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << CHARACTERS::HORIZONTAL_LINE << "                     ";
	std::cout << CHARACTERS::DOT << " " << CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::HORIZONTAL_LINE << " ' " << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::DOUBLE_HORIZONTAL_LINE << " " << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_LOWER_RIGHT_CORNER;
	std::cout << " " << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 43);
	std::cout << CHARACTERS::LOWER_LEFT_CORNER << CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 25; i++)
	{
		std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << " \\         / " << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 24; i++)
	{
		std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::LOWER_RIGHT_CORNER << std::endl;
	outputPosition(4, 44);
	std::cout << "                                                      ' ";
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << " '" << std::endl;
}

/**
 * @brief Function for printing the second part of the book's leafing to the right
*/
void pageLeafingRight2()
{
	outputPosition(4, 1);
	std::cout << "                                                                                         ";
	std::cout << CHARACTERS::VERTICAL_LINE << "\\" << std::endl;
	outputPosition(4, 2);
	std::cout << "                                                                                         ";
	std::cout << CHARACTERS::VERTICAL_LINE << " \\" << std::endl;
	outputPosition(4, 3);
	std::cout << "                                                                                         ";
	std::cout << CHARACTERS::VERTICAL_LINE << "  \\" << std::endl;
	std::cout << "                                                                                         ";
	std::cout << CHARACTERS::VERTICAL_LINE << "   \\" << std::endl;
	outputPosition(4, 4);
	std::cout << "                                                                                         ";
	std::cout << CHARACTERS::VERTICAL_LINE << "    \\" << std::endl;
	outputPosition(4, 5);
	std::cout << "                                                                                         ";
	std::cout << CHARACTERS::VERTICAL_LINE << "     \\" << std::endl;
	outputPosition(4, 6);
	std::cout << "                                                                                         ";
	std::cout << CHARACTERS::VERTICAL_LINE << "      " << CHARACTERS::DOT << std::endl;
	outputPosition(4, 7);
	std::cout << "                         . " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << " .                                          ";
	std::cout << CHARACTERS::VERTICAL_LINE << "      " << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 8);
	std::cout << "                   " << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << " '                         " << "' ' ";
	std::cout << CHARACTERS::HORIZONTAL_LINE << " .     . " << CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 12; i++)
	{
		std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::VERTICAL_LINE;
	std::cout << "      " << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 9);
	std::cout << "  " << CHARACTERS::DOUBLE_UPPER_LEFT_CORNER;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " '                                      \\   /                            ";
	std::cout << CHARACTERS::VERTICAL_LINE << "      " << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 10);
	std::cout << CHARACTERS::UPPER_LEFT_CORNER << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_VERTICAL_LINE << "                                                      \\ /                             ";
	std::cout << CHARACTERS::VERTICAL_LINE << "      " << CHARACTERS::VERTICAL_LINE;
	for (int i = 0; i < 9; i++)
	{
		std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::UPPER_RIGHT_CORNER << std::endl;
	for (int i = 0; i < 24; i++)
	{
		outputPosition(4, 11 + i);
		std::cout << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::DOUBLE_VERTICAL_LINE;
		std::cout << "                                                       |                              ";
		std::cout << CHARACTERS::VERTICAL_LINE << "      " << CHARACTERS::VERTICAL_LINE;
		std::cout << "                   " << CHARACTERS::VERTICAL_LINE << std::endl;
	}
	outputPosition(4, 34);
	std::cout << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                                                       |                              ";
	std::cout << CHARACTERS::VERTICAL_LINE << "      " << CHARACTERS::VERTICAL_LINE;
	std::cout << "                   " << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 35);
	std::cout << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                                                       |                               '.    ";
	std::cout << CHARACTERS::VERTICAL_LINE << "                   ";
	std::cout << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 36);
	std::cout << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                                                       |                                 '.  ";
	std::cout << CHARACTERS::VERTICAL_LINE << "                   ";
	std::cout << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 37);
	std::cout << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                                                       |                                   \\ ";
	std::cout << CHARACTERS::VERTICAL_LINE << "                   ";
	std::cout << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 38);
	std::cout << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                                                       |                                    \\";
	std::cout << CHARACTERS::VERTICAL_LINE << "                   ";
	std::cout << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 39);
	std::cout << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                                                       |                                    /                    ";
	std::cout << CHARACTERS::VERTICAL_LINE << std::endl;
	std::cout << "                                                       |                                   /                     ";
	std::cout << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 40);
	std::cout << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                   " << CHARACTERS::DOT << " ' " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " ' " << CHARACTERS::DOT << " .         |                                _";
	std::cout << CHARACTERS::DOT << "'                      ";
	std::cout << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 41);
	std::cout << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "              " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << "   " << " ' " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << " ' " << CHARACTERS::DOT;
	std::cout << " .    " << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::DOT << " .  |  . " << CHARACTERS::DOT;
	std::cout << " " << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::DOT << " " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::DOT;
	std::cout << "  " << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << "'                         ";
	std::cout << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 42);
	std::cout << CHARACTERS::VERTICAL_LINE << " " << CHARACTERS::DOUBLE_LOWER_LEFT_CORNER;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << " ";
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << " ";
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << " ";
	std::cout << CHARACTERS::DOUBLE_HORIZONTAL_LINE << " ' ";
	std::cout << "                              " << CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << CHARACTERS::HORIZONTAL_LINE << " " << CHARACTERS::DOT;
	std::cout << " .  \\ | /                                                       ";
	std::cout << CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(4, 43);
	std::cout << CHARACTERS::LOWER_LEFT_CORNER << CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 25; i++)
	{
		std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << " \\         / " << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 24; i++)
	{
		std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::LOWER_RIGHT_CORNER << std::endl;
	outputPosition(4, 44);
	std::cout << "                                                      ' ";
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << CHARACTERS::HORIZONTAL_LINE;
	std::cout << CHARACTERS::HORIZONTAL_LINE << " '" << std::endl;
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
