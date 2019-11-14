#include <convert.h>
#include <iostream>
using namespace std;
double stringToNum(string &data) {
  double ret;
  stringstream conv(data);
  conv >> ret;
  return ret;
}
string numToString(double data) {
  string ret;
  stringstream conv;
  conv << data;
  conv >> ret;
  return ret;
}

string getInfix(list <string> &infix) {
  string ret;
  ListNode<string> *iterator = infix.getHead();
  while (iterator) {
    ret = ret + iterator->value;
    iterator = iterator->next;
  }
  return ret;
}
template <class T>
void convert(list <T>& equation, list <T>& postfix) {
  ListNode <T> *iterator = equation.getHead();
  stack operators;
  while (iterator) {
    if (isListOperator(iterator->value.c_str()) == -1) {
      postfix.push_back(iterator->value);
    }
    else if (isListOperator(iterator->value.c_str()) == 5) {
      operators.push(iterator->value);
    }
    else if (isListOperator(iterator->value.c_str()) == 6) {
      while (isListOperator(operators.getTop().c_str()) != 5) {
        if (isListOperator(operators.getTop().c_str()) != 6 && isListOperator(operators.getTop().c_str()) != 5) {
          postfix.push_back(operators.getTop());
        }
        operators.pop();
      }
      operators.pop();
    }
    else {
      if (isListOperator(iterator->value.c_str()) == 4) {
        operators.push(iterator->value);
      }
      if (isListOperator(iterator->value.c_str()) == 2 || isListOperator(iterator->value.c_str()) == 3) {
        if (!operators.isEmpty() && isListOperator(operators.getTop().c_str()) == 4) {
          postfix.push_back(operators.getTop());
          operators.pop();
        }
        if (!operators.isEmpty()) {
          if (isListOperator(operators.getTop().c_str()) == 2 || isListOperator(operators.getTop().c_str()) == 3) {
            postfix.push_back(operators.getTop());
            operators.pop();
          }
        }
        operators.push(iterator->value);
      }
      if (isListOperator(iterator->value.c_str()) == 0 || isListOperator(iterator->value.c_str()) == 1) {
        if (!operators.isEmpty() && isListOperator(operators.getTop().c_str()) > 1 &&isListOperator(operators.getTop().c_str()) < 5) {
          postfix.push_back(operators.getTop());
          operators.pop();
        }
        if (!operators.isEmpty()) {
          if (isListOperator(operators.getTop().c_str()) == 1 || isListOperator(operators.getTop().c_str()) == 0) {
            postfix.push_back(operators.getTop());
            operators.pop();
          }
        }
        operators.push(iterator->value);
      }
    }
    iterator = equation.goForward(iterator);
  }
  while (!operators.isEmpty()) {
    postfix.push_back(operators.getTop());
    operators.pop();
  }
  postfix.traverse();
}
void calculate(list<string>&postfix) {
  int opFound = -1;
  while (postfix.size() > 1) {
    ListNode<string> *iterator = postfix.getHead();
    while (iterator) {
      if ((opFound = isListOperator(iterator->value.c_str())) != -1) {
        break;
      }
      iterator = postfix.goForward(iterator);
    }
      ListNode<string> *first = postfix.goBackward(iterator);
      ListNode<string> *second = postfix.goBackward(first);
      ListNode<string> *prev = postfix.goBackward(second);
    if (!opFound) {
      double firstOp = stringToNum(first->value);
      double secondOp = stringToNum(second->value);
      double sum = firstOp + secondOp;
      postfix.deleteNode(iterator);
      postfix.deleteNode(first);
      postfix.deleteNode(second);
      string insert = numToString(sum);
      if (postfix.isEmpty()) {
        postfix.push_back(insert);
      }
      else {
        if (prev) {
        postfix.insertAfter(prev, insert);
        }
        else {
          postfix.push_front(insert);
        }
      }
    }
    else if (opFound == 1) {
      double firstOp = stringToNum(first->value);
      double secondOp = stringToNum(second->value);
      double difference = secondOp - firstOp;
      postfix.deleteNode(iterator);
      postfix.deleteNode(first);
      postfix.deleteNode(second);
      string insert = numToString(difference);
      if (postfix.isEmpty()) {
        postfix.push_back(insert);
      }
      else {
        if (prev) {
        postfix.insertAfter(prev, insert);
        }
        else {
          postfix.push_front(insert);
        }
      }
    }
    else if (opFound == 2) {
      double firstOp = stringToNum(first->value);
      double secondOp = stringToNum(second->value);
      double product = firstOp * secondOp;
      postfix.deleteNode(iterator);
      postfix.deleteNode(first);
      postfix.deleteNode(second);
      string insert = numToString(product);
      if (postfix.isEmpty()) {
        postfix.push_back(insert);
      }
      else {
        if (prev) {
        postfix.insertAfter(prev, insert);
        }
        else {
          postfix.push_front(insert);
        }
      }
    }
    else if (opFound == 3) {
      double firstOp = stringToNum(first->value);
      double secondOp = stringToNum(second->value);
      double quotient = secondOp / firstOp;
      postfix.deleteNode(iterator);
      postfix.deleteNode(first);
      postfix.deleteNode(second);
      string insert = numToString(quotient);
      if (postfix.isEmpty()) {
        postfix.push_back(insert);
      }
      else {
        if (prev) {
        postfix.insertAfter(prev, insert);
        }
        else {
          postfix.push_front(insert);
        }
      }
    }
    else if (opFound == 4) {
      double firstOp = stringToNum(first->value);
      double secondOp = stringToNum(second->value);
      double exponent = pow(secondOp, firstOp);
      postfix.deleteNode(iterator);
      postfix.deleteNode(first);
      postfix.deleteNode(second);
      string insert = numToString(exponent);
      if (postfix.isEmpty()) {
        postfix.push_back(insert);
      }
      else {
        if (prev) {
        postfix.insertAfter(prev, insert);
        }
        else {
          postfix.push_front(insert);
        }
      }
    }
  }
  cout << "Answer: ";
  postfix.traverse();
}
template void convert<string>(list <string> &equation, list <string> &postfix);
