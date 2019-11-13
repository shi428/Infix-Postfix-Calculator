#include <string>
#include <list.h>
#include <iostream>
#pragma once
using namespace std;
struct equation{
  equation() {
  }
  equation(string &in, string &post);
  string infix;
  string postfix;
};

void appendLocalHistory(equation *newEquation, list <equation>&equationList);
void deleteLocalHistory(list <equation> &equationList);
void deleteEquation(list <equation> &equationList, int num);
void appendGlobalHistory(equation &newEquation);
