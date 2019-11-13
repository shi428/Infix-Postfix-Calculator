#include <string>
#include <list.h>
#include <history.h>
#pragma once
using namespace std;
bool handleCommand(string &command, list <equation> &equation);
void readFile(const char *filename);
void printLocalHistory(list <equation> &equation);
