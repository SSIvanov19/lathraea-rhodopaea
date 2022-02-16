/*! @file animations.cpp
*   @brief A source file for the application animations.
*/

#include <iostream>
#include <windows.h>
#include <front-end/graphics.h>
#include <front-end/output.h>


/**
 * @brief Function for setting the delay time.
 * @param seconds The seconds of delay
*/
void delay(int seconds)
{
	Sleep(seconds);
}

/**
 * @brief Function for printing book leafing animation.
*/
void bookAnimation()
{
	printOpenedBook();
	delay(100);
	clearConsole();
	printOnePageLeafedBook();
	delay(100);
	clearConsole();
	pageLeafingLeftOne();
	delay(100);
	clearConsole();
	pageLeafingLeftTwo();
	delay(10);
	clearConsole();
	pageLeafingRightTwo();
	delay(100);
	clearConsole();
	pageLeafingRightOne();
	delay(100);
	clearConsole();
	printOpenedBook();
}

/**
 * @brief Function for printing reverse book animation.
*/
void reverseBookAnimation() 
{
	pageLeafingRightOne();
	delay(120);
	clearConsole();	
	pageLeafingRightTwo();
	delay(120);
	clearConsole();	
	pageLeafingLeftTwo();
	delay(120);
	clearConsole();	
	pageLeafingLeftOne();
	delay(120);
	clearConsole();	
	printOnePageLeafedBook();
	delay(120);
	clearConsole();	
	printOpenedBook();
}

/**
 * @brief Function for printing book opening animation.
*/
void bookOpeningAnimation()
{
	printSlightlyOpenBook();
	delay(120);
	clearConsole();
	printHalfOpenBook();
	delay(120);
	clearConsole();
	printAlmostOpenedBook();
	delay(120);
	clearConsole();
	printFullyOpenedBook();
	delay(120);
}

/**
 * @brief Function for printing reverse book opening animation.
*/
void reverseBookOpeningAnimation() {
	delay(120);
	printFullyOpenedBook();
	clearConsole();
	delay(120);
	printAlmostOpenedBook();
	clearConsole();
	delay(120);
	printHalfOpenBook();
	clearConsole();
	delay(120);
	printSlightlyOpenBook();
	printClosedBook();
	printBookDecorations();
	printSnakeSword();
	printTeamLogo();
}

/**
 * @brief Function for printing loading animation
*/
void loadingAnimation()
{
	delay(200);
	outputPosition(90, 15);
	std::cout << (char)254;
	delay(200);
	outputPosition(92, 15);
	std::cout << (char)254;
	delay(200);
	outputPosition(94, 15);
	std::cout << (char)254;
	delay(200);
	outputPosition(96, 15);
	std::cout << (char)254;
	delay(200);
	outputPosition(98, 15);
	std::cout << (char)254;
	delay(180);
	outputPosition(84, 17);
	std::cout << "PRESS ENTER TO START!";
}
