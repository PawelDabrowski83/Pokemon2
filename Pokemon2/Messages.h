#pragma once
#include <string>
#include "Utils.h"



const string MAIN_INTRODUCTION = "Welcome to text-based experience called...";

/*
Solution for multiline strings: https://stackoverflow.com/a/55689576/13521548
Ascii art from: https://patorjk.com/software/taag/#p=display&f=JS%20Stick%20Letters&t=Grand
*/
const char* GRAND_TITLE = R""""(
         __   __             __  
        / _` |__)  /\  |\ | |  \ 
        \__> |  \ /~~\ | \| |__/

___  __        __                   ___      ___ 
 |  /  \ |  | |__) |\ |  /\   |\/| |__  |\ |  |  
 |  \__/ \__/ |  \ | \| /~~\  |  | |___ | \|  |

)""""; 
const string COMMAND_ENTER = "Press [ENTER] to continue.";
const string ENTER_NAME = "Please enter your player name and then press [ENTER].";
const string NAME_CONFIRM = "Nice to see you, ";
const string HAVE_NICE_GAME = "Have a nice game!";
const char* MAIN_MENU = R""""(
Please enter proper character to make a valid selection:
[ E ] = Enter the stage.
[ R ] = Review your team.
[ H ] = Check highscores.
[ L ] = Load game.
[ S ] = Save game.
[ X ] = Exit game without saving.
)"""";

const string X_TIME_TO_CREATE_TEAM = ", it is time to build your team!";
const char* SELECTION_MENU = R""""(
TEAM SELECTION:
Use controls to review available creatures and add them to your team. 
Your team need 6 creatures.

[ R ] = Review available creatures.
[ M ] = Manage your team.
[ G ] = Choose your team at random.
[ C ] = End selection step and continue.
[ E ] = Exit without saving.
)"""";
const string YOUR_TEAM_NUMBER = "Number of creatures in your team: ";
const string SELECT_REVIEW = "Review available creatures.";
const string SELECT_MANAGE = "Manage your team.";

const string ENTER_VALID_COMMAND = "Please enter valid command.";
