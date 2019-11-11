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
  list <string>test;
  getline(cin, input);
  list <string> postfix;
  readString(input, test);
  convert(test, postfix);
  return EXIT_SUCCESS;
}
