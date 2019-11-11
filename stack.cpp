#include <iostream>
#include <stack.h>
using namespace std;

stack::stack() {
  this->top = NULL;
  this->bottom = NULL;
}
stack::~stack() {
  StackNode *iterator = bottom;
  while (iterator) {
    StackNode *next = iterator->next;
    delete iterator;
    iterator = next;
  }
}

StackNode *stack::addNode(string input) {
  StackNode *newNode = new StackNode;
  newNode->value = input;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

void stack::push(string input) {
  if (!bottom) {
    bottom = addNode(input);
    top = bottom;
  }
  else {
    StackNode *temp = top;
    top = addNode(input); 
    top->prev = temp;
    temp->next = top;
  }
}

void stack::pop() {
  cout << top->value << endl;
  if (bottom == NULL) {
    cerr << "Stack empty!" << endl;
    return ;
  }
  if (top == bottom) {
    delete bottom;
    bottom = NULL;
    top = bottom;
  }
  else {
    StackNode *prev = top->prev;
    delete top;
    top = prev;
    top->next = NULL;
  }
}

void stack::traverse() {
  StackNode *iterator = bottom;
  if (isEmpty()) {
    return ;
  }
  cerr << "Values in the stack" << endl;
  while (iterator) {
    cout << iterator->value << " ";
    iterator = iterator->next;
  }
  cerr << endl;
}

bool stack::isEmpty() {
  if (!bottom) {
    return true;
  }
  return false;
}

string &stack::getTop() {
  return top->value;
}

string &stack::getBottom() {
  return top->value;
}

