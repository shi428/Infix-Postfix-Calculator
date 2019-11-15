#include <cstring>
#include <read.h>
#include <ctype.h>
#include <iostream>
#include <history.h>

using namespace std;

int isListOperator(const char *input) {
  int counter = 0;
  for (auto i: array) {
    if (*input == i) {
      if (counter == 1 && !isdigit(input[1])) {
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

int isOperator(char input) {
  int counter = 0;
  for (auto i: array) {
    if (input == i) {
      return counter;
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

bool readString(string &input, list<string> &infix, list<string> &equationList) {
  int i = 0; 
  bool first = true;
  string insert;
  int wordbegin = 0;
  bool negative = false;
  int negloc = 0;
  for (auto j: input) {
    int opRem = 0;
    if (j == '~') {
      char sign = '-';
      negative = true;
      stringstream ss;
      ss << sign;
      ss >> insert;
      negloc = i;
    }
    if (isOperator(j) != -1) {
      if (first) {
        if (!negative) {
          if (i != 0) {
            insert = input.substr(0, i);
            if (insert == "ans") {
              if (!fetchHistory(insert, equationList)) {
                cout << "Please try again" << endl;
                return false;
              }
            }
            infix.push_back(insert);
          }
        }
        else {
          string rest = input.substr(1, i - 1);
          if (rest == "ans") {
            if (!fetchHistory(rest, equationList)) {
              cout << "Please try again" << endl;
              return false;
            }
          }
          insert = insert + rest;
          infix.push_back(insert);
          negative = false;
        }
        wordbegin = i + 1;
        first = false;
        insert = input.substr(i, 1);
        infix.push_back(insert);
      }
      else {
        if (!negative) {
          if (i != wordbegin) {
            insert = input.substr(wordbegin, i - wordbegin);
            if (insert == "ans") {
              if (!fetchHistory(insert, equationList)) {
                cout << "Please try again" << endl;
                return false;
              }
            }
            infix.push_back(insert);
          }
        }
        else {
          string rest = input.substr(negloc + 1, i - (negloc + 1));
          if (rest == "ans") {
            if (!fetchHistory(rest, equationList)) {
              cout << "Please try again" << endl;
              return false;
            }
          }
          insert = insert + rest;
          infix.push_back(insert);
          negative = false;
        }
        wordbegin = i + 1;
        insert = input.substr(i, 1);
        infix.push_back(insert);
      }
    }
    for (auto k: array) {
      if (!findChar(input, k, i)) {
        opRem++;
      }
    }
    if (opRem == 7) {
      string negsign;
      if (j == '~') {
        negsign.push_back('-');
        negative = true;
      }
      if (negative) {
        string sub;
        if ((sub = input.substr(i + 1)) == "ans") {
          if (!fetchHistory(insert, equationList)) {
            cout << "Please try again" << endl;
            return false;
          }
        }
        insert = negsign + sub;
      }
      else {
        insert = input.substr(i);
        if (insert == "ans") {
          if (!fetchHistory(insert, equationList)) {
            cout << "Please try again" << endl;
            return false;
          }
        }
      }
      infix.push_back(insert);
      break;
    }
    i++;
  }
  return true;
}
