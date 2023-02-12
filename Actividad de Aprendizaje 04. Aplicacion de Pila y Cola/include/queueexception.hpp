// queueexception.hpp
#ifndef __QUEUEEXCEPTION_H__
#define __QUEUEEXCEPTION_H__

#include <exception>
#include <string>

class QueueException : public std::exception {
 private:
  std::string msg;

 public:
  explicit QueueException(const char* message) : msg(message) {}
  explicit QueueException(const std::string& message) : msg(message) {}
  virtual ~QueueException() throw() {}
  virtual const char* what() const throw() { return msg.c_str(); }
};

#endif  // __QUEUEEXCEPTION_H__