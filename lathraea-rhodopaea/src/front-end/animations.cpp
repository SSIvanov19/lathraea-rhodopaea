#include <iostream>
#include <windows.h>
#include <front-end/graphics.h>

/**
 * @brief Structure for setting the delay time
*/
struct Timer {
	void operator()()
	{
		Sleep(70);
	}
};

Timer delay;

/**
 * @brief Function for printing book leafing animation
*/
void bookAnimation()
{
	printOnePageLeafedBook();
	delay();
	system("CLS");
	pageLeafingLeft1();
	delay();
	system("CLS");
	pageLeafingLeft2();
	delay();
	system("CLS");
	pageLeafingRight2();
	delay();
	system("CLS");
	pageLeafingRight1();
	delay();
	system("CLS");
	printOpenedBook();
}
