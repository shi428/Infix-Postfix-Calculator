#include <history.h>
equation::equation(string &in, string &post) {
  infix = in;
  postfix = post;
}
void appendLocalHistory(equation *newEquation, list <equation> &equationList) {
  equationList.push_back(*newEquation);
  cout << newEquation->infix << "=" << newEquation->postfix << " has been added at position " << equationList.size() << endl;
}

void deleteLocalHistory(list <equation> &equationList) {
  equationList.deleteList();
  cout << "Local History has been deleted" << endl;
}

void deleteEquation(list <equation> &equationList, int num) {
  ListNode<equation> *iterator = equationList.getHead();
  for (int i = 0; i < num; i++) {
    iterator = iterator->next;
  }
  equationList.deleteNode(iterator);
}

