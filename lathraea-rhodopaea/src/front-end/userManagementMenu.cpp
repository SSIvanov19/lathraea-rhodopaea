#include <front-end/userManagementMenu.h>
#include <front-end/output.h>
#include <front-end/graphics.h>
#include <front-end/enumerations.h>

void addNewAdmin(AccountManager* accountManager)
{
	Validations validations;

	std::string email;
	std::string uname;
	std::string password;

	outputPosition(81, 10);
	std::cout << "Enter an email: ";

	std::getline(std::cin, email);

	while (!validations.isEmailValid(email))
	{
		outputPosition(81, 12);
		std::cout << "Please, enter a valid email: ";
		std::getline(std::cin, email);
		std::cout << std::endl;
		outputPosition(81, 12);
		std::cout << "                                                    " << std::endl;
	}

	std::cout << std::endl;
	outputPosition(81, 12);
	std::cout << "Enter a username: ";
	std::getline(std::cin, uname);
	while (!validations.isUnameValid(uname))
	{
		outputPosition(81, 14);
		std::cout << "Please, enter a valid uname: ";
		std::getline(std::cin, uname);
		std::cout << std::endl;
		outputPosition(81, 14);
		std::cout << "                                                    " << std::endl;
	}

	std::cout << std::endl;
	outputPosition(81, 14);
	std::cout << "Enter a password: ";
	std::getline(std::cin, password);
	while (!validations.isPassValid(password))
	{
		outputPosition(81, 16);
		std::cout << "Please, enter a valid password: ";
		std::getline(std::cin, password);
		std::cout << std::endl;
		outputPosition(81, 16);
		std::cout << "                                                    " << std::endl;
	}

	try
	{
		accountManager->registerUser(uname, email, password, Roles::ADMIN);
	}
	catch (std::string msg)
	{
		outputPosition(81, 18);
		std::cout << "There was problem with the regestration:";
		outputPosition(81, 19);
		std::cout << msg;
		outputPosition(81, 20);
		std::cout << "Please try again!";
		(void)_getch();
	}

}

/**
 * @brief Function for stringifying a enum
 * @param role Role as a enum
 * @return Role as a string
*/
std::string enumToString(Roles role)
{
	switch (role)
	{
	case Roles::USER:
		return "User";
		break;
	case Roles::ADMIN:
		return "Admin";
		break;
	default:
		return "User";
		break;
	}
}

void showUserInfo(Account account, AccountManager* accountManager)
{
	std::vector<std::string> options = {
		"Make admin",
		"Remove user",
		"Back"
	};

	outputPosition(81, 10);
	std::cout << "Account info:";
	outputPosition(81, 11);
	std::cout << "Username: " << account.uname;
	outputPosition(81, 12);
	std::cout << "Email: " << account.email;
	outputPosition(81, 13);
	std::cout << "Role: " << enumToString(account.role);
	outputPosition(81, 15);
	std::cout << "Choose actions:";
	int selectedOption = 1;
	char pressedKey = ' ';

	while (pressedKey != (int)ARROW_KEYS::KEY_ENTER)
	{
		for (int i = 0; i < options.size(); i++)
		{
			if (i + 1 == selectedOption)
			{
				outputPosition(81, 16 + i);
				std::cout << "-> ";
			}
			else
			{
				outputPosition(81, 16 + i);
				std::cout << "   ";
			}
			std::cout << options[i] << std::endl << std::endl;
		}

		pressedKey = _getch();

		switch (pressedKey)
		{
		case (int)ARROW_KEYS::KEY_UP:
			selectedOption--;
			if (selectedOption == 0)
			{
				selectedOption += 1;
			}
			break;

		case (int)ARROW_KEYS::KEY_DOWN:
			selectedOption++;
			if (selectedOption == options.size() + 1)
			{
				selectedOption -= 1;
			}
			break;
		case (int)ARROW_KEYS::KEY_ENTER:
			clearConsole();
			printFullyOpenedBook();

			switch (selectedOption)
			{
			case 1:
				// Make admin
				accountManager->changeUserRoleToAdmin(account.email);
				return;
				break;
			case 2:
				if (!accountManager->removeAccount(
					&accountManager->accountList,
					account.email
				))
				{
					throw std::string("There was a problem with the program. Error deleteing user");
				}

				return;
				break;
			case 3:
				// Back
				return;
				break;
			}
		case (int)ARROW_KEYS::KEY_ESC:
			// Return to main menu
			clearConsole();
			printClosedBook();
			printBookDecorations();
			printSnakeSword();
			printTeamLogo();
			return;
			break;
		}
	}

	if (_getch())
	{
		clearConsole();
		printClosedBook();
		printBookDecorations();
		printSnakeSword();
		printTeamLogo();
	}
}

void viewAllUsers(AccountManager* accountManager)
{
	std::vector<Account> allAccounts = accountManager->getAllUserData();

	printFullyOpenedBook();
	outputPosition(81, 10);
	std::cout << "Choose which user you want to view:";

	int selectedOption = 1;
	char pressedKey = ' ';

	while (pressedKey != (int)ARROW_KEYS::KEY_ENTER)
	{
		for (int i = 0; i < allAccounts.size(); i++)
		{
			if (i + 1 == selectedOption)
			{
				outputPosition(81, 12 + i * 2);
				std::cout << "-> ";
			}
			else
			{
				outputPosition(81, 12 + i * 2);
				std::cout << "   ";
			}
			std::cout << allAccounts[i].uname << " - " 
				<< allAccounts[i].email << std::endl << std::endl;
		}

		pressedKey = _getch();

		switch (pressedKey)
		{
		case (int)ARROW_KEYS::KEY_UP:
			selectedOption--;
			if (selectedOption == 0)
			{
				selectedOption += 1;
			}
			break;

		case (int)ARROW_KEYS::KEY_DOWN:
			selectedOption++;
			if (selectedOption == allAccounts.size() + 1)
			{
				selectedOption -= 1;
			}
			break;
		case (int)ARROW_KEYS::KEY_ENTER:
			clearConsole();
			printFullyOpenedBook();
			showUserInfo(allAccounts[int(selectedOption)- 1], accountManager);
		case (int)ARROW_KEYS::KEY_ESC:
			// Return to main menu
			clearConsole();
			printClosedBook();
			printBookDecorations();
			printSnakeSword();
			printTeamLogo();
			return;
			break;
		}
	}

	if (_getch())
	{
		clearConsole();
		printClosedBook();
		printBookDecorations();
		printSnakeSword();
		printTeamLogo();
	}
}
