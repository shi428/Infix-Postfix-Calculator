#include <stack.h>
#include <read.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <list.h>
#include <convert.h>
#include <history.h>
#include <commands.h>
using namespace std;
int main(int argc, char *argv[]) {
  string input;
  list <string> equationList;
  do {
    list <string> infix;
    getline(cin, input);
    if (handleCommand(input, equationList)) {
      string expression;
      cout << "Enter an infix expression: ";
      getline(cin, expression);
      list <string> postfix;
      cout << "You entered: " << expression << endl;
      readString(expression, infix, equationList);
      cout << "Postfix: ";
      convert(infix, postfix);
      calculate(postfix);
      string answer = postfix.getHead()->value;
      string in = getInfix(infix);
      string hist = in+"="+answer;
      appendLocalHistory(hist, equationList);
      appendGlobalHistory(hist);
    }
  } while (input != "quit");
  /* list <char> a;
     a.size();
     a.push_back('c');
     a.push_front('b');
     a.size();
     a.pop_front();
     a.size();
     a.traverse();*/
  return EXIT_SUCCESS;
}
