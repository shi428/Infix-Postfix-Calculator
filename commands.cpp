#include <commands.h>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

bool handleCommand(string &commands, list <equation> &equation) {
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
    return false;
  }

  return false;
}

void readFile(const char *filename) {
  ifstream myfile;
  myfile.open(filename, ios::in);
  bool commands = false;
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
      myfile.close();
    }
  }
}

void printLocalHistory(list <equation> &equationList) {
  if (equationList.isEmpty()) {
    cout << "history empty!" << endl;
    return ;
  }
  else {
    ListNode <equation>*iterator = equationList.getHead();
    int i = 1;
    while (iterator) {
      cout << i << " " << iterator->value.infix << "=" <<  iterator->value.postfix << endl;
      iterator = iterator->next;
      i++;
    }
  }
}


