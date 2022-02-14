/*! @file graphics.cpp
*   @brief A source file for the graphics.
*/

#include <iostream>
#include <front-end/output.h>
#include <front-end/enumerations.h>

/**
 * @brief Function for printing closed book.
*/
void printClosedBook()
{
	int counter = 5;
	outputPosition(77, counter + 1);
	std::cout << (char)CHARACTERS::UPPER_LEFT_CORNER;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::T;
	for (int i = 0; i < 48; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::UPPER_RIGHT_CORNER << std::endl;
	outputPosition(77, counter + 2);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_UPPER_RIGHT_CORNER << std::endl;
	outputPosition(77, counter + 3);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::UPPER_RIGHT_CORNER << std::endl;
	outputPosition(77, counter + 4);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 5);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 6);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 7);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 8);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 9);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 10);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 11);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 12);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 13);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 14);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 15);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 16);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 17);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 18);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 19);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 20);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 21);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 22);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 23);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 24);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 25);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 26);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 27);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 28);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 29);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 30);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 31);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 32);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 33);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 34);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 35);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 36);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::ROTATED_T;
	for (int i = 0; i < 48; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::LOWER_RIGHT_CORNER << " ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 37);
	std::cout << "( .";
	for (int i = 0; i < 53; i++)
	{
		std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::DOUBLE_LOWER_RIGHT_CORNER;
	std::cout << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 38);
	std::cout << " ";
	for (int i = 0; i < 57; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::LOWER_RIGHT_CORNER << std::endl;
}

/**
 * @brief Function for printing slightly open book.
*/
void printSlightlyOpenBook()
{
	int counter = 2;
	outputPosition(77, counter);
	std::cout << "                            . " << (char)CHARACTERS::DOT;
	std::cout << " " << (char)CHARACTERS::DOT << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::UPPER_RIGHT_CORNER << std::endl;
	outputPosition(77, counter + 1);
	std::cout << "                      . " << (char)CHARACTERS::DOT;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << "       " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 2);
	std::cout << "               . " << (char)CHARACTERS::DOT << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << "              " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 3);
	std::cout << "         . " << (char)CHARACTERS::DOT << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << "                    " << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << "." << std::endl;
	outputPosition(77, counter + 4);
	std::cout << "  . " << (char)CHARACTERS::DOT << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << "                           ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	for (int i = 0; i < 4; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << std::endl;
	outputPosition(77, counter + 5);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                  ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "     ' ";
	for (int i = 0; i < 3; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	}
	for (int i = 0; i < 7; i++)
	{
		std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	}
	std::cout << char(187) << std::endl;
	outputPosition(77, counter + 6);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                  ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                    ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::UPPER_RIGHT_CORNER << std::endl;

	for (int i = 0; i < 28; i++)
	{
		outputPosition(77, counter + 7 + i);
		std::cout << (char)CHARACTERS::VERTICAL_LINE << "                                  ";
		std::cout << (char)CHARACTERS::VERTICAL_LINE << "                    ";
		std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
		std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	}
	outputPosition(77, counter + 35);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                           . ";
	std::cout << (char)CHARACTERS::DOT << " " << (char)CHARACTERS::DOT << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::LOWER_RIGHT_CORNER;
	std::cout << "                    " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 36);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                     . ";
	std::cout << (char)CHARACTERS::DOT << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << "                            ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 37);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "              . ";
	std::cout << (char)CHARACTERS::DOT << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << "                                   ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 38);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "          " << (char)CHARACTERS::DOT;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << "                                         ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 39);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "  . " << (char)CHARACTERS::DOT;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << "                                               ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 40);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << (char)CHARACTERS::DOT << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << "                            " << (char)CHARACTERS::DOT << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " ' ";
	for (int i = 0; i < 3; i++)
	{
		std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << " ";
	}
	for (int i = 0; i < 5; i++)
	{
		std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::DOUBLE_LOWER_RIGHT_CORNER;
	std::cout << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(77, counter + 41);
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 56; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::LOWER_RIGHT_CORNER << std::endl;
}

