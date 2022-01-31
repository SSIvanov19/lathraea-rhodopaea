/*! @file graphics.cpp
*   @brief A source file for the graphics.
*/

#include <iostream>

/**
 * @brief Function for printing the opened book
*/
void printOpenedBook()
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "                         . " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << char(196) << char(196) << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << char(196) << char(196) << " .                       . " << char(196) << char(196) << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << char(196) << char(196) << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " ." << std::endl;
	std::cout << "                   " << char(196) << char(196) << char(196) << " '                         " << "' ' " << char(196) << " .     . " << char(196) << " ' '                         ' " << char(196) << char(196) << char(196) << std::endl;
	std::cout << "  " << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << " " << char(196) << " " << char(196) << " " << char(196) << " '                                      \\   /                                      ' " << char(196) << " " << char(196) << " " << char(196) << " " << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187) << std::endl;
	std::cout << char(218) << char(196) << char(186) << "                                                      \\ /                                                      " << char(186) << char(196) << char(191) << std::endl;
	for (int i = 0; i < 29; i++)
	{
		std::cout << char(179) << " " << char(186) << "                                                       |                                                       " << char(186) << " " << char(179) << std::endl;
	}
	std::cout << char(179) << " " << char(186) << "                   " << char(250) << " ' " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " ' " << char(250) << " .         |         . " << char(250) << " ' " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " ' " << char(250) << "                   " << char(186) << " " << char(179) << std::endl;
	std::cout << char(179) << " " << char(186) << "              " << char(196) << char(196) << char(196) << char(196) << char(196) << "   " << " ' " << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << " ' " << char(250) << " .    " << char(196) << char(196) << " " << char(250) << " .  |  . " << char(250) << " " << char(196) << char(196) << "    . " << char(250) << " ' " << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << " '    " << char(196) << char(196) << char(196) << char(196) << char(196) << "              " << char(186) << " " << char(179) << std::endl;
	std::cout << char(179) << " " << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << " " << char(205) << " " << char(205) << " " << char(205) << " ' " << "                              " << char(196) << " " << char(196) << " " << char(250) << " .  \\ | /  . " << char(250) << " " << char(196) << " " << char(196) << "                     " << char(250) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " ' " << char(205) << " " << char(205) << " " << char(205) << " " << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << " " << char(179) << std::endl;
	std::cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << " \\         / " << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(217) << std::endl;
	std::cout << "                                                      ' " << char(196) << char(196) << char(196) << char(196) << char(196) << " '" << std::endl;
}

/**
 * @brief Function for printing the book with only one page leafed
*/
void printOnePageLeafedBook()
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "                         . " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << char(196) << char(196) << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << char(196) << char(196) << " .                       . " << char(196) << char(196) << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << char(196) << char(196) << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " ." << std::endl;
	std::cout << "                   " << char(196) << char(196) << char(196) << " '                         " << "' ' " << char(196) << " .     . " << char(196) << " ' '                         ' " << char(196) << char(196) << char(196) << std::endl;
	std::cout << "  " << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << " " << char(196) << " " << char(196) << " " << char(196) << " '                                      \\   /                                      ' " << char(196) << " " << char(196) << " " << char(196) << " " << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187) << std::endl;
	std::cout << char(218) << char(196) << char(186) << "                                                      \\ /                                                      " << char(186) << char(196) << char(191) << std::endl;
	for (int i = 0; i < 29; i++)
	{
		std::cout << char(179) << " " << char(186) << "                                                       |                                                       " << char(186) << " " << char(179) << std::endl;
	}
	std::cout << char(179) << " " << char(186) << "                                                       |         . " << char(250) << " ' " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " ' " << char(250) << "                   " << char(186) << " " << char(179) << std::endl;
	std::cout << char(179) << " " << char(186) << "              " << char(196) << char(196) << char(196) << char(196) << char(196) << "   " << " ' " << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << "  " << char(250) << " " << char(196) << " " << char(196) << " " << char(250) << " " << char(196) << char(196) << " " << char(250) << " .  |  . " << char(250) << " " << char(196) << char(196) << "    . " << char(250) << " ' " << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << " '    " << char(196) << char(196) << char(196) << char(196) << char(196) << "              " << char(186) << " " << char(179) << std::endl;
	std::cout << char(179) << " " << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << " " << char(205) << " " << char(205) << " " << char(205) << " ' " << "                                       \\ | /  . " << char(250) << " " << char(196) << " " << char(196) << "                     " << char(250) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " ' " << char(205) << " " << char(205) << " " << char(205) << " " << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << " " << char(179) << std::endl;
	std::cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << " \\         / " << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(217) << std::endl;
	std::cout << "                                                      ' " << char(196) << char(196) << char(196) << char(196) << char(196) << " '" << std::endl;
}

