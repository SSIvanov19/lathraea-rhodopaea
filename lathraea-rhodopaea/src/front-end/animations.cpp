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
	printClosedBook();
	delay(70);
	printOnePageLeafedBook();
	delay(70);
	system("CLS");
	pageLeafingLeft1();
	delay(70);
	system("CLS");
	pageLeafingLeft2();
	delay(70);
	system("CLS");
	pageLeafingRight2();
	delay(70);
	system("CLS");
	pageLeafingRight1();
	delay(70);
	system("CLS");
	printOpenedBook();
}