/**
 * @brief Function for half open book.
*/
void printHalfOpenBook()
{
	int counter = 2;
	outputPosition(74, counter + 1);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "\\" << std::endl;
	outputPosition(74, counter + 2);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " \\" << std::endl;
	outputPosition(74, counter + 3);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "  \\           . ";
	for (int i = 0; i < 3; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	for (int i = 0; i < 4; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ." << std::endl;
	outputPosition(74, counter + 4);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "  | .  . ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " ' '                       ' ";
	for (int i = 0; i < 3; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << std::endl;
	outputPosition(74, counter + 5);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "  |                                        ' ";
	for (int i = 0; i < 3; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	}
	for (int i = 0; i < 7; i++)
	{
		std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::DOUBLE_UPPER_RIGHT_CORNER << std::endl;
	outputPosition(74, counter + 6);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "  |                                                       ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::UPPER_RIGHT_CORNER << std::endl;
	for (int i = 0; i < 31; i++)
	{
		outputPosition(74, counter + 7 + i);
		std::cout << (char)CHARACTERS::VERTICAL_LINE;
		std::cout << "  |                                                       ";
		std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
		std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	}
	outputPosition(74, counter + 38);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "  |         . " << (char)CHARACTERS::DOT << " ' ";
	for (int i = 0; i < 8; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	}
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " ' " << (char)CHARACTERS::DOT;
	std::cout << "                   " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(74, counter + 39);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "  |  . " << (char)CHARACTERS::DOT;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << "    . " << (char)CHARACTERS::DOT;
	std::cout << " ' " << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 11; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << " '    " << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 4; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << "              " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(74, counter + 40);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "  | /  . " << (char)CHARACTERS::DOT;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << "                     ";
	std::cout << (char)CHARACTERS::DOT << " ";
	for (int i = 0; i < 3; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	}
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " ' ";
	for (int i = 0; i < 2; i++)
	{
		std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << " ";
	}
	for (int i = 0; i < 2; i++)
	{
		std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	}
	for (int i = 0; i < 5; i++)
	{
		std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::DOUBLE_LOWER_RIGHT_CORNER;
	std::cout << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(74, counter + 41);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "  ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "    / ";
	for (int i = 0; i < 51; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::LOWER_RIGHT_CORNER << std::endl;
	outputPosition(74, counter + 42);
	std::cout << (char)CHARACTERS::LOWER_LEFT_CORNER;
	for (int i = 0; i < 5; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << " '" << std::endl;
}
/**
 * @brief Function for printing almost open book.
*/
void printAlmostOpenedBook()
{
	int counter = 1;
	outputPosition(19, counter + 1);
	std::cout << "  " << (char)CHARACTERS::VERTICAL_LINE << "   ` ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " .   " << std::endl;
	outputPosition(19, counter + 2);
	std::cout << "  " << (char)CHARACTERS::VERTICAL_LINE << "          ` ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " .   " << std::endl;
	outputPosition(19, counter + 3);
	std::cout << "  " << (char)CHARACTERS::VERTICAL_LINE << "                 ` ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " .   " << std::endl;
	outputPosition(19, counter + 4);
	std::cout << "  " << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                          ` " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " .    " << std::endl;
	std::cout << "  " << (char)CHARACTERS::VERTICAL_LINE << "                                 ` ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " .                             . ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " ." << std::endl;
	outputPosition(19, counter + 5);
	std::cout << "  " << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                      ` ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " .                 ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " ' '                         ' ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << std::endl;
	outputPosition(19, counter + 6);
	std::cout << "  " << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                             ` " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " .  ___ /                                       ' ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	for (int i = 0; i < 3; i++)
	{
		std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_UPPER_RIGHT_CORNER << std::endl;
	outputPosition(19, counter + 7);
	std::cout << "  " << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                   :   |                                                       ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::UPPER_RIGHT_CORNER << std::endl;
	for (int i = 0; i < 28; i++)
	{
		outputPosition(19, counter + 8 + i);
		std::cout << "  " << (char)CHARACTERS::VERTICAL_LINE;
		std::cout << "                                                   :   |                                                       ";
		std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
		std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	}
	outputPosition(19, counter + 36);
	std::cout << "    ` " << (char)CHARACTERS::HORIZONTAL_LINE << " .";
	std::cout << "                                             :   |                                                       ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 37);
	std::cout << "           " << (char)CHARACTERS::HORIZONTAL_LINE << " .";
	std::cout << "                                        :   |                                                       ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 38);
	std::cout << "               " << (char)CHARACTERS::HORIZONTAL_LINE << " .";
	std::cout << "                                    :   |                                                       ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 39);
	std::cout << "                    ` " << (char)CHARACTERS::HORIZONTAL_LINE << " .";
	std::cout << "                             :   |         . " << (char)CHARACTERS::DOT;
	std::cout << " ' " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " ' " << (char)CHARACTERS::DOT << "                   ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 40);
	std::cout << "                           ` " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " ." << "                      :   |  . " << (char)CHARACTERS::DOT;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << "    . " << (char)CHARACTERS::DOT << " ' " << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 5; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " '    " << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 2; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << "              " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 41);
	std::cout << "                                  ` " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " ." << "               :   | /  . " << (char)CHARACTERS::DOT << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << "                     " << (char)CHARACTERS::DOT << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ' ";
	for (int i = 0; i < 3; i++)
	{
		std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << " ";
	}
	for (int i = 0; i < 5; i++)
	{
		std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::DOUBLE_LOWER_RIGHT_CORNER;
	std::cout << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 42);
	std::cout << "                                         ` ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " .                  / ";
	for (int i = 0; i < 50; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::LOWER_RIGHT_CORNER << std::endl;
	outputPosition(19, counter + 43);
	std::cout << "                                                  ' ";
	for (int i = 0; i < 9; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << " '" << std::endl;
}

/**
 * @brief Function for printing fully open book.
*/
void printFullyOpenedBook()
{
	int counter = 4;
	outputPosition(19, counter + 1);
	std::cout << "                                                                    . ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " "; (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ." << std::endl;
	outputPosition(19, counter + 2);
	std::cout << "                                                              ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " ' '                         ' ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << std::endl;
	outputPosition(19, counter + 3);
	std::cout << " ________________________________________________________   /                                      ' ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_UPPER_RIGHT_CORNER << std::endl;
	outputPosition(19, counter + 4);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                        \\ /                                                      ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::UPPER_RIGHT_CORNER << std::endl;
	for (int i = 0; i < 31; i++)
	{
		outputPosition(19, counter + 5 + i);
		std::cout << (char)CHARACTERS::VERTICAL_LINE;
		std::cout << "                                                         |                                                       ";
		std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
		std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;

	}
	outputPosition(19, counter + 36);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                         |         . ";
	std::cout << (char)CHARACTERS::DOT << " ' " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ' " << (char)CHARACTERS::DOT;
	std::cout << "                   " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 37);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                         |  . ";
	std::cout << (char)CHARACTERS::DOT << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << "    . " << (char)CHARACTERS::DOT;
	std::cout << " ' " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 5; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << " '    " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << "              " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 38);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                         | /  . ";
	std::cout << (char)CHARACTERS::DOT << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << "                     ";
	std::cout << (char)CHARACTERS::DOT << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " ' ";
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << " ";
	for (int i = 0; i < 5; i++)
	{
		std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::DOUBLE_LOWER_RIGHT_CORNER;
	std::cout << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 39);
	std::cout << (char)CHARACTERS::LOWER_LEFT_CORNER << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 24; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << "\\            / ";
	for (int i = 0; i < 25; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::LOWER_RIGHT_CORNER << std::endl;
	outputPosition(19, counter + 40);
	std::cout << "                                                     '";
	for (int i = 0; i < 3; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE << "'" << std::endl;
}
/**
 * @brief Function for printing the opened book
*/
void printOpenedBook()
{
	int counter = 4;
	outputPosition(19, counter + 1);
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
	outputPosition(19, counter + 2);
	std::cout << "                   " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " '                         " << "' ' " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " .     . " << (char)CHARACTERS::HORIZONTAL_LINE << " ' '                         ' ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << std::endl;
	outputPosition(19, counter + 3);
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
	outputPosition(19, counter + 4);
	std::cout << (char)CHARACTERS::UPPER_LEFT_CORNER << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << "                                                      \\ /                                                      ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::UPPER_RIGHT_CORNER << std::endl;
	for (int i = 0; i < 30; i++)
	{
		outputPosition(19, counter + 5 + i);
		std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
		std::cout << "                                                       |                                                       ";
		std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	}
	outputPosition(19, counter + 35);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                                                       |                                                       ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 36);
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
	outputPosition(19, counter + 37);
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
	outputPosition(19, counter + 38);
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
	outputPosition(19, counter + 39);
	std::cout << (char)CHARACTERS::LOWER_LEFT_CORNER << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 25; i++) {
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << " \\         / " << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 25; i++) {
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::LOWER_RIGHT_CORNER << std::endl;
	outputPosition(19, counter + 40);
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
	int counter = 4;
	outputPosition(19, counter + 1);
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
	outputPosition(19, counter + 2);
	std::cout << "                   " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " '                         " << "' ' ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " .     . " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " ' '                         ' " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE << std::endl;
	outputPosition(19, counter + 3);
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
	outputPosition(19, counter + 4);
	std::cout << (char)CHARACTERS::UPPER_LEFT_CORNER << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << "                                                      \\ /                                                      ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::UPPER_RIGHT_CORNER << std::endl;

	for (int i = 0; i < 30; i++)
	{
		outputPosition(19, counter + 5 + i);
		std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
		std::cout << "                                                       |                                                       ";
		std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	}
	outputPosition(19, counter + 35);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                                                       |                                                       ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 36);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                                                       |         . ";
	std::cout << (char)CHARACTERS::DOT << " ' " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " ' " << (char)CHARACTERS::DOT << "                   " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 37);
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
	outputPosition(19, counter + 38);
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
	outputPosition(19, counter + 39);
	std::cout << (char)CHARACTERS::LOWER_LEFT_CORNER << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 25; i++) {
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << " \\         / " << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 25; i++) {
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::LOWER_RIGHT_CORNER << std::endl;
	outputPosition(19, counter + 40);
	std::cout << "                                                      ' ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " '" << std::endl;
}

/**
 * @brief Function for printing the first part of the book's leafing to the left
*/
void pageLeafingLeftOne()
{
	int counter = 3;
	outputPosition(19, counter + 1);
	std::cout << "         /" << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 2);
	std::cout << "        " << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                                           . ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ." << std::endl;
	outputPosition(19, counter + 3);
	std::cout << "        " << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE;
	for (int i = 0; i < 14; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " .     . " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " ' '                         ' " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << std::endl;
	outputPosition(19, counter + 4);
	std::cout << "        " << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                                             \\   /                                      ' ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_UPPER_RIGHT_CORNER << std::endl;
	outputPosition(19, counter + 5);
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
		outputPosition(19, counter + 6 + i);
		std::cout << (char)CHARACTERS::VERTICAL_LINE << "       " << (char)CHARACTERS::VERTICAL_LINE;
		std::cout << " " << (char)CHARACTERS::VERTICAL_LINE << "                                               |                                                       ";
		std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	}
	outputPosition(19, counter + 35);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "       " << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << " " << (char)CHARACTERS::VERTICAL_LINE << "                                               |                                                       ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 36);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "       " << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "/                                                |                                                       ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 37);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "        \\                                                |         . ";
	std::cout << (char)CHARACTERS::DOT << " ' " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " ' " << (char)CHARACTERS::DOT << "                   ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 38);
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
	outputPosition(19, counter + 39);
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
	outputPosition(19, counter + 40);
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
	outputPosition(19, counter + 41);
	std::cout << "                                                      ' ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " '" << std::endl;
}


/**
 * @brief Function for printing the first part of the book's leafing to the right
*/
void pageLeafingRightOne()
{
	int counter = 3;
	outputPosition(19, counter + 1);
	std::cout << "                                                                                                           /";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 2);
	std::cout << "                         . " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " .                                                           ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 3);
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
	outputPosition(19, counter + 4);
	std::cout << "  " << (char)CHARACTERS::DOUBLE_UPPER_LEFT_CORNER;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " '                                      \\   /                                             ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 5);
	std::cout << (char)CHARACTERS::UPPER_LEFT_CORNER << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << "                                                      \\ /                                              ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::UPPER_RIGHT_CORNER << std::endl;

	for (int i = 0; i < 29; i++)
	{
		outputPosition(19, counter + 6 + i);
		std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
		std::cout << "                                                       |                                               ";
		std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE;
		std::cout << "       " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	}
	outputPosition(19, counter + 35);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                                                       |                                               ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "       " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 36);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                                                       |                                                \\";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "       " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 37);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                   " << (char)CHARACTERS::DOT << " ' ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " ' " << (char)CHARACTERS::DOT;
	std::cout << " .         |                                                /        ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 38);
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
	outputPosition(19, counter + 39);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_LOWER_LEFT_CORNER;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << " " << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << " " << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << " ' " << "                              " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::DOT << " .  \\ | /                                                       ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 40);
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
	outputPosition(19, counter + 41);
	std::cout << "                                                      ' ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " '" << std::endl;
}

/**
 * @brief Function for printing the second part of the book's leafing to the left
*/
void pageLeafingLeftTwo()
{
	int counter = -2;
	outputPosition(19, counter + 1);
	std::cout << "                         /" << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 2);
	std::cout << "                        / " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 3);
	std::cout << "                       /  " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 4);
	std::cout << "                      /   " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 5);
	std::cout << "                     /    " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 6);
	std::cout << "                    " << (char)CHARACTERS::DOT << "     " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 7);
	std::cout << "                    " << (char)CHARACTERS::VERTICAL_LINE << "     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                                           . ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " ." << std::endl;
	outputPosition(19, counter + 8);
	std::cout << "                    " << (char)CHARACTERS::VERTICAL_LINE << "     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 13; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << " .     . " << (char)CHARACTERS::HORIZONTAL_LINE << " ' '                         ' ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << std::endl;
	outputPosition(19, counter + 9);
	std::cout << "                    " << (char)CHARACTERS::VERTICAL_LINE << "     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                             \\   /                                      ' ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_UPPER_RIGHT_CORNER << std::endl;
	outputPosition(19, counter + 10);
	std::cout << (char)CHARACTERS::UPPER_LEFT_CORNER << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 9; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "     " << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                              \\ /                                                      ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::UPPER_RIGHT_CORNER << std::endl;

	for (int i = 0; i < 24; i++)
	{
		outputPosition(19, counter + 11 + i);
		std::cout << (char)CHARACTERS::VERTICAL_LINE << "                   ";
		std::cout << (char)CHARACTERS::VERTICAL_LINE << "     ";
		std::cout << (char)CHARACTERS::VERTICAL_LINE << "                               |                                                       ";
		std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
		std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	}
	outputPosition(19, counter + 35);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                   ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "     " << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                               |                                                       ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 36);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                   ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "    .'";
	std::cout << "                               |                                                       ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 37);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                   ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "  " << (char)CHARACTERS::DOT;
	std::cout << "'                                 |                                                       ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " " << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << std::endl;
	outputPosition(19, counter + 38);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                   ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " /                                   |                                                       ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 39);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                   ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "/                                    |                                                       ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 40);
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                    \\                                    |                                                       ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 41);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                     \\                                   |                                                       ";
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << " ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 42);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                      '";
	std::cout << (char)CHARACTERS::DOT << "_                                |         . ";
	std::cout << (char)CHARACTERS::DOT << " ' " << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " ' " << (char)CHARACTERS::DOT << "                   " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << " " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 43);
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
	outputPosition(19, counter + 44);
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
	outputPosition(19, counter + 45);
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
	outputPosition(19, counter + 46);
	std::cout << "                                                      ' ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " '" << std::endl;
}