/**
 * @brief Function for printing the first part of the book's leafing to the left
*/
void pageLeafingLeft1()
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "         /" << char(179) << std::endl;
	std::cout << "        " << char(179) << " " << char(179) << "                                                           . " << char(196) << char(196) << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << char(196) << char(196) << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " ." << std::endl;
	std::cout << "        " << char(179) << " " << char(179) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << " .     . " << char(196) << " ' '                         ' " << char(196) << char(196) << char(196) << std::endl;
	std::cout << "        " << char(179) << " " << char(179) << "                                             \\   /                                      ' " << char(196) << " " << char(196) << " " << char(196) << " " << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187) << std::endl;
	std::cout << char(218) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(179) << " " << char(179) << "                                              \\ /                                                      " << char(186) << char(196) << char(191) << std::endl;
	for (int i = 0; i < 28; i++)
	{
		std::cout << char(179) << "       " << char(179) << " " << char(179) << "                                               |                                                       " << char(186) << " " << char(179) << std::endl;
	}
	std::cout << char(179) << "       " << char(179) << "/                                                |                                                       " << char(186) << " " << char(179) << std::endl;
	std::cout << char(179) << "        \\                                                |         . " << char(250) << " ' " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " ' " << char(250) << "                   " << char(186) << " " << char(179) << std::endl;
	std::cout << char(179) << "         '" << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << "  " << char(250) << " " << char(196) << " " << char(196) << " " << char(250) << " " << char(196) << char(196) << " " << char(250) << " .  |  . " << char(250) << " " << char(196) << char(196) << "    . " << char(250) << " ' " << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << " '    " << char(196) << char(196) << char(196) << char(196) << char(196) << "              " << char(186) << " " << char(179) << std::endl;
	std::cout << char(179) << "                                                       \\ | /  . " << char(250) << " " << char(196) << " " << char(196) << "                     " << char(250) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " ' " << char(205) << " " << char(205) << " " << char(205) << " " << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << " " << char(179) << std::endl;
	std::cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << " \\         / " << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(217) << std::endl;
	std::cout << "                                                      ' " << char(196) << char(196) << char(196) << char(196) << char(196) << " '" << std::endl;
}

