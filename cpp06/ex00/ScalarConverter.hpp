#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <limits.h>
#include <cfloat>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <typeinfo>

// char literals: ’c’, ’a’, ...
// int literals: 0, -42, 42...
// float literals: 0.0f,-4.2f, 4.2f...
// pseudo-f-literals -inff, +inff, nanf...
// double literals: 0.0,-4.2, 4.2...
// pseudo-d-literals -inf, +inf, nan...

class ScalarConverter {
 private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter&);
  ScalarConverter& operator=(const ScalarConverter&);
  ~ScalarConverter();

 public:
  static void convert(std::string str);
};

class ConversionFailException : public std::exception {
 public:
  virtual const char* what() const throw();
};

class OutoftheBoundsException : public std::exception {
 public:
  virtual const char* what() const throw();
};

template <typename T>
T strToType(const std::string& str) {

  std::stringstream ss(str);
  long double n;

  ss >> n;

  if (ss.fail() || !ss.eof())
    throw(ConversionFailException());

  if (std::numeric_limits<T>::is_integer) {
    if (n < std::numeric_limits<T>::min() || n > std::numeric_limits<T>::max())
      throw(OutoftheBoundsException());
  } else {
    if (n < -std::numeric_limits<T>::max() || n > std::numeric_limits<T>::max())
      throw(OutoftheBoundsException());
  }

  return static_cast<T>(n);
}

#endif