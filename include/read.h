#include <cstdbool>
#include <list.h>
#pragma once

const char array[] = {'+', '-', '*', '/', '^', '(', ')'};
int isOperator(char input);
bool validateInput(string &input);
bool isNumber(string &number);
void readString(string &input, list &equation);
bool findChar(string &str, char input, int pos);


