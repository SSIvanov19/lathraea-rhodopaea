# QA Documentation
# Introduction
The job of the QA engineer is very important, as he has to check if the code is correct. It’s not an easy job, as you always have to think of new ways to “break” the program so most of the problems in the code are corrected.

# Entry and exit criteria
## Entry Criteria
When the QA engineer starts his work, the program isn’t optimized and “cleared” from any problems it may have.

## Exit Criteria
When the QA engineer finished his work, the program is more optimized and up-to-date with less problems.

# Objectives and tasks
## Objective
The goal is that we end up with a complete and working product.

## Tasks
The tasks a QA engineer has to face are:
1.	Preparation of a QA documentation
2.	Testing the app
3.	Reports any problems
4.	Making a documentation about the corresponding problem

# Scope
The program has to be fully tested so any problems can be reported and solved.

# Test deliverables
The result of a tested program are that there will be fewer malfunctions and it will be more accessible for use.

# Test Cases
## Console and handle related function
### Test Case 1
| | | | | | | | |
|-|-|-|-|-|-|-|-|
| | |ID|TS1_001|Created by|Teodor Karchev| | |
| | |Name|Setting cursor| | | | |
| | |Description|Moving the cursor to a specific point in screen|Created on|06/11/2021| | |
| | | | | | | | |
| | |#|Description|Test Data|Expectations|Actual Result|Status|
| | |1|When starting of the game, it puts the mouse to a specific point.|X coordinate|Puts the cursor to the coordinates.|Puts the cursor to the coordinates.|PASSED|
| | | | |Y coordinate| | | |
### Test Case 2
| | | | | | | | |
|-|-|-|-|-|-|-|-|
| | |ID|TS1_002|Created by|Teodor Karchev| | |
| | |Name|Color change| | | | |
| | |Description|Changes the foreground color|Created on|06/11/2021| | |
| | | | | | | | |
| | |#|Description|Test Data|Expectations|Actual Result|Status|
| | |1|Changes the background of the game.|FOREGROUND_BLUE|Changes color to blue.|Changes color to blue.|PASSED|
| | | | | | | | |
| | |#|Description|Test Data|Expectations|Actual Result|Status|
| | |2|Changes the background of the game.|FOREGROUND_RED|Changes color to red.|Changes color to red.|PASSED|
### Test Case 3
| | | | | | | | |
|-|-|-|-|-|-|-|-|
| | |ID|TS1_003|Created by|Teodor Karchev| | |
| | |Name|Clear the console| | | | |
| | |Description|A function that clears the console|Created on|06/11/2021| | |
| | | | | | | | |
| | |#|Description|Test Data|Expectations|Actual Result|Status|
| | |1|Should clear the console.| |Clears the console.|Clears the console!|PASSED|

## Logs related function
### Test Case 1
| | | | | | | | |
|-|-|-|-|-|-|-|-|
| | |ID|TS2_001|Created by|Teodor Karchev| | |
| | |Name|Showing error on the screen and save it to the logs| | | | |
| | |Description|Shows a error and logs it into a file.|Created on|06/11/2021| | |
| | | | | | | | |
| | |#|Description|Test Data|Expectations|Actual Result|Status|
| | |1|Shows a error and logs it into a file.|Name of file|Shows a error and logs it into a file.|Shows a error and logs it into a file.|PASSED|
| | | | |Name of function| | | |
| | | | |Error code| | | |
| | | | |The message| | | |

## Menu related functions
### Test Case 1
| | | | | | | | |
|-|-|-|-|-|-|-|-|
| | |ID|TS3_001|Created by|Teodor Karchev| | |
| | |Name|Shows the options| | | | |
| | |Description|Checking if it prints the option of the given menu|Created on|06/11/2021| | |
| | | | | | | | |
| | |#|Description|Test Data|Expectations|Actual Result|Status|
| | |1|It should shows the option menu and we can select an option.|Vector that holds all the options.|Shows the option menu and we can select an option.|shows the option menu and we can select an option.|PASSED|
| | | | |Variable that represents the selected option| | | |
| | | | |Pointer to function| | | |

### Test Case 2
| | | | | | | | |
|-|-|-|-|-|-|-|-|
| | |ID|TS3_002|Created by|Teodor Karchev| | |
| | |Name|Shows the main logo| | | | |
| | |Description|Function that prints the main logo|Created on|06/11/2021| | |
| | | | | | | | |
| | |#|Description|Test Data|Expectations|Actual Result|Status|
| | |1|It should print the main logo of the game and team.| |Shows the main logo.|Shows the main logo.|PASSED|

