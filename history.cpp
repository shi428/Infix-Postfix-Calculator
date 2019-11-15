#include <history.h>
#include <fstream>
#include <convert.h>
using namespace std;
void appendLocalHistory(string equation, list <string> &equationList) {
  equationList.push_back(equation);
}

void appendGlobalHistory(string equation) {
  ofstream file;
  file.open("history.txt", ios::app);
  file << equation << endl;
  file.close();
}

void deleteLocalHistory(list <string> &equationList) {
  equationList.deleteList();
  cout << "Local History has been deleted!" << endl;
}

void deleteGlobalHistory() {
  fstream file;
  file.open("history.txt", ios::in);
  if (file.fail()) {
    cerr << "failed to open file!" << endl;
    return;
  }
  if (file.is_open()) {
    if (remove("history.txt")) {
      cerr << "failed to remove file!" << endl;
    }
    else {
      cout << "Glboal history has been deleted!" << endl;
    }
  }
}

void deleteEquation(list <string> &equationList, int num) {
  ifstream file;
  ofstream file2;
  string line;
  file.open("history.txt", ios::in);
  file2.open("copy.txt", ios::out);
  if (file.fail() || file2.fail()) {
    cerr << "file failed to open!" << endl;
    return ;
  }
  ListNode<string> *iterator = equationList.getHead();
  for (int i = 1; i < num; i++) {
    iterator = iterator->next;
  }
  bool found = false;
  if (file.is_open() && file2.is_open()) {
    while (getline(file, line)) {
      if (iterator->value != line && !found) {
        file2 << line << endl;
        found = true;
      }
    }
  }
  file.close();
  rename("copy.txt", "history.txt");
  file2.close();
  equationList.deleteNode(iterator);
}

bool fetchHistory(string &insert, list <string>&equationList) {
  if (equationList.isEmpty()) {
    ifstream myfile;
    myfile.open("history.txt");
    if (myfile.fail()) {
      cout << "failed to load history!" << endl;
      return false ;
    }
    else {
      if (myfile.is_open()) {
        string line;
        while (getline(myfile, line)) {
          insert = line.substr(line.find("=") + 1);
        }
      }
    }
  }
  else {
    string eq = equationList.getTail()->value;
    insert = eq.substr(eq.find("=") + 1);
  }
  return true;
}
