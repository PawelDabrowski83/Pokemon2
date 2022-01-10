#include <iostream>
#include <windows.h>

#include "Messages.h"
#include "Utils.h"

using std::cout;
using std::endl;


int main()
{
    cout << MAIN_INTRODUCTION << endl;
    cout << GRAND_TITLE << endl;
    cout << COMMAND_ENTER << endl;
    pressEnterAndClear();
}

