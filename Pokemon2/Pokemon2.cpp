#include <iostream>
#include <windows.h>

#include "Messages.h"
#include "Config.h"
#include "Utils.h"



int main()
{
    /*
        WELCOME STEP
    */
    cout << MAIN_INTRODUCTION << endl;
    cout << GRAND_TITLE << endl;
    cout << COMMAND_ENTER << endl;
    pressEnterAndClear();

    /*
        ENTER NAME
    */
    cout << ENTER_NAME << endl;
    string playerName;
    cin >> playerName;
    cout << NAME_CONFIRM << playerName << endl;
    cout << HAVE_NICE_GAME << endl;
    emptyLine(3);
    pressEnter();

    /*
        TEAM SELECTION
    */
    cout << playerName << X_TIME_TO_CREATE_TEAM << endl;
    bool selectStep = false;
    int teamCreatures = 0;
    char input;
    
    while (!selectStep) {
        cout << SELECTION_MENU << endl;
        cout << YOUR_TEAM_NUMBER << teamCreatures << endl;
        input = readChar();
        
        //  Invalid input loop.
        while ( input != 'R' and 
                input != 'M' and 
                input != 'G' and
                input != 'C' and 
                input != 'X') {
            cout << ENTER_VALID_COMMAND << endl;
            cout << SELECTION_MENU << endl;
            input = readChar();
        }

        // SELECT options
        switch (input) {
            case 'R':
                clearScreen();
                cout << SELECT_REVIEW << endl;
                cout << "Random from 1 to 6 is: " << endl;
                for (int i = 0; i < 10; i++) {
                    cout << getNameFor(getRandomElement()) << endl;
                }
                break;
            case 'M':
                clearScreen();
                cout << SELECT_MANAGE << endl;
                break;
            case 'G':
                clearScreen();
                cout << SELECT_GENERATE << endl;
                teamCreatures = 6;
                break;
            case 'C':
                clearScreen();
                cout << SELECT_CONTINUE << endl;
                selectStep = true;
                break;
            case 'X':
                clearScreen();
                cout << EXIT_MSG << endl;
                return EXIT_SUCCESS;
            default:
                break;
                // nie powinno się zdarzyć
        }
    }

    /*
        START TOURNAMENT
    */
    clearScreen();
    cout << START_TOURNAMENT << endl;
    pressEnter();
    
    int gameRound = 0;
    int defeatedOpponents = 0;

    gameRound++;
    while (gameRound <= 4) {
        bool gameRoundFinished = false;
        while (!gameRoundFinished) {
            bool actionFilled = false;
            while (!actionFilled) {
                cout << GAME_ROUND << gameRound << endl;
                cout << GAME_MENU << endl;
                input = readChar();
                // check for invalid input
                while ( input != 'E' and
                        input != 'R' and
                        input != 'H' and
                        input != 'D' and
                        input != 'L' and
                        input != 'S' and
                        input != 'X') {
                    cout << ENTER_VALID_COMMAND << endl;
                    cout << GAME_MENU << endl;
                    input = readChar();
                }

                // GAME options
                switch (input) {
                case 'E':
                    clearScreen();
                    cout << GAME_ENTER_STAGE << endl;
                    actionFilled = true;
                    break;
                case 'R':
                    clearScreen();
                    cout << GAME_REVIEW << endl;
                    break;
                case 'H':
                    clearScreen();
                    cout << GAME_HIGHSCORES << endl;
                    break;
                case 'D':
                    clearScreen();
                    cout << GAME_DESCRIPTION << endl;
                    break;
                case 'L':
                    clearScreen();
                    cout << GAME_LOAD << endl;
                    break;
                case 'S':
                    clearScreen();
                    cout << GAME_SAVE << endl;
                    break;
                case 'X':
                    clearScreen();
                    cout << EXIT_MSG << endl;
                    return EXIT_SUCCESS;
                default:
                    break;
                    // nie powinno się zdarzyć
                }
            }
            cout << OPPONENT_INFO << OPPONENT_NAME_PLACEHOLDER << endl;
            cout << FIGHT_VICTORY << OPPONENT_NAME_PLACEHOLDER << endl;
            gameRoundFinished = true;
            gameRound++;
        }
    }

    cout << WINNING << endl;

}

