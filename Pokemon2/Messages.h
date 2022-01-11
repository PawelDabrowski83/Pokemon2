#pragma once
#include "Utils.h"
#include <string>



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
const char* GAME_MENU = R""""(
Please enter proper character to make a valid selection:
[ E ] = Enter the stage.
[ R ] = Review your team.
[ H ] = Check highscores.
[ D ] = Read in-depth description of what is going on.
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
[ X ] = Exit without saving.
)"""";
const string YOUR_TEAM_NUMBER = "Number of creatures in your team: ";
const string SELECT_REVIEW = "Review available creatures.";
const string SELECT_MANAGE = "Manage your team.";
const string SELECT_GENERATE = "Generate randomly your team.";
const string SELECT_CONTINUE = "Confirm your selection and go to next step.";
const string EXIT_MSG = "Thank you for choosing our game!";

const string ENTER_VALID_COMMAND = "Please enter valid command.";

const char* START_TOURNAMENT = R""""(
Grant Tournament last 4 rounds, on each you need to defeat 4 opponent creatures!
Whenever you lose a fight, you are defeated.

On each fight you and your opponent will alterate on their moves.
On your move - choose your action to see the result.

It is possible to change your creature during fight, if you want to strategize. 
Remember that only one creature will get xp points for defeating the opponent.
)"""";

const string GAME_ROUND = "Game round number: ";
const string GAME_ENTER_STAGE = "Enter the stage and fight!";
const string GAME_REVIEW = SELECT_REVIEW;
const string GAME_HIGHSCORES = "Visit the Hall of Champions.";
const string GAME_DESCRIPTION = "Read the lore.";
const string GAME_LOAD = "Load game.";
const string GAME_SAVE = "Save game.";
const string GAME_EXIT = EXIT_MSG;


const string OPPONENT_INFO = "A wild opponent appears. It is: ";
const string OPPONENT_NAME_PLACEHOLDER = "Oppomon!";
const string FIGHT_VICTORY = "You have won with ";
const string FIGHT_LOST = "You have been defeated by ";



const string WINNING = "Grats! You have won and now you are joining Grand Tournament's Hall of Champions.";
const string GENERAL_PLACEHOLDER = "This function is under development and may be accesible in future releases.";
