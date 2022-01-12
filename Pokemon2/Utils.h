#pragma once
#include "EnumElements.h"
#include "Config.h"
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <windows.h>
#include <cstdlib>
#include <regex>

using std::cout;
using std::cin;
using std::endl;
using std::rand;
using std::regex;
using std::regex_replace;
using std::string;
using std::toupper;
using std::vector;


void pressEnter();
void clearScreen();
void pressEnterAndClear();
char readChar();
void emptyLine();
void emptyLine(int);
string getRandom(vector<string>);
int getRandomFrom(int, int);
EnumElement getRandomElement();
string getElementTxt(EnumElement);
string getRandomElementTxt();
string getNameFor(EnumElement);
string ltrim(const string&);
string rtrim(const string&);
string trim(const string&);
int dice(const int);
int dice(const int, const int);