/**
 * @brief Function for printing the second part of the book's leafing to the right
*/
void pageLeafingRightTwo()
{
	int counter = -2;
	outputPosition(19, counter + 1);
	std::cout << "                                                                                         ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "\\" << std::endl;
	outputPosition(19, counter + 2);
	std::cout << "                                                                                         ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " \\" << std::endl;
	outputPosition(19, counter + 3);
	std::cout << "                                                                                         ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "  \\" << std::endl;
	std::cout << "                                                                                         ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "   \\" << std::endl;
	outputPosition(19, counter + 4);
	std::cout << "                                                                                         ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "    \\" << std::endl;
	outputPosition(19, counter + 5);
	std::cout << "                                                                                         ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "     \\" << std::endl;
	outputPosition(19, counter + 6);
	std::cout << "                                                                                         ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "      " << (char)CHARACTERS::DOT << std::endl;
	outputPosition(19, counter + 7);
	std::cout << "                         . " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE << " ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " .                                          ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "      " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 8);
	std::cout << "                   " << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " '                         " << "' ' ";
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << " .     . " << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 12; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "      " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 9);
	std::cout << "  " << (char)CHARACTERS::DOUBLE_UPPER_LEFT_CORNER;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " '                                      \\   /                            ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "      " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 10);
	std::cout << (char)CHARACTERS::UPPER_LEFT_CORNER << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::DOUBLE_VERTICAL_LINE << "                                                      \\ /                             ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "      " << (char)CHARACTERS::VERTICAL_LINE;
	for (int i = 0; i < 9; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::UPPER_RIGHT_CORNER << std::endl;
	for (int i = 0; i < 26; i++)
	{
		outputPosition(19, counter + 11 + i);
		std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
		std::cout << "                                                       |                              ";
		std::cout << (char)CHARACTERS::VERTICAL_LINE << "      " << (char)CHARACTERS::VERTICAL_LINE;
		std::cout << "                   " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	}
	outputPosition(19, counter + 36);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                                                       |                              ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "      " << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "                   " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 37);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                                                       |                               '.    ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                   ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 38);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                                                       |                                 '.  ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                   ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 39);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                                                       |                                   \\ ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                   ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 40);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                                                       |                                    \\";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                   ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 41);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                                                       |                                    /                    ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	std::cout << "                                                       |                                   /                     ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 42);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << " " << (char)CHARACTERS::DOUBLE_VERTICAL_LINE;
	std::cout << "                   " << (char)CHARACTERS::DOT << " ' " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " " << (char)CHARACTERS::HORIZONTAL_LINE << " " << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << " ' " << (char)CHARACTERS::DOT << " .         |                                _";
	std::cout << (char)CHARACTERS::DOT << "'                      ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(19, counter + 43);
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
	outputPosition(19, counter + 44);
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
	outputPosition(19, counter + 45);
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
	outputPosition(19, counter + 46);
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
	int counter = 8;
	outputPosition(115, counter + 1);
	std::cout << ",-." << std::endl;
	outputPosition(114, counter + 2);
	std::cout << "(\"O_)" << std::endl;
	outputPosition(113, counter + 3);
	std::cout << "/ `-/" << std::endl;
	outputPosition(112, counter + 4);
	std::cout << "/-. /" << std::endl;
	outputPosition(111, counter + 5);
	std::cout << "/   )" << std::endl;
	outputPosition(84, counter + 6);
	std::cout << "                          /   /  " << std::endl;
	outputPosition(84, counter + 7);
	std::cout << "              _          /-. /" << std::endl;
	outputPosition(84, counter + 8);
	std::cout << "             (_)\"-.._   /   )" << std::endl;
	outputPosition(84, counter + 9);
	std::cout << "              \"-._   '\"\"( )/    " << std::endl;
	outputPosition(84, counter + 10);
	std::cout << "                   \"-/\"-._\"`. " << std::endl;
	outputPosition(84, counter + 11);
	std::cout << "                    /     \"-.'._" << std::endl;
	outputPosition(84, counter + 12);
	std::cout << "                   /\\       /-._\"-._" << std::endl;
	outputPosition(84, counter + 13);
	std::cout << "    _,---...__    /  ) _,-\"/    \"-(_)" << std::endl;
	outputPosition(84, counter + 14);
	std::cout << "___<__(|) _   \"\"-/  / /   /" << std::endl;
	outputPosition(84, counter + 15);
	std::cout << " '  `----' \"\"-.   \\/ /   /" << std::endl;
	outputPosition(84, counter + 16);
	std::cout << "               )  ] /   /" << std::endl;
	outputPosition(84, counter + 17);
	std::cout << "       ____..-'   //   /                       " << std::endl;
	outputPosition(84, counter + 18);
	std::cout << "   ,-\"\"      __.,'/   /   ___                )" << std::endl;
	outputPosition(84, counter + 19);
	std::cout << "  /    ,--\"\"/  / /   /,-\"\"   \"\"\"-          ,'/" << std::endl;
	outputPosition(84, counter + 20);
	std::cout << " [    (    /  / /   /  ,.---,_   `._   _,-','" << std::endl;
	outputPosition(84, counter + 21);
	std::cout << "  \\    `-./  / /   /  /       `-._  \"\"\"_.-'" << std::endl;
	outputPosition(84, counter + 22);
	std::cout << "   `-._  /  / /   /_,'            \"\"--\"" << std::endl;
	outputPosition(84, counter + 23);
	std::cout << "       \"/  / /   /\"         " << std::endl;
	outputPosition(84, counter + 24);
	std::cout << "       /  / /   /" << std::endl;
	outputPosition(84, counter + 25);
	std::cout << "      /  |,'   /  " << std::endl;
	outputPosition(89, counter + 26);
	std::cout << ":   /    /" << std::endl;
	outputPosition(89, counter + 27);
	std::cout << "[  /   ,'  " << std::endl;
	outputPosition(89, counter + 28);
	std::cout << "| /  ,'" << std::endl;
	outputPosition(89, counter + 29);
	std::cout << "|/,-'" << std::endl;
}