/**
 * @brief Function for printing the first part of the book's leafing to the right
*/
void pageLeafingRight1()
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "                                                                                                           /" << char(179) << std::endl;
	std::cout << "                         . " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << char(196) << char(196) << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << char(196) << char(196) << " .                                                           " << char(179) << " " << char(179) << std::endl;
	std::cout << "                   " << char(196) << char(196) << char(196) << " '                         " << "' ' " << char(196) << " .     . " << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(179) << " " << char(179) << std::endl;
	std::cout << "  " << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << " " << char(196) << " " << char(196) << " " << char(196) << " '                                      \\   /                                             " << char(179) << " " << char(179) << std::endl;
	std::cout << char(218) << char(196) << char(186) << "                                                      \\ /                                              " << char(179) << " " << char(179) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(191) << std::endl;
	for (int i = 0; i < 28; i++)
	{
		std::cout << char(179) << " " << char(186) << "                                                       |                                               " << char(179) << " " << char(179) << "       " << char(179) << std::endl;
	}
	std::cout << char(179) << " " << char(186) << "                                                       |                                                \\" << char(179) << "       " << char(179) << std::endl;
	std::cout << char(179) << " " << char(186) << "                   " << char(250) << " ' " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " ' " << char(250) << " .         |                                                /        " << char(179) << std::endl;
	std::cout << char(179) << " " << char(186) << "              " << char(196) << char(196) << char(196) << char(196) << char(196) << "   " << " ' " << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << " ' " << char(250) << " .    " << char(196) << char(196) << " " << char(250) << " .  |  . " << char(250) << " " << char(196) << char(196) << " " << char(250) << " " << char(196) << " " << char(196) << " " << char(250) << "  " << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << "'         " << char(179) << std::endl;
	std::cout << char(179) << " " << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << " " << char(205) << " " << char(205) << " " << char(205) << " ' " << "                              " << char(196) << " " << char(196) << " " << char(250) << " .  \\ | /                                                       " << char(179) << std::endl;
	std::cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << " \\         / " << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(217) << std::endl;
	std::cout << "                                                      ' " << char(196) << char(196) << char(196) << char(196) << char(196) << " '" << std::endl;
}

/**
 * @brief Function for printing the second part of the book's leafing to the left
*/
void pageLeafingLeft2()
{
	std::cout << "                         /" << char(179) << std::endl;
	std::cout << "                        / " << char(179) << std::endl;
	std::cout << "                       /  " << char(179) << std::endl;
	std::cout << "                      /   " << char(179) << std::endl;
	std::cout << "                     /    " << char(179) << std::endl;
	std::cout << "                    " << char(250) << "     " << char(179) << std::endl;
	std::cout << "                    " << char(179) << "     " << char(179) << "                                           . " << char(196) << char(196) << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << char(196) << char(196) << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " ." << std::endl;
	std::cout << "                    " << char(179) << "     " << char(179) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << " .     . " << char(196) << " ' '                         ' " << char(196) << char(196) << char(196) << std::endl;
	std::cout << "                    " << char(179) << "     " << char(179) << "                             \\   /                                      ' " << char(196) << " " << char(196) << " " << char(196) << " " << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187) << std::endl;
	std::cout << char(218) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(179) << "     " << char(179) << "                              \\ /                                                      " << char(186) << char(196) << char(191) << std::endl;
	for (int i = 0; i < 22; i++)
	{
		std::cout << char(179) << "                   " << char(179) << "     " << char(179) << "                               |                                                       " << char(186) << " " << char(179) << std::endl;
	}
	std::cout << char(179) << "                   " << char(179) << "     " << char(179) << "                               |                                                       " << char(186) << " " << char(179) << std::endl;
	std::cout << char(179) << "                   " << char(179) << "    .'" << "                               |                                                       " << char(186) << " " << char(179) << std::endl;
	std::cout << char(179) << "                   " << char(179) << "  " << char(250) << "'                                 |                                                       " << char(186) << " " << char(179) << std::endl;
	std::cout << char(179) << "                   " << char(179) << " /                                   |                                                       " << char(186) << " " << char(179) << std::endl;
	std::cout << char(179) << "                   " << char(179) << "/                                    |                                                       " << char(186) << " " << char(179) << std::endl;
	std::cout << char(179) << "                    \\                                    |                                                       " << char(186) << " " << char(179) << std::endl;
	std::cout << char(179) << "                     \\                                   |                                                       " << char(186) << " " << char(179) << std::endl;
	std::cout << char(179) << "                      '" << char(250) << "_                                |         . " << char(250) << " ' " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " ' " << char(250) << "                   " << char(186) << " " << char(179) << std::endl;
	std::cout << char(179) << "                         '" << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << "  " << char(250) << " " << char(196) << " " << char(196) << " " << char(250) << " " << char(196) << char(196) << " " << char(250) << " .  |  . " << char(250) << " " << char(196) << char(196) << "    . " << char(250) << " ' " << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << " '    " << char(196) << char(196) << char(196) << char(196) << char(196) << "              " << char(186) << " " << char(179) << std::endl;
	std::cout << char(179) << "                                                       \\ | /  . " << char(250) << " " << char(196) << " " << char(196) << "                     " << char(250) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " ' " << char(205) << " " << char(205) << " " << char(205) << " " << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << " " << char(179) << std::endl;
	std::cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << " \\         / " << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(217) << std::endl;
	std::cout << "                                                      ' " << char(196) << char(196) << char(196) << char(196) << char(196) << " '" << std::endl;
}

