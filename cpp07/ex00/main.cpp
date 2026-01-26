#include "whatever.hpp"
#include <iostream>
#include <string>

int main(void) {
  {
    int i = 5;
    int j = 2;
    std::cout << i << std::endl;
    std::cout << j << std::endl;
    swap(i, j);
    std::cout << i << std::endl;
    std::cout << j << std::endl;
  }
  {
    float i = 3.14;
    float j = 2.72;
    std::cout << i << std::endl;
    std::cout << j << std::endl;
    swap(i, j);
    std::cout << i << std::endl;
    std::cout << j << std::endl;
  }
  {
    std::string i = "Berlin";
    std::string j = "42";
    std::cout << i << std::endl;
    std::cout << j << std::endl;
    swap(i, j);
    std::cout << i << std::endl;
    std::cout << j << std::endl;
  }
  {
    int a = 2;
    int b = 3;
    swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
  }
}