/**
 * @brief Function for printing main page 
*/
void printMainPage()
{
	std::cout << "                   [\\                                            " << std::endl;
	std::cout << "                   |\\)                                           " << std::endl;
	std::cout << "                   |                                                  ___      __       ___                     " << std::endl;
	std::cout << "                   /\\           __                           |     /\\  | |__| |__)  /\\  |__   /\\                  " << std::endl;
	std::cout << "                  /  \\       __(  )--.                       |___ /~~\\ | |  | |  \\ /~~\\ |___ /~~\\                " << std::endl;
	std::cout << "                 /    \\   ,-(         )_                                 __        __   __   __   __       ___                 " << std::endl;
	std::cout << "                //T`-._\\ (             _)                               |__) |__| /  \\ |  \\ /  \\ |__) /\\  |__   /\\              " << std::endl;
	std::cout << "                /[|   ]|  `-(_______)-`   |\\                            |  \\ |  | \\__/ |__/ \\__/ |   /~~\\ |___ /~~\\                 " << std::endl;
	std::cout << "                | |    |                  J'                      " << std::endl;
	std::cout << "                | |  ] |     _           /;\\                     " << std::endl;
	std::cout << "               [| |    |     L'         /;  \\                    " << std::endl;
	std::cout << "              /||.| /\\ |    /\\         /.,-._\\                 " << std::endl;
	std::cout << "             /_|||| || |   /  \\        | |{  |                   " << std::endl;
	std::cout << "   L/\\        |\\| | '` |_ _  {|        | | U |   /\\            " << std::endl;
	std::cout << "  /   \\/\\    `| Y | [  '-'  '--''-''- -'`'   | '`  \\ /\\,`\\   " << std::endl;
	std::cout << " / ,'./  \\.`  |[  |       [     __   L    ]  |      /  \\  \\    " << std::endl;
	std::cout << "/,'     `     |   |           ,`   .   ]     |___Y Y____,_,,___,_____,,______________,______   " << std::endl;
	std::cout << "---    -----.-(] [|   ]     o/     |o       ]|| /`-, Y  _   Y  Y        _             _    " << std::endl;
	std::cout << "     Y Y  --;`~T  |      }   \\     |[\\ _,.- (^) ,-'    (^)__  _        (^)           (^)         " << std::endl;
	std::cout << "    Y  YY   ;'~~l |   L     [|\\       \\   \\ \\Y-`  _     Y   _       --- Y   ` _ _     Y               " << std::endl;
	std::cout << "   Y  Y Y   ;\\~~/\\{| [      _,'-\\`= = '.\\_ ,`    (^)       (^)      _        _              " << std::endl;
	std::cout << "       --   ;\\~~~/\\|  _,.-` _  `.\\_..-'   _  ., _ Y     _   Y__    (^)      (^)            " << std::endl;
	std::cout << "      _    _; \\~~( Y``   Y (^) / `,      (^)      _    (^)          Y        Y    _      " << std::endl;
	std::cout << "     (^)  (^)`._~ /  L \\  _.Y'`  _  ` --  Y - - -(^) -  Y -         ===          (^)          " << std::endl;
	std::cout << "      Y    Y    `'--..,-'`      (^)   _  -    _   Y ____       __      _          Y   " << std::endl;
	std::cout << "        --                _ --   Y   (^)     (^)  ===   ----          (^) _  _  _              " << std::endl;
	std::cout << "            __   -       (^)      --- Y       Y                        Y          " << std::endl;
	std::cout << "                          Y                                                           " << std::endl;
}


