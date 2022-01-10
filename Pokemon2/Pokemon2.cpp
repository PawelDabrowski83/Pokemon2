#include <iostream>
#include <limits>
#include "Messages.h"


using std::cout;
using std::endl;
using std::cin;
using std::streamsize;

int main()
{
    cout << MAIN_INTRODUCTION << endl;
    cout << GRAND_TITLE << endl;
    cout << COMMAND_ENTER << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
}
