#include <stack.h>
#include <read.h>
#include <convert.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <list.h>
#include <commands.h>
#include <history.h>
using namespace std;
int main(int argc, char *argv[]) {
  string input;
  list <equation> equationList;
  do {
    list <string> infix;
    getline(cin, input);
    if (handleCommand(input, equationList)) {
      string expression;
      cout << "Enter an infix expression: ";
      getline(cin, expression);
      list <string> postfix;
      cout << "You entered: " << expression << endl;
      readString(expression, infix);
      cout << "Postfix: ";
      convert(infix, postfix);
      calculate(postfix);
      string answer = postfix.getHead()->value;
      equation *newEquation =  new equation(expression, answer);
      cout << "Do you wish to add this equation to your history?" << endl;
      string ans;
      getline(cin, ans);
      if (ans == "yes") {
        appendLocalHistory(newEquation, equationList);
      }
      delete newEquation;
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