/**
 * @brief Function for printing the map of Bulgaria
*/
void printBulgarianMap()
{
	int counter = 11;
	outputPosition(39, counter + 1);
	std::cout << "  .-.                                                     _.--._" << std::endl;
	outputPosition(39, counter + 2);
	std::cout << " _|  \\_                                              _.-'       ._   _" << std::endl;
	outputPosition(39, counter + 3);
	std::cout << "/    .-'  _                                       .'              '-' '" << std::endl;
	outputPosition(39, counter + 4);
	std::cout << "|    '-.-' '-._       _                        _.'                     '----'." << std::endl;
	outputPosition(39, counter + 5);
	std::cout << " \\             '-.--.' '-.._._       _______.'                               \\" << std::endl;
	outputPosition(39, counter + 6);
	std::cout << "  |                            '-_.-'                                    _.._/" << std::endl;
	outputPosition(39, counter + 7);
	std::cout << "   \\_                                                                 .'" << std::endl;
	outputPosition(39, counter + 8);
	std::cout << "     \\                                                              _.'" << std::endl;
	outputPosition(39, counter + 9);
	std::cout << "      \\_                                                           '." << std::endl;
	outputPosition(39, counter + 10);
	std::cout << "        |                                                         _.'" << std::endl;
	outputPosition(39, counter + 11);
	std::cout << "        '.                                                         '." << std::endl;
	outputPosition(39, counter + 12);
	std::cout << "       .'                                                           '." << std::endl;
	outputPosition(39, counter + 13);
	std::cout << "      _/                                                            _'" << std::endl;
	outputPosition(39, counter + 14);
	std::cout << "  .-_/                                                            .'" << std::endl;
	outputPosition(39, counter + 15);
	std::cout << "  '.                                                             .'" << std::endl;
	outputPosition(39, counter + 16);
	std::cout << "   /_                                                           .'" << std::endl;
	outputPosition(39, counter + 17);
	std::cout << "   _/                                                           '-" << std::endl;
	outputPosition(39, counter + 18);
	std::cout << "   \\.                                                    _._     '-." << std::endl;
	outputPosition(39, counter + 19);
	std::cout << "     '--.                                             .-'    '-.    '-." << std::endl;
	outputPosition(39, counter + 20);
	std::cout << "        |_                                           /         '-._.-.-'" << std::endl;
	outputPosition(39, counter + 21);
	std::cout << "          '-.                                     _.'" << std::endl;
	outputPosition(39, counter + 22);
	std::cout << "          .'                                   .-'" << std::endl;
	outputPosition(39, counter + 23);
	std::cout << "          |        ._..-.-.                   '-." << std::endl;
	outputPosition(39, counter + 24);
	std::cout << "         .'   ._.-'       '-._._              _.'" << std::endl;
	outputPosition(39, counter + 25);
	std::cout << "        '__.-'                  '.    _._.'.-'" << std::endl;
	outputPosition(39, counter + 26);
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
	int counter = 9;
	outputPosition(33, counter + 1);
	std::cout << (char)CHARACTERS::UPPER_LEFT_CORNER << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 42; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::UPPER_RIGHT_CORNER << std::endl;
	outputPosition(33, counter + 2);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "     Move the marker on the coordinates the event had been placed and press Enter!    " << (char)CHARACTERS::VERTICAL_LINE << std::endl;

	for (int i = 0; i < 26; i++)
	{
		outputPosition(33, counter + i + 3);
		std::cout << (char)CHARACTERS::VERTICAL_LINE << "                                                                                      " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	}

	outputPosition(33, counter + 28);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                                                                                      " << (char)CHARACTERS::VERTICAL_LINE << std::endl;

	outputPosition(33, counter + 29);
	std::cout << (char)CHARACTERS::LOWER_LEFT_CORNER << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 42; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::LOWER_RIGHT_CORNER << std::endl;
}

