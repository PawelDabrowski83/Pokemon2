#include <iostream>
#include "Messages.h"
#include <windows.h>

using std::cout;
using std::endl;
using std::cin;
using std::string;

void pressEnter();
void pressEnterAndClear();
void clearScreen();

int main()
{
    cout << MAIN_INTRODUCTION << endl;
    cout << GRAND_TITLE << endl;
    cout << COMMAND_ENTER << endl;
    pressEnterAndClear();
}

/*
    Press enter thanks to: https://stackoverflow.com/a/903230/13521548
*/
void pressEnter() {
    cin.ignore();
}

/*
    Clearing screen: https://stackoverflow.com/a/5866648/13521548
*/

void clearScreen() {
    COORD tl = { 0,0 };
    CONSOLE_SCREEN_BUFFER_INFO s;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(console, &s);
    DWORD written, cells = s.dwSize.X * s.dwSize.Y;
    FillConsoleOutputCharacter(console, ' ', cells, tl, &written);
    FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
    SetConsoleCursorPosition(console, tl);
}

void pressEnterAndClear() {
    pressEnter();
    clearScreen();
}