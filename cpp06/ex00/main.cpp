#include <limits.h>
#include <cfloat>
#include <iostream>
#include <typeinfo>
#include "ScalarConverter.hpp"

int main(int argc, char** argv) {

  // ScalarConverter con;
  // std::cout << "Int min: " << INT_MIN << std::endl;
  // std::cout << "Int max: " << INT_MAX << std::endl;
  // std::cout << "Float min: " << FLT_MIN << std::endl;
  // std::cout << "Float max: " << FLT_MAX << std::endl;
  // std::cout << "Double min: " << DBL_MIN << std::endl;
  // std::cout << "Double max: " << DBL_MAX << std::endl;

  if (argc != 2)
    return (std::cout << "Please pass a literal value!\n", 0);

  // int         a = 10;
  // short       b;
  // ScalarConverter a;
  // a.hello();
  // b = a;

  // std::cout << a << " / size: " << sizeof(a) << std::endl;
  // std::cout << b << " / size: " << sizeof(b) << std::endl;

  // ScalarConverter::hello();
  // int i = 5;
  // double d = 44.55;
  // float f = 3.14;
  // std::string str = "Mertcan";

  // std::cout << typeid(i).name() << std::endl;
  // std::cout << typeid(d).name() << std::endl;
  // std::cout << typeid(f).name() << std::endl;
  // std::cout << typeid(argv[1]).name() << std::endl;
  ScalarConverter::convert(argv[1]);
}