/**
 * @brief Function for printing a pop-up tab for the timeline
*/
void printTimelinePopUp()
{
	outputPosition(2, 1);
	std::cout << (char)CHARACTERS::UPPER_LEFT_CORNER << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 35; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::UPPER_RIGHT_CORNER << std::endl;

	outputPosition(2, 2);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                                                                     X  " << (char)CHARACTERS::VERTICAL_LINE << std::endl;

	for (int i = 0; i < 12; i++)
	{
		outputPosition(2, 3 + i);
		std::cout << (char)CHARACTERS::VERTICAL_LINE << "                                                                        " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	}

	outputPosition(2, 13);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                                                                        " << (char)CHARACTERS::VERTICAL_LINE << std::endl;

	outputPosition(2, 14);
	std::cout << (char)CHARACTERS::LOWER_LEFT_CORNER << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 35; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::LOWER_RIGHT_CORNER << std::endl;
}

/**
 * @brief Function for printing a pop-up tab for the sword timeline
*/
void printSwordTimelinePopUp()
{
	outputPosition(2, 1);
	std::cout << (char)CHARACTERS::UPPER_LEFT_CORNER << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 42; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::UPPER_RIGHT_CORNER << std::endl;

	outputPosition(2, 2);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                                                                                   X  " << (char)CHARACTERS::VERTICAL_LINE << std::endl;

	for (int i = 0; i < 10; i++)
	{
		outputPosition(2, 3 + i);
		std::cout << (char)CHARACTERS::VERTICAL_LINE << "                                                                                      " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	}

	outputPosition(2, 13);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                                                                                      " << (char)CHARACTERS::VERTICAL_LINE << std::endl;

	outputPosition(2, 14);
	std::cout << (char)CHARACTERS::LOWER_LEFT_CORNER << (char)CHARACTERS::HORIZONTAL_LINE;
	for (int i = 0; i < 42; i++)
	{
		std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	}
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::LOWER_RIGHT_CORNER << std::endl;
}

/**
 * @brief Function for printing a sword timeline
*/
void printSwordTimeline()
{
	outputPosition(6, 4);
	std::cout << "                    " << "1987" << "            " << "1987" << "            " << "1987" << "            " << "1987" << std::endl;

	outputPosition(24, 6);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "                  " << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "               " << (char)CHARACTERS::VERTICAL_LINE << "               ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE << std::endl;

	outputPosition(6, 6);
	std::cout << "              /\\     " << (char)CHARACTERS::VERTICAL_LINE << std::endl;

	outputPosition(6, 7);
	std::cout << "/VVVVVVVVVVVVVV|" << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::ROTATED_T << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::ROTATED_T << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::ROTATED_T << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::ROTATED_T << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << "\\" << std::endl;

	outputPosition(6, 8);
	std::cout << "`^^^^^^^^^^^^^^|" << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::T << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::T << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::T << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE << "/" << std::endl;

	outputPosition(6, 9);
	std::cout << "              \\/" << std::endl;
	outputPosition(35, 9);
	std::cout << (char)CHARACTERS::VERTICAL_LINE << "               " << (char)CHARACTERS::VERTICAL_LINE << "               " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(6, 11);
	std::cout << "                            1987            1876            1967" << std::endl;
}

/**
 * @brief Function for printing a timeline
*/
void printTimeline()
{
	outputPosition(5, 5);
	std::cout << "               1987            1989            1991" << std::endl;

	outputPosition(5, 7);
	std::cout << "                " << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "               " << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "               " << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "               \\" << std::endl;

	outputPosition(5, 8);
	std::cout << (char)CHARACTERS::BLOCK << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::T << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::ROTATED_T;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::T << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::ROTATED_T;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::T << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::ROTATED_T;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::T << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << (char)CHARACTERS::HORIZONTAL_LINE;
	std::cout << (char)CHARACTERS::HORIZONTAL_LINE << ")" << std::endl;
	outputPosition(5, 9);
	std::cout << "        " << (char)CHARACTERS::VERTICAL_LINE << "               ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "               " << (char)CHARACTERS::VERTICAL_LINE << "               ";
	std::cout << (char)CHARACTERS::VERTICAL_LINE;
	std::cout << "       /" << std::endl;
	outputPosition(5, 11);
	std::cout << "       1986            1988            1990            1991" << std::endl;
}

