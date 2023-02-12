// stackexception.hpp
#ifndef __STACKEXCEPTION_H__
#define __STACKEXCEPTION_H__
#include <exception>
#include <string>
class StackException : public std::exception {
 private:
  std::string msg;

 public:
  explicit StackException(const char* message) : msg(message) {}
  explicit StackException(const std::string& message) : msg(message) {}
  virtual ~StackException() throw() {}
  virtual const char* what() const throw() { return msg.c_str(); }
};
#endif  // __STACKEXCEPTION_H__