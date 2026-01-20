#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) {
  return (*this);
}
ScalarConverter::~ScalarConverter() {}

// int ScalarConverter::t = 5;

// void ScalarConverter::hello() {
//     std::cout << t << " Hello\n";
//     }
bool is_displayable(char c) {
  if (33 <= c && c <= 125)
    return true;
  return false;
}

void ScalarConverter::convert(std::string str) {
  if (str.size() == 3 && is_displayable(str[1]) && str[0] == '\'' &&
      str[2] == '\'')
    std::cout << str << std::endl;
}
