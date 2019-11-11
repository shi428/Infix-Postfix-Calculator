#include <cstring>
#include <read.h>
#include <ctype.h>
#include <iostream>

using namespace std;

int isOperator(char *input) {
  int counter = 0;
  for (auto i: array) {
    if (*input == i) {
      if (counter == 1 && isdigit(input[1])) {
        return counter;
      }
      if (counter != 1) {
        return counter;
      }
    }
    counter++;
  }
  return -1;
}

bool findChar(string &str, char input, int pos) {
  for (unsigned i = pos; i < str.length(); i++) {
    if (str[i] == input) {
      return true;
    }
  }
  return false;
}

bool isNumber(string &aString) {
  for (auto i: aString) {
    if (!isdigit(i) && !isspace(i)) {
      return false;
    }
  }
  return true;
}

bool validateInput(string &input) {
  return true;
}
