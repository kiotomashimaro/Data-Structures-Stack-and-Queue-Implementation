// interface.hpp
#ifndef __INTERFACE_H__
#define __INTERFACE_H__
#include <iostream>
#include <string>

#include "queue.hpp"
#include "stack.hpp"
class Interface {
 private:
  Queue<char> input;
  Stack<char> temporal;
  Queue<char> output;

  int toInt(const char&);  // returns a int depending on the given character

 public:
  Interface();

  void
  getString();  // asks the user to enter a string, stores it in input Queue
  void infixToPostfix();  // transforse the input queue and stores it in the
                          // output queue
  void printsOutput();    // prints the output
  void execute();         // runs the whole program
  bool exit();            // returns false
};

#endif  // __INTERFACE_H__