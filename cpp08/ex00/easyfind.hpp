#pragma once

#include <exception>
#include <iostream>
#include <sstream>
#include <string>

std::string itos(int value) {
  std::ostringstream oss;
  oss << value;
  return oss.str();
}

class NotFoundException : public std::exception {

 private:
  std::string _msg;

 public:
  NotFoundException(int n) : _msg("Not found: " + itos(n)) {}
  virtual ~NotFoundException() throw(){};

  virtual const char* what() const throw() { return (_msg.c_str()); }
};

template <typename T>

typename T::const_iterator easyfind(const T& container, int n) {

  typename T::const_iterator it = container.begin();
  for (; it != container.end(); it++) {
    if (*it == n)
      break;
  }
  if (it == container.end())
    throw NotFoundException(n);
  return (it);
}
