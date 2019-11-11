template <class T>
void convert(list <T>& equation, list <T> postfix) {
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
