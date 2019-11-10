#include <string>
#include <cstdbool>
#pragma once

using namespace std;

typedef struct listnode {
  struct listnode *prev;
  struct listnode *next;
  string value;
}ListNode;
class list {
  public:
    list();
    ~list();
    ListNode *addNode(string input);
    void push_back(string input);
    void pop_back();
    void insertAfter(ListNode *before, string input);
    void push_front(string input);
    void pop_front();
    void deleteNode(ListNode *remove);
    ListNode *search(string input);
    bool isEmpty();
    void traverse();
    ListNode *getHead();
    ListNode *getTail();
    ListNode *goForward(ListNode *input);
  private:
    ListNode *head;
    ListNode *tail;
};
