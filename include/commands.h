#include <string>
#include <history.h>
#pragma once
using namespace std;
bool handleCommand(string &command, list <string> &equation);
void readFile(const char *filename);
void printLocalHistory(list <string> &equation);
