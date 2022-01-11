#pragma once
#include <iostream>
#include <cctype>
#include <windows.h>
#include <cstdlib>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::rand;
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