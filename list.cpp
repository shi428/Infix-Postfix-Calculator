#include <iostream>
#include <list.h>
#include <stdio.h>
using namespace std;
list::list() {
  head = NULL;
  tail = NULL;
}

list::~list() {
  ListNode *iterator = head;
  while (iterator) {
    ListNode *next = iterator->next;
    delete iterator;
    iterator = next;
  }
}

ListNode *list::addNode(string input) {
  ListNode *newNode = new ListNode;
  newNode->value = input;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

void list::push_back(string input) {
  cout << input << endl;
  if (!head) {
    head = addNode(input);
    tail = head;
  }
  else {
    ListNode *temp = tail;
    tail = addNode(input); 
    tail->prev = temp;
    temp->next = tail;
  }
}

void list::pop_back() {
  if (head == NULL) {
    cerr << "List empty!" << endl;
    return ;
  }
  if (tail == head) {
    delete head;
    head = NULL;
    tail = head;
  }
  else {
    ListNode *prev = tail->prev;
    delete tail;
    tail = prev;
    tail->next = NULL;
  }
}

void list::insertAfter(ListNode *before, string input) {
  ListNode *insert = addNode(input);
  ListNode *next = before->next;
  before->next = insert;
  insert->next = next;
  next->prev = insert;
  insert->prev = before;
}

void list::push_front(string input) {
  if (!head) {
    head = addNode(input);
    tail = head;
  }
  else {
  ListNode *newHead = addNode(input);
  newHead->next = head;
  head->prev = newHead;
  head = newHead;
  }
}

void list::pop_front() {
  if (!head) {
    cerr << "List Empty!" << endl;
    return;
  }
  ListNode *temp = head;
  delete temp;
  head = head->next;
  if (head) {
    head->prev = NULL;
  }
}

void list::deleteNode(ListNode *remove) {
  if (!remove) {
    cerr << "item does not exist in the linked list!" << endl;
    return ;
  }
  if (remove == head) {
    pop_front();
    return ;
  }
  if (remove == tail) {
    pop_back();
    return ;
  }
  ListNode *iterator = head;
  while (iterator) {
    if (iterator->next == remove) {
      ListNode *next = remove->next;
      delete remove;
      iterator = next;
      return ;
    }
    iterator = iterator->next;
  }
}

ListNode *list::search(string input) {
  ListNode *iterator = head;
  while (iterator) {
    if (iterator->value == input) {
      return iterator;
    }
  }
  return NULL;
}

bool list::isEmpty() {
  if (!head) {
    return true;
  }
  return false;
}

void list::traverse() {
  if (isEmpty()) {
    return ;
  }
  ListNode *iterator = head;
  cerr << "items in the list" << endl;
  while (iterator) {
    cout << iterator->value << " ";
    iterator = iterator->next;
  }
  cerr << endl;
}

ListNode *list::getHead() {
  return head;
}

ListNode *list::getTail() {
  return tail;
}

ListNode *list::goForward(ListNode *input) {
  if (!input) {
    return NULL;
  }
  return input->next;
}
