#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <string>
#include <unistd.h>

int main(void) {

    Base *p;

    for (int i = 0; i < 10; i++) {
    p = generate();

    identify(p);

    std::cout << &p << std::endl;
    std::cout << p << std::endl;

    identify(*p);
    sleep(1);
    }

    delete p;
}