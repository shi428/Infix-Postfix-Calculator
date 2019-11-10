#include <stack.h>
#include <read.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <list.h>
using namespace std;

int main(int argc, char *argv[]) {
  string input;
  list test;
  getline(cin, input);
 // bool beginning = true;
/*  for (unsigned int i = 0; i < input.length(); i++) {
    if (beginning) {
      unsigned int j = 0;
      while (isOperator(&input[j]) == -1 && input[j] != ' ' && j < input.length()) {
        j++;
      }
      string insert;
      bool op = true;
        if (j != 0) {
          insert = input.substr(0, j);
          test.push_back(insert);
        }
        else {
          insert = input.substr(0, 1);
          test.push_back(insert);
          op = false;
        }
        beginning = false;
        i = j;
        if (j != input.length() && op) {
          insert = input.substr(0, 1);
          test.push_back(insert);
        }
    }
    else {
      unsigned int j = i;
      while (isOperator(&input[j]) == -1 && input[j] != ' ' && j < input.length()) {
        j++;
      }
      string insert;
      unsigned int k = i;
      bool op = true;
      if (input[i] != ' ') {
        if (k != j) {
          insert = input.substr(i, j - i);
          test.push_back(insert);
        }
        else {
          insert = input.substr(i, 1);
          test.push_back(insert);
          op = false;
        }
        i = j;
        if (j != input.length() && op) {
          insert = input.substr(i, 1);
          test.push_back(insert);
        }
      }
    }
  }*/
/*  bool check = validateInput(test);
  if (!check) {
    return EXIT_FAILURE;
  }*/
  readString(input, test);
  while (!test.isEmpty()) {
    test.traverse();
    test.pop_back();
  }
  return EXIT_SUCCESS;
}
