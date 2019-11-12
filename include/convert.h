#include <read.h>
#include <stack.h>
#include <sstream>
#include <string>
#include <cmath>
#pragma once

using namespace std;
template <class T>
void convert(list <T>& equation, list<T>&postfix);
void calculate(list<string> & postfix);
double stringToNum(string &data);
string numToString(double data);
#include "../convert.cpp"
