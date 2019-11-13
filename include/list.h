#include <string>
#include <cstdbool>
#pragma once

using namespace std;
template <class T>

struct ListNode {
  ListNode<T>() {
  }
  struct ListNode *prev;
  struct ListNode *next;
  T value;
};
template <class T>
class list {
  public:
    list();
    ~list();
    ListNode<T> *addNode(T input);
    void push_back(T input);
    void pop_back();
    void insertAfter(ListNode<T> *before, T input);
    void push_front(T input);
    void pop_front();
    void deleteNode(ListNode<T> *remove);
    ListNode<T> *search(T input);
    bool isEmpty();
    void traverse();
    ListNode<T> *getHead();
    ListNode<T> *getTail();
    ListNode<T> *goForward(ListNode<T> *input);
    ListNode<T> *goBackward(ListNode<T> *input);
    int size();
    void deleteList();
  private:
    ListNode<T> *head;
    ListNode<T> *tail;
};
#include "../list.cpp"
