#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <stdlib.h>
#include <iostream>

Base::~Base() {}

Base * generate(void) {
    Base *ptr;

    std::srand(time(NULL));  //use current time as seed for random generator
    if (rand() % 3 == 2) {
        ptr = new A;
        std::cout << "Base *ptr is pointing to A" << std::endl;
    }
    else if (rand() % 3 == 1) {
        ptr = new B;   
        std::cout << "Base *ptr is pointing to B" << std::endl;
    }
    else {
        ptr = new C;
        std::cout << "Base *ptr is pointing to C" << std::endl;
    }
    return (ptr);
}

void identify(Base* p) {
    
    if (dynamic_cast<A*>(p))
        std::cout << "dynamic_cast to type A*" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "dynamic_cast to type B*" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "dynamic_cast to type C*" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p) {
    Base a, b, c;

    std::cout << &p << std::endl;
    
    a = dynamic_cast<A&>(p);
    std::cout << &a << std::endl;
    
    b = dynamic_cast<B&>(p);
    std::cout << &b << std::endl;
    
    c = dynamic_cast<C&>(p);
    std::cout << &c << std::endl;
    
}