/*! @file lathraeaRhodopaea.cpp
*   @brief The main source file of the program.
*/

#include <iostream>
#include <back-end/accountSystem.h>

int main()
{
	try
	{
		accountManager.registerUser("Stoyan", "SS@cb.bg", "Password123", Roles::USER);
	}
	catch (const std::string errorMsg)
	{
		std::cout << "The user can not be registered\nReason: " + errorMsg << std::endl;;
	}
	catch (...)
	{
		std::cout << "Problem occurred. Please restart the program!";
	}
}