/**
 * @brief Function for printing the second part of the book's leafing to the right
*/
void pageLeafingRight2()
{
	std::cout << "                                                                                         " << char(179) << "\\" << std::endl;
	std::cout << "                                                                                         " << char(179) << " \\" << std::endl;
	std::cout << "                                                                                         " << char(179) << "  \\" << std::endl;
	std::cout << "                                                                                         " << char(179) << "   \\" << std::endl;
	std::cout << "                                                                                         " << char(179) << "    \\" << std::endl;
	std::cout << "                                                                                         " << char(179) << "     \\" << std::endl;
	std::cout << "                                                                                         " << char(179) << "      " << char(250) << std::endl;
	std::cout << "                         . " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << char(196) << char(196) << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << char(196) << char(196) << " .                                          " << char(179) << "      " << char(179) << std::endl;
	std::cout << "                   " << char(196) << char(196) << char(196) << " '                         " << "' ' " << char(196) << " .     . " << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(179) << "      " << char(179) << std::endl;
	std::cout << "  " << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << " " << char(196) << " " << char(196) << " " << char(196) << " '                                      \\   /                            " << char(179) << "      " << char(179) << std::endl;
	std::cout << char(218) << char(196) << char(186) << "                                                      \\ /                             " << char(179) << "      " << char(179) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(191) << std::endl;
	for (int i = 0; i < 22; i++)
	{
		std::cout << char(179) << " " << char(186) << "                                                       |                              " << char(179) << "      " << char(179) << "                   " << char(179) << std::endl;
	}
	std::cout << char(179) << " " << char(186) << "                                                       |                               '.    " << char(179) << "                   " << char(179) << std::endl;
	std::cout << char(179) << " " << char(186) << "                                                       |                                 '.  " << char(179) << "                   " << char(179) << std::endl;
	std::cout << char(179) << " " << char(186) << "                                                       |                                   \\ " << char(179) << "                   " << char(179) << std::endl;
	std::cout << char(179) << " " << char(186) << "                                                       |                                    \\" << char(179) << "                   " << char(179) << std::endl;
	std::cout << char(179) << " " << char(186) << "                                                       |                                    /                    " << char(179) << std::endl;
	std::cout << char(179) << " " << char(186) << "                                                       |                                   /                     " << char(179) << std::endl;
	std::cout << char(179) << " " << char(186) << "                   " << char(250) << " ' " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " " << char(196) << " ' " << char(250) << " .         |                                _" << char(250) << "'                      " << char(179) << std::endl;
	std::cout << char(179) << " " << char(186) << "              " << char(196) << char(196) << char(196) << char(196) << char(196) << "   " << " ' " << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << " ' " << char(250) << " .    " << char(196) << char(196) << " " << char(250) << " .  |  . " << char(250) << " " << char(196) << char(196) << " " << char(250) << " " << char(196) << " " << char(196) << " " << char(250) << "  " << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << "'                         " << char(179) << std::endl;
	std::cout << char(179) << " " << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << " " << char(205) << " " << char(205) << " " << char(205) << " ' " << "                              " << char(196) << " " << char(196) << " " << char(250) << " .  \\ | /                                                       " << char(179) << std::endl;
	std::cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << " \\         / " << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(217) << std::endl;
	std::cout << "                                                      ' " << char(196) << char(196) << char(196) << char(196) << char(196) << " '" << std::endl;
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
