#include "Creature.h"
#include "Messages.h"

#include <iostream>
#include <windows.h>
#include <regex>
#include <algorithm>
#include <string>

using std::regex;
using std::regex_match;
using std::string;
using std::transform;
using std::vector;

int main()
{
    vector<CapableCreature> CREAT_UNIVERSE{};



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
    string longInput;

    /*
        GENERATE CREATURES TO UNIVERSE
    */
    for (int i = 0; i < 18; i++) {
        CREAT_UNIVERSE.push_back( 
            CapableCreature{ getRandomElement() } 
        );
    }
    
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
        bool selectReviewStep;
        switch (input) {
            case 'R': // Review available creatures.
                clearScreen();
                selectReviewStep = false;
                while (!selectReviewStep) {
                    cout << SELECT_REVIEW << endl;
                    for (size_t i = 0; i < CREAT_UNIVERSE.size(); i++) {
                        CapableCreature curCreature = CREAT_UNIVERSE[i];
                        if (!curCreature.isSelected()) {
                            curCreature.printShort();
                        }
                    }
                    cout << SELECT_ENTER_ID << endl;
                    cin >> longInput;
                    // invalid input loop
                    //  if (regex_match ("softwareTesting", regex("(soft)(.*)") ))
                    while (!regex_match(longInput, regex("^(E|e|\\d+)$"))) {
                        cout << ENTER_VALID_COMMAND << endl;
                        cout << SELECT_ENTER_ID << endl;
                        cin >> longInput;
                    }
                    cout << "Your input is: " << longInput << endl;
                    // switch
                }
                break;
            case 'M': // Manage your team.
                clearScreen();
                cout << SELECT_MANAGE << endl;
                break;
            case 'G': // Choose your team at random.
                clearScreen();
                cout << SELECT_GENERATE << endl;
                teamCreatures = 6;
                break;
            case 'C': // End selection step and continue.
                clearScreen();
                cout << SELECT_CONTINUE << endl;
                selectStep = true;
                break;
            case 'X': // Exit without saving.
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

