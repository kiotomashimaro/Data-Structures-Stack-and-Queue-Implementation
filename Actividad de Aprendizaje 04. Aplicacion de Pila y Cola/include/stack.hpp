// stack.hpp and .cpp
#ifndef __STACK_H__
#define __STACK_H__

#include "stackexception.hpp"
// DEFINITION
template <typename T, int ARRAYSIZE = 1024>
class Stack {
 private:
  T data[ARRAYSIZE];
  int top;

  void copyAll(const Stack<T, ARRAYSIZE>&);  // auxiliar method to copy elements
                                             // from another stack
 public:
  Stack();
  Stack(const Stack<T, ARRAYSIZE>&);  // starts the stack with another stack

  bool isEmpty();  // checks if its empty
  bool isFull();   // checks if its full

  void removeAll();  // removes all the data from the stack

  void push(const T&);  // inserts a element on the top
  void pop();           // removes the element from top

  T getTop();  // return the element in the top

  Stack<T, ARRAYSIZE>& operator=(const Stack<T, ARRAYSIZE>&);
};

// IMPLEMENTATION

template <typename T, int ARRAYSIZE>
void Stack<T, ARRAYSIZE>::copyAll(const Stack<T, ARRAYSIZE>& copyStack) {
  int i(0);
  while (i <= copyStack.top) {
    this->data[i] = copyStack.data[i];
    i++;
  }
  this->top = copyStack.top;
}

template <typename T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>::Stack() : top(-1) {}

template <typename T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>::Stack(const Stack<T, ARRAYSIZE>& copyStack) {
  copyAll(copyStack);
}

template <typename T, int ARRAYSIZE>
bool Stack<T, ARRAYSIZE>::isEmpty() {
  return top == -1;
}

template <typename T, int ARRAYSIZE>
bool Stack<T, ARRAYSIZE>::isFull() {
  return top == ARRAYSIZE - 1;
}

template <typename T, int ARRAYSIZE>
void Stack<T, ARRAYSIZE>::removeAll() {
  top = -1;
}

template <typename T, int ARRAYSIZE>
void Stack<T, ARRAYSIZE>::push(const T& element) {
  if (isFull()) {
    throw StackException("Desbordamiento de datos, push()");
  }

  top++;
  data[top] = element;
}

template <typename T, int ARRAYSIZE>
void Stack<T, ARRAYSIZE>::pop() {
  if (isEmpty()) {
    throw StackException("Insuficiencia de datos, pop()");
  }
  top--;
}

template <typename T, int ARRAYSIZE>
T Stack<T, ARRAYSIZE>::getTop() {
  if (isEmpty()) {
    throw StackException("Insuficiencia de datos, pop()");
  }
  return data[top];
}

template <typename T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>& Stack<T, ARRAYSIZE>::operator=(
    const Stack<T, ARRAYSIZE>& other) {
  copyAll(other);

  return *this;
}

#endif  // __STACK_H__