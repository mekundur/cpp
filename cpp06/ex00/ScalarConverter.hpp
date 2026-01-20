#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

// char literals: ’c’, ’a’, ...
// int literals: 0, -42, 42...
// float literals: 0.0f,-4.2f, 4.2f...
// pseudo-literals -inff, +inff, nanf...
// double literals: 0.0,-4.2, 4.2...
// pseudo-literals -inf, +inf, nan...

class ScalarConverter {
 private:
  // static int t;
  ScalarConverter();
  ScalarConverter(const ScalarConverter&);
  ScalarConverter& operator=(const ScalarConverter&);
  ~ScalarConverter();

 public:
  static void convert(std::string str);
  // static void hello();
};

#endif