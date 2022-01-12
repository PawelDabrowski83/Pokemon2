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

vector<CapableCreature> CREAT_UNIVERSE{};
vector<CapableCreature*> YOUR_TEAM{};

void showIntro();
void showYourTeam();
void fillCreatureUniverse(const int);
void confirmPlayerNameWith(const string&);
void promptForMenuSelect();
void promptInvalidMenuSelect();
void promptSelectCreatureToTeam();


const int CREATURES_IN_UNIVERSE = 18;

int main()
{
    showIntro();
    fillCreatureUniverse(CREATURES_IN_UNIVERSE);

    cout << ENTER_NAME << endl;
    string playerName;
    cin >> playerName;
    confirmPlayerNameWith(playerName);

    /*
        TEAM SELECTION
    */
    cout << playerName << X_TIME_TO_CREATE_TEAM << endl;
    bool selectStep = false;
    char input;
    string longInput;
    
    while (!selectStep) { // loop for SELECT menu
        promptForMenuSelect();
        input = readChar();
        
        //  Invalid input loop.
        while ( input != 'R' and input != 'M' and input != 'G' and 
                input != 'C' and input != 'X') {
            promptInvalidMenuSelect();
            input = readChar();
        }

        bool selectReviewFinished;
        int numberBuffer;
        switch (input) {
            case 'R': // Review available creatures.
                clearScreen();
                selectReviewFinished = YOUR_TEAM.size() >= 6 ? true : false;
                while (!selectReviewFinished) {
                    promptSelectCreatureToTeam();
                    cin >> longInput;
                    // invalid input loop
                    while (!regex_match(longInput, regex("^E$|^e$|^\\d+$"))) {
                        cout << ENTER_VALID_COMMAND << endl;
                        cout << SELECT_ENTER_ID << endl;
                        cin >> longInput;
                    }
                    if (longInput == "e" or longInput == "E") {
                        selectReviewFinished = true;
                    }
                    else {
                        numberBuffer = stoi(longInput);
                        if (numberBuffer >= Creature::getCount()) {
                            cout << SELECT_INVALID_ID << endl;
                        }
                        else {
                            CapableCreature* selectedCreature = &CREAT_UNIVERSE[numberBuffer];
                            if (selectedCreature->isSelected()) {
                                cout << SELECT_CREAT_ALREADY_SELECTED << endl;
                            }
                            else {
                                YOUR_TEAM.push_back(selectedCreature);
                                selectedCreature->setSelected(true);
                                selectReviewFinished = YOUR_TEAM.size() >= 6 ? true : false;
                            }
                            
                        }
                    }
                    showYourTeam();
                }
                
                if (YOUR_TEAM.size() >= 6) {
                    cout << SELECT_TEAM_MEMBERS_LIMIT << endl;
                    selectReviewFinished = true;
                    showYourTeam();
                }
                break;
            case 'M': // Manage your team.
                clearScreen();
                cout << SELECT_MANAGE << endl;
                showYourTeam();
                break;
            case 'G': // Choose your team at random.
                clearScreen();
                cout << SELECT_GENERATE << endl;
                while (YOUR_TEAM.size() < 6) {
                    int randomIndex = getRandomFrom(0, Creature::getCount() - 1);
                    CapableCreature* randomCreature = &CREAT_UNIVERSE[randomIndex];
                    if (!randomCreature->isSelected()) {
                        YOUR_TEAM.push_back(randomCreature);
                        randomCreature->setSelected(true);
                    }
                }
                break;
            case 'C': // End selection step and continue.
                clearScreen();
                if (YOUR_TEAM.size() != 6) {
                    cout << SELECT_CONTINUE_FAIL << endl;
                }
                else {
                    cout << SELECT_CONTINUE << endl;
                    selectStep = true;
                }
                
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
    
    int gameRound = 0;
    int defeatedOpponents = 0;

    gameRound++;
    while (gameRound <= 4) {
        bool gameRoundFinished = false;
        while (!gameRoundFinished) {
            bool actionFilled = false;
            while (!actionFilled) {
                pressEnter();
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

void showYourTeam() {
    cout << "Your team is: " << endl;
    for (size_t i = 0; i < YOUR_TEAM.size(); i++) {
        CapableCreature* curCreature = YOUR_TEAM[i];
        if (curCreature->isSelected()) {
            curCreature->printShort();
        }
    }
}

void showIntro() {
    cout << MAIN_INTRODUCTION << endl;
    cout << GRAND_TITLE << endl;
    cout << COMMAND_ENTER << endl;
    pressEnterAndClear();
}

void promptForMenuSelect() {
    cout << SELECTION_MENU << endl;
    cout << YOUR_TEAM_NUMBER << YOUR_TEAM.size() << endl;
}

void promptInvalidMenuSelect() {
    cout << ENTER_VALID_COMMAND << endl;
    cout << SELECTION_MENU << endl;
}

void promptSelectCreatureToTeam() {
    cout << SELECT_REVIEW << endl;
    for (size_t i = 0; i < CREAT_UNIVERSE.size(); i++) {
        CapableCreature* curCreature = &CREAT_UNIVERSE[i];
        if (!curCreature->isSelected()) {
            curCreature->printShort();
        }
    }
    cout << SELECT_ENTER_ID << endl;
}

void fillCreatureUniverse(const int bound) {
    for (int i = 0; i < bound; i++) {
        CREAT_UNIVERSE.push_back(
            CapableCreature{ getRandomElement() }
        );
    }
}

void confirmPlayerNameWith(const string& playerName) {
    cout << NAME_CONFIRM << playerName << endl;
    cout << HAVE_NICE_GAME << endl;
    emptyLine(3);
    pressEnter();

}