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
    cout << playerName << endl;

    /*
        TEAM SELECTION
    */
}

