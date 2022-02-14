/*! @file animation.cpp
*   @brief A source file for the animations.
*/

#include <iostream>
#include <windows.h>
#include <front-end/graphics.h>


/**
 * @brief Function for setting the delay time 
 * @param seconds The seconds of delay
*/
void delay(int seconds)
{
	Sleep(seconds);
}

/**
 * @brief Function for printing book leafing animation
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

void reverseBookAnimation() {
	printOpenedBook();
	system("CLS");
	delay(120);
	pageLeafingRightOne();
	system("CLS");
	delay(120);
	pageLeafingRightTwo();
	system("CLS");
	delay(120);
	pageLeafingLeftTwo();
	system("CLS");
	delay(120);
	pageLeafingLeftOne();
	system("CLS");
	delay(120);
	printOnePageLeafedBook();
	system("CLS");
	delay(120);
	printOpenedBook();
}

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
}