### Test Case 3
| | | | | | | | |
|-|-|-|-|-|-|-|-|
| | |ID|TS3_003|Created by|Teodor Karchev| | |
| | |Name|Shows the settings logo| | | | |
| | |Description|Function that prints the settings logo|Created on|06/11/2021| | |
| | | | | | | | |
| | |#|Description|Test Data|Expectations|Actual Result|Status|
| | |1|It should print the settings logo of the game and team.| |Shows the settings logo.|Shows the settings logo.|PASSED|

### Test Case 4
| | | | | | | | |
|-|-|-|-|-|-|-|-|
| | |ID|TS3_004|Created by|Teodor Karchev| | |
| | |Name|Shows the settings menu| | | | |
| | |Description|Checking if it prints the settings menu.|Created on|06/11/2021| | |
| | | | | | | | |
| | |#|Description|Test Data|Expectations|Actual Result|Status|
| | |1|It should shows the settings menu.| |Shows the settings menu.|Shows the settings menu.|PASSED|

### Test Case 5
| | | | | | | | |
|-|-|-|-|-|-|-|-|
| | |ID|TS3_005|Created by|Teodor Karchev| | |
| | |Name|Show "how to play" logo| | | | |
| | |Description|Function that prints the "how to play" logo.|Created on|06/11/2021| | |
| | | | | | | | |
| | |#|Description|Test Data|Expectations|Actual Result|Status|
| | |1|It should print the "how to play" logo| |Shows the "how to play" logo.|shows the "how to play" logo.|PASSED|

### Test Case 6
| | | | | | | | |
|-|-|-|-|-|-|-|-|
| | |ID|TS3_006|Created by|Teodor Karchev| | |
| | |Name|Show the "how to play" menu| | | | |
| | |Description|Checking if it prints the "how to play" menu.|Created on|06/11/2021| | |
| | | | | | | | |
| | |#|Description|Test Data|Expectations|Actual Result|Status|
| | |1|It should shows the "how to play"menu|Number of selected options|Shows the "how to play" menu.|Shows the "how to play" menu.|PASSED|
| | | | |Should the logo be printed?| | | |

## Game related functions
### Test Case 1
| | | | | | | | |
|-|-|-|-|-|-|-|-|
| | |ID|TS4_001|Created by|Teodor Karchev| | |
| | |Name|Movement| | | | |
| | |Description|Testing if the movement is possible.|Created on|06/11/2021| | |
| | | | | | | | |
| | |#|Description|Test Data|Expectations|Actual Result|Status|
| | |1|When the player run into a wall not to get inside it.|X coordinate of the player|It doesn't go inside the wall.|It doesn't go inside the wall.|PASSED|
| | | | |Y coordinate of the player| | | |
### Test Case 2
| | | | | | | | |
|-|-|-|-|-|-|-|-|
| | |ID|TS4_002|Created by|Teodor Karchev| | |
| | |Name|Room drawing| | | | |
| | |Description|Draws a room/part of the map.|Created on|06/11/2021| | |
| | | | | | | | |
| | |#|Description|Test Data|Expectations|Actual Result|Status|
| | |1|It should draw a room with 2 to 4 doors to near rooms.|Pointer to dynamic two-dimensional array of Room|It doesn't go inside the wall.|It doesn't go inside the wall.|PASSED|
| | | | |The size of the room| | | |
### Test Case 3
| | | | | | | | |
|-|-|-|-|-|-|-|-|
| | |ID|TS4_003|Created by|Teodor Karchev| | |
| | |Name|Maze drawing| | | | |
| | |Description|Draws a maze.|Created on|06/11/2021| | |
| | | | | | | | |
| | |#|Description|Test Data|Expectations|Actual Result|Status|
| | |1|it should draw the maze for the player to move within.|Pointer to dynamic two-dimensional array of Room|Draws the maze.|Draws the maze.|PASSED|
| | | | |The size of the maze| | | |
### Test Case 4
| | | | | | | | |
|-|-|-|-|-|-|-|-|
| | |ID|TS4_004|Created by|Teodor Karchev| | |
| | |Name|Shows the player information| | | | |
| | |Description|Prints player information.|Created on|06/11/2021| | |
| | | | | | | | |
| | |#|Description|Test Data|Expectations|Actual Result|Status|
| | |1|It should prints player information (Health, Armour, etc) on the board.| |Prints Health, Armour, Keys amd money.|Prints Health, Armour, Keys amd money.|PASSED|
### Test Case 5
| | | | | | | | |
|-|-|-|-|-|-|-|-|
| | |ID|TS4_005|Created by|Teodor Karchev| | |
| | |Name|Shows a message on the UI| | | | |
| | |Description|Shows a message on the UI. (For example: Dialogue)|Created on|06/11/2021| | |
| | | | | | | | |
| | |#|Description|Test Data|Expectations|Actual Result|Status|
| | |1|It should show a message on the console.|The message to be shown|Shows a message.|Shows a message.|PASSED|
