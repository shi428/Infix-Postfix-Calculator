#include <stack.h>
#include <read.h>
#include <convert.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <list.h>
using namespace std;
int main(int argc, char *argv[]) {
  string input;
  list <string> test;
  cout << "Enter an infix expression: ";
  getline(cin, input);
  list <string> postfix;
  cout << "You entered: " << input << endl;
  readString(input, test);
  cout << "Postfix: ";
  convert(test, postfix);
  calculate(postfix);
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