/**
 * @brief Function for printing the logo of the project
*/
void logoForProgram()
{
	std::cout << "        ##### /                                                                                                         " << std::endl;
	std::cout << "     ######  /                                   /                                                                      " << std::endl;
	std::cout << "    /#   /  /                                  #/                                                                       " << std::endl;
	std::cout << "   /    /  /                            #      ##                                                                       " << std::endl;
	std::cout << "       ## ##                           ##      ##                                                                       " << std::endl;
	std::cout << "       ## ##                           ##      ##                                                                       " << std::endl;
	std::cout << "       ## ##               /###      ########  ##  /##    ###  /###       /###         /##         /###                 " << std::endl;
	std::cout << "       ## ##              / ###  /  ########   ## / ###    ###/ ####  /  / ###  /     / ###       / ###  /              " << std::endl;
	std::cout << "       ## ##             /   ###/      ##      ##/   ###    ##    ###/  /   ###/     /   ###     /   ###/               " << std::endl;
	std::cout << "       #  ##            ##    ##       ##      ##     ##    ##         ##    ##     ##    ###   ##    ##                " << std::endl;
	std::cout << "          /             ##    ##       ##      ##     ##    ##         ##    ##     ########    ##    ##                " << std::endl;
	std::cout << "      /##/           /  ##    ##       ##      ##     ##    ##         ##    ##     #######     ##    ##                " << std::endl;
	std::cout << "     /  ############/   ##    ##       ##      ##     ##    ##         ##    ##     ##          ##    ##                " << std::endl;
	std::cout << "    /     #########     ##    /#       ##      ##     ##    ##         ##    /#     ####    /   ##    /#                " << std::endl;
	std::cout << "    #                    ####/  ##     ##      ##     ##    ###         ####/  ##    ######/     ####/  ##              " << std::endl;
	std::cout << "     ##                   ###    ##     ##      ##    ##     ###         ###    ##    #####       ###    ##             " << std::endl;
	std::cout << "                                                      /                                                                 " << std::endl;
	std::cout << "                                                     /                                                                  " << std::endl;
	std::cout << "                                                    /                                                                   " << std::endl;
	std::cout << "                                                                                                                        " << std::endl;
	std::cout << "     ##### /##       /                              ##                                                                  " << std::endl;
	std::cout << "  ######  / ##     #/                                ##                                                                 " << std::endl;
	std::cout << " /#   /  /  ##     ##                                ##                                                                 " << std::endl;
	std::cout << "/    /  /   ##     ##                                ##                                                                 " << std::endl;
	std::cout << "    /  /    /      ##                                ##                                                                 " << std::endl;
	std::cout << "   ## ##   /       ##  /##         /###         ###  ##       /###         /###       /###         /##         /###     " << std::endl;
	std::cout << "   ## ##  /        ## / ###       / ###  /     ##########    / ###  /     / ###  /   / ###  /     / ###       / ###  /  " << std::endl;
	std::cout << "   ## ###/         ##/   ###     /   ###/     ##    ####    /   ###/     /   ###/   /   ###/     /   ###     /   ###/   " << std::endl;
	std::cout << "   ## ##  ###      ##     ##    ##    ##      ##     ##    ##    ##     ##    ##   ##    ##     ##    ###   ##    ##    " << std::endl;
	std::cout << "   ## ##    ##     ##     ##    ##    ##      ##     ##    ##    ##     ##    ##   ##    ##     ########    ##    ##    " << std::endl;
	std::cout << "   #  ##    ##     ##     ##    ##    ##      ##     ##    ##    ##     ##    ##   ##    ##     #######     ##    ##    " << std::endl;
	std::cout << "      /     ##     ##     ##    ##    ##      ##     ##    ##    ##     ##    ##   ##    ##     ##          ##    ##    " << std::endl;
	std::cout << "  /##/      ###    ##     ##    ##    ##      ##    /#     ##    ##     ##    ##   ##    /#     ####    /   ##    /#    " << std::endl;
	std::cout << " /  ####    ##     ##     ##     ######        ####/        ######      #######     ####/  ##    ######/     ####/  ##  " << std::endl;
	std::cout << "/    ##     #       ##    ##      ####          ###          ####       ######       ###    ##    #####       ###    ## " << std::endl;
	std::cout << "#                         /                                             ##                                              " << std::endl;
	std::cout << " ##                      /                                              ##                                              " << std::endl;
	std::cout << " ##                     /                                               ##                                              " << std::endl;
	std::cout << " ##                                                                      ##                                             " << std::endl;
}

/**
 * @brief Function for printing the team logo
*/
void printTeamLogo()
{
	outputPosition(6, 4);
	std::cout << "  _          _   _                                     " << std::endl;
	outputPosition(6, 5);
	std::cout << " | |    __ _| |_| |__  _ __ __ _  ___  __ _            " << std::endl;
	outputPosition(6, 6);
	std::cout << " | |   / _` | __| '_ \\| '__/ _` |/ _ \\/ _` |           " << std::endl;
	outputPosition(6, 7);
	std::cout << " | |__| (_| | |_| | | | | | (_| |  __/ (_| |           " << std::endl;
	outputPosition(6, 8);
	std::cout << " |_____\\__,_|\\__|_| |_|_|  \\__,_|\\___|\\__,_|           " << std::endl;
	outputPosition(6, 9);
	std::cout << "  ____  _               _                              " << std::endl;
	outputPosition(6, 10);
	std::cout << " |  _ \\| |__   ___   __| | ___  _ __   __ _  ___  __ _ " << std::endl;
	outputPosition(6, 11);
	std::cout << " | |_) | '_ \\ / _ \\ / _` |/ _ \\| '_ \\ / _` |/ _ \\/ _` |" << std::endl;
	outputPosition(6, 12);
	std::cout << " |  _ <| | | | (_) | (_| | (_) | |_) | (_| |  __/ (_| |" << std::endl;
	outputPosition(6, 13);
	std::cout << " |_| \\_\\_| |_|\\___/ \\__,_|\\___/| .__/ \\__,_|\\___|\\__,_|" << std::endl;
	outputPosition(6, 14);
	std::cout << "                               |_|                     " << std::endl;
}
/**
 * @brief Function for printing text for about us page
*/
void printText() {
	std::cout << "Hello, we are team from five people, making a program for historical events!" << std::endl;
	std::cout << "1. Use your arrow keys to navigate through the options given in the menu" << std::endl;
	std::cout << "2. From the menu, you can choose either to remove, edit or add an event" << std::endl;
	std::cout << "3. Fill your progress about the event, providing details (date, period, year, type, ect.)" << std::endl;
}

/**
 * @brief Function for printing about us page 
*/
void printaboutUs() {

	std::cout << " " << std::endl;
	std::cout << "  ________________________________________________________________" << std::endl;
	std::cout << " / \                                                               \\. " << std::endl;
	std::cout << "|   |                                                              \\. " << std::endl;
	std::cout << "|   |                                                              |. " << std::endl;
	std::cout << " \\_ |              _   _              _     _   _                  |. " << std::endl;
	std::cout << "    |             /_\\ | |__  ___ _  _| |_  | | | |___              |. " << std::endl;
	std::cout << "    |            / _ \\| '_ \\/ _ \\ || |  _| | |_| (_-<              |. " << std::endl;
	std::cout << "    |           /_/ \\_\\_.__/\\___/\\_,_|\\__|  \\___//__/              |. " << std::endl;
	std::cout << "    |                                                              |. " << std::endl;
	std::cout << "    |                                                              |. " << std::endl;
	std::cout << "    |                                                              |." << std::endl;
	std::cout << "    |                                                              |." << std::endl;
	std::cout << "    |                                                              |." << std::endl;
	std::cout << "    |                                                              |." << std::endl;
	std::cout << "    |                                                              |." << std::endl;
	std::cout << "    |                                                              |." << std::endl;
	std::cout << "    |                                                              |." << std::endl;
	std::cout << "    |                                                              |." << std::endl;
	std::cout << "    |                                                              |." << std::endl;
	std::cout << "    |                                                              |." << std::endl;
	std::cout << "    |                                                              |." << std::endl;
	std::cout << "    |                                                              |." << std::endl;
	std::cout << "    |                                                              |." << std::endl;
	std::cout << "    |                                                              |." << std::endl;
	std::cout << "    |                                                              |." << std::endl;
	std::cout << "    |                                                              |." << std::endl;
	std::cout << "    |                                                              |." << std::endl;
	std::cout << "    |                                                              |. " << std::endl;
	std::cout << "    |                                                              |. " << std::endl;
	std::cout << "    |                                                              |. " << std::endl;
	std::cout << "    |                                                              |." << std::endl;
	std::cout << "    |                                                              |. " << std::endl;
	std::cout << "    |                                                              |. " << std::endl;
	std::cout << "    |                                                              |." << std::endl;
	std::cout << "    |                                                              |. " << std::endl;
	std::cout << "    |                                                              |. " << std::endl;
	std::cout << "    |     _________________________________________________________|___ " << std::endl;
	std::cout << "    |    /                                                            /." << std::endl;
	std::cout << "    \\   /                                                            /." << std::endl;
	std::cout << "     \\_/  __________________________________________________________/. " << std::endl;
}

