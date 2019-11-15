#include <cstdbool>
#include <list.h>
#include <sstream>
#pragma once

const char array[] = {'+', '-', '*', '/', '^', '(', ')'};
int isListOperator(const char *input);
int isOperator(char input);
bool validateInput(string &input);
bool isNumber(string &number);
bool findChar(string &str, char input, int pos);
bool readString(string &input, list<string> &infix, list<string> &equationList);

