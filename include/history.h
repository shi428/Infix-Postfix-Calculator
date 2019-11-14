#include <string>
#include <list.h>
#include <iostream>
#include <convert.h>
#pragma once
using namespace std;
void appendLocalHistory(string equation, list <string>&equationList);
void deleteLocalHistory(list <string> &equationList);
void deleteGlobalHistory();
void deleteEquation(list <string> &equationList, int num);
void appendGlobalHistory(string equation);
bool fetchHistory(string &insert, list <string> &equationList);
