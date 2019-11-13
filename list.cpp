#include <iostream>
//#include <list.h>
#include <stdio.h>
using namespace std;
template <class T>
list<T>::list() {
  head = NULL;
  tail = NULL;
}

template <class T>
list<T>::~list() {
  ListNode<T> *iterator = head;
  while (iterator) {
    ListNode<T> *next = iterator->next;
    delete iterator;
    iterator = next;
  }
}

template <class T>
ListNode<T> *list<T>::addNode(T input) {
  ListNode<T> *newNode = new ListNode<T>;
  newNode->value = input;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

template <class T>
void list<T>::push_back(T input) {
//  cout << input << endl;
  if (!head) {
    head = addNode(input);
    tail = head;
  }
  else {
    ListNode<T> *temp = tail;
    tail = addNode(input); 
    tail->prev = temp;
    temp->next = tail;
  }
}

template <class T>
void list<T>::pop_back() {
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
    ListNode<T> *prev = tail->prev;
    delete tail;
    tail = prev;
    tail->next = NULL;
  }
}

template <class T>
void list<T>::insertAfter(ListNode<T> *before, T input) {
  ListNode<T> *insert = addNode(input);
  ListNode<T> *next = before->next;
  before->next = insert;
  insert->next = next;
  next->prev = insert;
  insert->prev = before;
}

template <class T>
void list<T>::push_front(T input) {
  if (!head) {
    head = addNode(input);
    tail = head;
  }
  else {
  ListNode<T> *newHead = addNode(input);
  newHead->next = head;
  head->prev = newHead;
  head = newHead;
  }
}

template <class T>
void list<T>::pop_front() {
  if (!head) {
    cerr << "List Empty!" << endl;
    return;
  }
  ListNode<T> *next = head->next;
  delete head;
  head = next;
  if (head) {
    head->prev = NULL;
  }
}

template <class T>
void list<T>::deleteNode(ListNode<T> *remove) {
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
  ListNode<T> *iterator = head;
  while (iterator) {
    if (iterator->next == remove) {
      ListNode<T> *next = remove->next;
      delete remove;
      iterator->next = next;
      next->prev = iterator;
      return ;
    }
    iterator = iterator->next;
  }
}

template <class T>
ListNode<T> *list<T>::search(T input) {
  ListNode<T> *iterator = head;
  while (iterator) {
    if (iterator->value == input) {
      return iterator;
    }
    iterator = iterator->next;
  }
  return NULL;
}

template <class T>
bool list<T>::isEmpty() {
  if (!head) {
    return true;
  }
  return false;
}

template <class T>
void list<T>::traverse() {
  if (isEmpty()) {
    return ;
  }
  ListNode<T> *iterator = head;
//  cerr << "items in the list" << endl;
  while (iterator) {
    cout << iterator->value << " ";
    iterator = iterator->next;
  }
  cerr << endl;
}

template <class T>
ListNode<T> *list<T>::getHead() {
  return head;
}

template <class T>
ListNode<T> *list<T>::getTail() {
  return tail;
}

template <class T>
ListNode<T> *list<T>::goForward(ListNode<T> *input) {
  if (!input) {
    return NULL;
  }
  return input->next;
}
template <class T>
ListNode<T> *list<T>::goBackward(ListNode<T> *input) {
  if (!input) {
    return NULL;
  }
  return input->prev;
}

template <class T>
int list<T>::size() {
  int i = 0;
  ListNode <T>*iterator = head;
  while (iterator) {
    iterator = iterator->next;
    i++;
  }
  return i;
}

template <class T>
void list<T>::deleteList() {
  while (!isEmpty()) {
    pop_back();
  }
}

