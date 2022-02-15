/*! @file animation.cpp
*   @brief A source file for the animations.
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
	delay(120);
	system("CLS");
	printOnePageLeafedBook();
	delay(120);
	system("CLS");
	pageLeafingLeftOne();
	delay(120);
	system("CLS");
	pageLeafingLeftTwo();
	delay(120);
	system("CLS");
	pageLeafingRightTwo();
	delay(120);
	system("CLS");
	pageLeafingRightOne();
	delay(120);
	system("CLS");
	printOpenedBook();
}

/**
 * @brief Function for printing reverse book animation.
*/
void reverseBookAnimation() 
{
	pageLeafingRightOne();
	delay(120);
	system("CLS");	
	pageLeafingRightTwo();
	delay(120);
	system("CLS");	
	pageLeafingLeftTwo();
	delay(120);
	system("CLS");	
	pageLeafingLeftOne();
	delay(120);
	system("CLS");	
	printOnePageLeafedBook();
	delay(120);
	system("CLS");	
	printOpenedBook();
}

/**
 * @brief Function for printing book opening animation.
*/
void bookOpeningAnimation()
{
	printSlightlyOpenBook();
	delay(120);
	system("CLS");
	printHalfOpenBook();
	delay(120);
	system("CLS");
	printAlmostOpenedBook();
	delay(120);
	system("CLS");
	printFullyOpenedBook();
	delay(120);
}

/**
 * @brief Function for printing reverse book opening animation.
*/
void reverseBookOpeningAnimation() {
	delay(120);
	printFullyOpenedBook();
	system("CLS");
	delay(120);
	printAlmostOpenedBook();
	system("CLS");
	delay(120);
	printHalfOpenBook();
	system("CLS");
	delay(120);
	printSlightlyOpenBook();
	printClosedBook();
	prinyBookDecorations();
	printSnakeSword();
	printTeamLogo();
}

/**
 * @brief Function for printing loading animation
*/
void loadingAnimation()
{
	delay(300);
	outputPosition(90, 15);
	std::cout << (char)254;
	delay(300);
	outputPosition(92, 15);
	std::cout << (char)254;
	delay(300);
	outputPosition(94, 15);
	std::cout << (char)254;
	delay(300);
	outputPosition(96, 15);
	std::cout << (char)254;
	delay(300);
	outputPosition(98, 15);
	std::cout << (char)254;
	delay(280);
	outputPosition(84, 17);
	std::cout << "PRESS ENTER TO START!";
}
