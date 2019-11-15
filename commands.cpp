#include <commands.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <convert.h>
using namespace std;

bool handleCommand(string &commands, list <string> &equation) {
  int pos = commands.find(' ');
  string first = commands.substr(0, pos);
  string second = commands.substr(pos + 1);
  if (commands == "clear") {
    system("clear");
    return false;
  }
  else if (commands == "calc") {
    return true;
  }
  else if (commands == "quit") {
    return false;
  }
  else if (commands == "help") {
    readFile("README.md");
    return false;
  }
  else if (commands == "history") {
    printLocalHistory(equation);
    readFile("history.txt");
    return false;
  }
  else if (first == "delete") {
    if (second == "global") {
      deleteGlobalHistory();
      return false;
    }
    if (second == "local") {
      deleteLocalHistory(equation);
      return false;
    }
    if (equation.isEmpty()) {
      cout << "Nothing to delete!" << endl;
    }
    else {
      int eqnum;
      cout << "Which equation do you wish to delete?" << endl;
      scanf("%d", &eqnum);
      deleteEquation(equation, eqnum);
    }
  }
  else {
    system("clear");
  }
  return false;
}

void readFile(const char *filename) {
  ifstream myfile;
  myfile.open(filename, ios::in);
  bool commands = false;
  if (myfile.fail()) {
    cout << "Global History empty!" << endl;
    return ;
  }
  if (myfile.is_open()) {
    string line;
    if (!strcmp(filename, "README.md")) {
      while (getline(myfile, line)) {
        if (line[0] == 'C') {
          commands = true;
        }
        if (line[0] == 'M') {
          commands = false;
        }
        if (commands) {
          cout << line << endl;
        }
      }
    }
    else {
      cout << "Global History" << endl;
      int i = 1;
      while (getline(myfile, line)) {
        cout << i << ". " << line << endl;
        i++;
      }
    }
  }
  myfile.close();
}

void printLocalHistory(list <string> &equationList) {
  if (equationList.isEmpty()) {
    cout << "Local History Empty!" << endl;
  }
  else {
    cout << "Local History" << endl;
    ListNode <string>*iterator = equationList.getHead();
    int i = 1;
    while (iterator) {
      cout << i << ". " <<iterator->value << endl;
      iterator = iterator->next;
      i++;
    }
  }
}
