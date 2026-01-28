#include <unistd.h>
#include <iostream>
#include <string>
#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

int main(void) {

  Base* p;

  for (int i = 0; i < 5; i++) {

    p = generate();
    identify(p);
    std::cout << &p << std::endl;
    std::cout << p << std::endl;
    identify(*p);
    delete p;

    sleep(1);
  }
}