/**
 * @brief Function for printing the team logo as keyboard
*/
void printTeamKeyboardLogo()
{
	outputPosition(6, 4);
	std::cout << "    ____ ____ ____ ____ ____ ____ ____ ____   " << std::endl;
	outputPosition(6, 5);
	std::cout << "   ||L |||a |||t |||h |||r |||a |||e |||a ||  " << std::endl;
	outputPosition(6, 6);
	std::cout << "   ||__|||__|||__|||__|||__|||__|||__|||__||  " << std::endl;
	outputPosition(6, 7);
	std::cout << "   |/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|  " << std::endl;
	outputPosition(6, 8);
	std::cout << " ____ ____ ____ ____ ____ ____ ____ ____ ____ " << std::endl;
	outputPosition(6, 9);
	std::cout << "||R |||h |||o |||d |||o |||p |||a |||e |||a ||" << std::endl;
	outputPosition(6, 10);
	std::cout << "||__|||__|||__|||__|||__|||__|||__|||__|||__||" << std::endl;
	outputPosition(6, 11);
	std::cout << "|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|" << std::endl;
}

/**
 * @brief Function for printing blank space
 * @param x X coordinates
 * @param y Y coordinates
*/
void printBlankSpace(int x, int y)
{
	outputPosition(x, y);
	std::cout << "                                                         " << std::endl;
	std::cout << "                                                         " << std::endl;
	std::cout << "                                                         " << std::endl;
	std::cout << "                                                         " << std::endl;
	std::cout << "                                                         " << std::endl;
	std::cout << "                                                         " << std::endl;
	std::cout << "                                                         " << std::endl;
	std::cout << "                                                         " << std::endl;
	std::cout << "                                                         " << std::endl;
	std::cout << "                                                         " << std::endl;
	std::cout << "                                                         " << std::endl;
	std::cout << "                                                         " << std::endl;
	std::cout << "                                                         " << std::endl;
	std::cout << "                                                         " << std::endl;
	std::cout << "                                                         " << std::endl;
	std::cout << "                                                         " << std::endl;
	std::cout << "                                                         " << std::endl;
	std::cout << "                                                         " << std::endl;
	std::cout << "                                                         " << std::endl;
	std::cout << "                                                         " << std::endl;
}

/**
 * @brief Function for printing book decorations
*/
void prinyBookDecorations()
{
	int counter = 6;
	outputPosition(79, counter + 1);
	std::cout << "   " << (char)CHARACTERS::VERTICAL_LINE << "          '                         '" << std::endl;
	outputPosition(79, counter + 2);
	std::cout << "   " << (char)CHARACTERS::VERTICAL_LINE << "   O     '                           '     O" << std::endl;
	outputPosition(79, counter + 3);
	std::cout << "   " << (char)CHARACTERS::VERTICAL_LINE << "       .'                             '." << std::endl;
	outputPosition(79, counter + 4);
	std::cout << "   " << (char)CHARACTERS::VERTICAL_LINE << "     .'                                 '." << std::endl;
	outputPosition(79, counter + 5);
	std::cout << "   " << (char)CHARACTERS::VERTICAL_LINE << "_ .'                                       '. _" << std::endl;
	outputPosition(79, counter + 6);
	std::cout << "   " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(79, counter + 7);
	std::cout << "   " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(79, counter + 8);
	std::cout << "   " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(79, counter + 9);
	std::cout << "   " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(79, counter + 10);
	std::cout << "   " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(79, counter + 11);
	std::cout << "   " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(79, counter + 12);
	std::cout << "   " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(79, counter + 13);
	std::cout << "   " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(79, counter + 14);
	std::cout << "   " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(79, counter + 15);
	std::cout << "   " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(79, counter + 16);
	std::cout << "   " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(79, counter + 17);
	std::cout << "   " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(79, counter + 18);
	std::cout << "   " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(79, counter + 19);
	std::cout << "   " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(79, counter + 20);
	std::cout << "   " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(79, counter + 21);
	std::cout << "   " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(79, counter + 22);
	std::cout << "   " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(79, counter + 23);
	std::cout << "   " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(79, counter + 24);
	std::cout << "   " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(79, counter + 25);
	std::cout << "   " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(79, counter + 26);
	std::cout << "   " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(79, counter + 27);
	std::cout << "   " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(79, counter + 28);
	std::cout << "   " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(79, counter + 29);
	std::cout << "   " << (char)CHARACTERS::VERTICAL_LINE << std::endl;
	outputPosition(79, counter + 30);
	std::cout << "   " << (char)CHARACTERS::VERTICAL_LINE << "-.                                            .-" << std::endl;
	outputPosition(79, counter + 31);
	std::cout << "   " << (char)CHARACTERS::VERTICAL_LINE << "   '.                                      .'" << std::endl;
	outputPosition(79, counter + 32);
	std::cout << "   " << (char)CHARACTERS::VERTICAL_LINE << "     '.                                  .'" << std::endl;
	outputPosition(79, counter + 33);
	std::cout << "   " << (char)CHARACTERS::VERTICAL_LINE << "   O   '                                '   O" << std::endl;
	outputPosition(79, counter + 34);
	std::cout << "   " << (char)CHARACTERS::VERTICAL_LINE << "        '                              '" << std::endl;
}
