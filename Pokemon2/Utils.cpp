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

string getNameFor(EnumElement e) {
    int random = getRandomFrom(0, 999);
    string name;
    if (random < 100) {
        name = getRandom(CREAT_DESCRIPTIONS);
    }
    if (random < 910) {
        vector<string> list;
        switch (e) {
        case FIRE:  list = CREAT_FIRE_NAMES;    break;
        case WATER: list = CREAT_WATER_NAMES;   break;
        case AIR:   list = CREAT_AIR_NAMES;     break;
        case EARTH: list = CREAT_EARTH_NAMES;   break;
        case ICE:   list = CREAT_ICE_NAMES;     break;
        case STEEL: list = CREAT_STEEL_NAMES;   break;
        default:                                break;
        };
        name = name + " " + getRandom(list);
    }
    return trim(name + " " + getRandom(CREAT_SPECIES));
}

// trim from: https://www.techiedelight.com/trim-string-cpp-remove-leading-trailing-spaces/
string ltrim(const string& s) {
    return regex_replace(s, regex("^\\s+"), string(""));
}

string rtrim(const string& s) {
    return regex_replace(s, regex("\\s+$"), string(""));
}

string trim(const string& s) {
    return ltrim(rtrim(s));
}

int dice(const int val) {
    if (val > 0) {
        return getRandomFrom(1, val);
    }
    return 0;
}

int dice(const int val, const int repeat) {
    int sum = 0;
    if (val > 0 and repeat > 0) {
        int counter = 0;
        while (counter++ < repeat) {
            sum += dice(val);
        }
    }
    return sum;
}

int compareMix(const EnumElement& source, const EnumElement& target) {
    switch (source) {
    case FIRE:
        switch (target) {
        case ICE:       case STEEL:     return 1;
        case WATER:     case EARTH:     return -1;
        default:        return 0;
        }
        break;
    case WATER:
        switch (target) {
        case WATER:     return -1;
        case EARTH:     case FIRE:      return 1;
        default:        return 0;
        }
        break;
    case AIR:
        switch (target) {
        case ICE:       return 1;
        case EARTH:     case STEEL:     return -1;
        default:        return 0;
        }
        break;
    case EARTH:
        switch (target) {
        case AIR:       return -1;
        case FIRE:      case ICE:       case STEEL:     return 1;
        default:        return 0;
        }
        break;
    case ICE:
        switch (target) {
        case EARTH:     return 1;
        case WATER:     case FIRE:      case ICE:       return -1;
        default:        return 0;
        }
        break;
    case STEEL:
        switch (target) {
        case FIRE:      case STEEL:     return -1;
        case WATER:     case AIR:       return 1;
        default:        return 0;
        }
        break;
    default: return 0;
    }
}