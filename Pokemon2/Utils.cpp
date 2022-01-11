#include "Utils.h"

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

char readChar() {
    char c;
    cin >> c;
    return toupper(c);
}

void emptyLine() {
    cout << endl;
}

void emptyLine(int n) {
    while (n-- > 0) {
        emptyLine();
    }
}

int getRandomFrom(int fromRange, int toRange) {
    return (rand() % (toRange - fromRange + 1)) + fromRange;
}

string getRandom(vector<string> list) {
    int random = rand() % list.size();
    return list[random];
}

EnumElement getRandomElement() {
    return EnumElement(rand() % 6);
}

string getElementTxt(EnumElement e) {
    return toString(e);
}

string getRandomElementTxt() {
    return getElementTxt(getRandomElement());
}