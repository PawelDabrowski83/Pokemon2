#include <iostream>
#include <windows.h>

#include "Messages.h"
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
    pressEnterAndClear();

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
        cin >> input;
        
        /*
            Invalid input loop.
        */
        while ( input != 'R' and 
                input != 'M' and 
                input != 'G' and
                input != 'C' and 
                input != 'E') {
            cout << ENTER_VALID_COMMAND << endl;
            cout << SELECTION_MENU << endl;
            cin >> input;
        }

        /*
            Execution of Select commands.
        */
        switch (input) {
            case 'R':
                clearScreen();
                cout << SELECT_REVIEW << endl;
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

}

