#include <unistd.h>
#include <iostream>
#include <string>
#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

int main(void) {

  Base* ptr;

  ptr = generate();
  std::cout << std::endl;
  identify(ptr);
  std::cout << std::endl;
  std::cout << "ptr is holding the address: " << ptr << std::endl;
  std::cout << std::endl;
  identify(*ptr);

  delete ptr;

}