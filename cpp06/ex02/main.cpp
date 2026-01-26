#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <string>

int main(void) {

    Base *p;

    p = generate();

    identify(p);

    std::cout << &p << std::endl;
    std::cout << p << std::endl;

    identify(*p);

    delete p;
}