#include <cstdbool>
#include <string>
#pragma once

using namespace std;

typedef struct stacknode {
  struct stacknode *prev;
  struct stacknode *next;
  string value;
}StackNode;

class stack {
  public:
    stack();
    ~stack();
    void push(string input);
    void pop();
    void traverse();
    StackNode *addNode(string input);
    bool isEmpty();
  private:
    StackNode *top;
    StackNode *bottom;
};
