#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <conio.h>
#include <front-end/output.h>
#include <front-end/graphics.h>
#include <front-end/animations.h>
#include <front-end/mainMenu.h>
#include <front-end/enumerations.h>
#include <back-end/eventManager.h>
#include <back-end/datetimeManager.h>
#include <back-end/validations.h>
#include <application.h>

/**
 * @brief Function for entering and validating registration data
 * @return Accout information
*/
std::vector<std::string> enterRegisterData()
{
    Validations validations;

    std::vector<std::string> accountInformation;


    std::string email, uname, password;
     printBlankSpace(6, 18);
    outputPosition(7, 18);
    std::cout << "Enter an email: ";

    std::getline(std::cin, email);
    while (!validations.isEmailValid(email))
    {
        outputPosition(7, 20);
        std::cout << "Please, enter a valid email: ";
        std::getline(std::cin, email);
        std::cout << std::endl;
        outputPosition(7, 20);
        std::cout << "                                                         " << std::endl;     
    }

    std::cout << std::endl;
    outputPosition(7, 20);
    std::cout << "Enter a username: ";
    std::getline(std::cin, uname);
    while (!validations.isUnameValid(uname))
    {
        outputPosition(7, 22);
        std::cout << "Please, enter a valid uname: ";
        std::getline(std::cin, uname);
        std::cout << std::endl;
        outputPosition(7, 22);
        std::cout << "                                                         " << std::endl;
    }

    std::cout << std::endl;
    outputPosition(7, 22);
    std::cout << "Enter a password: ";
    std::getline(std::cin, password);
    while (!validations.isPassValid(password))
    {
        outputPosition(7, 24);
        std::cout << "Please, enter a valid password: ";
        std::getline(std::cin, password);
        std::cout << std::endl;
        outputPosition(7, 24);
        std::cout << "                                                         " << std::endl;
    }

    accountInformation.push_back(email);
    accountInformation.push_back(uname);
    accountInformation.push_back(password);

    return accountInformation;
}

/**
 * @brief Function for registering a user
 * @param accountManager Variable for an account manager
*/
void registerUser(AccountManager* accountManager)
{
    std::vector<std::string> newAccount = enterRegisterData();  
    try
    {
        accountManager->registerUser(
            newAccount[1],
            newAccount[0],
            newAccount[2],
            Roles::USER
        );
        printBlankSpace(7, 18);
    }
    catch (std::string errorMessage)
    {
        outputPosition(7, 26);
        std::cout << errorMessage;
        _getch();
        printBlankSpace(7, 18);
    }
}

/**
 * @brief Function for loging in user
 * @return Login data
*/
std::vector<std::string> enterLoginData()
{
    std::vector<std::string> loginData;

    std::string email, password;

    printBlankSpace(6, 18);
    outputPosition(7, 18);
    std::cout << "Enter an email: ";
    std::getline(std::cin, email);

    std::cout << std::endl;
    outputPosition(7, 20);
    std::cout << "Enter a password: ";
    std::getline(std::cin, password);

    loginData.push_back(email);
    loginData.push_back(password);
    return loginData;
}

/**
 * @brief Function for loging in user
 * @param accountManager Variable for an account manager
 * @return
*/
bool isUserLogedIn(AccountManager* accountManager)
{
    std::vector<std::string> loginData = enterLoginData();

    try
    {
        accountManager->loginUser(loginData[0], loginData[1]);
        printBlankSpace(6, 18);
        return true;
    }
    catch (std::string errorMessage)
    {
        outputPosition(7, 22);
        std::cout << errorMessage;
        _getch();
        printBlankSpace(7, 18);
        return false;
    }
}

/**
 * @brief Function for coloring hovered login/register options
 * @param accountManager Variable for an account manager
 * @param key key The pressed button
 * @param selectedOption The selected option
 * @param possibleOptions The possible options
*/
bool switchLoginOptions(
    AccountManager* accountManager,
    char key,
    int& selectedOption,
    std::vector<std::string> possibleOptions
)
{
    bool isLoginSuccessful = false;
    switch (key)
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
        if (selectedOption == possibleOptions.size() + 1)
        {
            selectedOption -= 1;
        }
        break;
    case (int)ARROW_KEYS::KEY_ENTER:
        switch (selectedOption)
        {
        case 1: isLoginSuccessful = isUserLogedIn(accountManager);
            break;
        case 2: registerUser(accountManager);
            break;
        case 3:
            clearConsole();
            exit(0);
            break;
        }
    }
    return isLoginSuccessful;
}

/**
 * @brief Function for login and register
 * @param accountManager Variable for an account manager
*/
void accountMenu(AccountManager& accountManager)
{
    bool isLoginSuccessful;

    const std::vector<std::string> loginOptions =
    {
        "Login",
        "Register",
        "Exit"
    };

    char pressedKey;
    int selectedOption = 1;

    bool firstTime = true;

    while (selectedOption)
    {
        if (firstTime)
        {
            printClosedBook();
            printBookDecorations();
            printSnakeSword();
            printTeamLogo();
            firstTime = false;
        }

        outputOptions(loginOptions, selectedOption);
        pressedKey = _getch();
        isLoginSuccessful = switchLoginOptions(
            &accountManager, 
            pressedKey,
            selectedOption,
            loginOptions
        );

        if (isLoginSuccessful)
        {
            break;
        }
    }
}

