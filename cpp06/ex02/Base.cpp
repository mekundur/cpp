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
        std::cout << "Base *ptr is pointing to type A" << std::endl;
    }
    else if (rand() % 3 == 1) {
        ptr = new B;   
        std::cout << "Base *ptr is pointing to type B" << std::endl;
    }
    else {
        ptr = new C;
        std::cout << "Base *ptr is pointing to type C" << std::endl;
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
    a = static_cast<A&>(p);
    b = static_cast<B&>(p);
    c = static_cast<C&>(p);
    
    try {
        a = dynamic_cast<A&>(p);
        std::cout << "Type of A" << std::endl;
    }
    catch(...) {
        std::cerr << "Not A" << std::endl;
    }
    
    try {
        b = dynamic_cast<B&>(p);
        std::cout << "Type of B" << std::endl;
    }
    catch(...) {
        std::cerr << "Not B" << std::endl;
    }

    try {
        c = dynamic_cast<C&>(p);
        std::cout << "Type of C" << std::endl;
    }
    catch(...) {
        std::cerr << "Not C" << std::endl;
    }
    
    
    // b = dynamic_cast<B&>(p);
    // std::cout << &b << std::endl;
    
    // c = dynamic_cast<C&>(p);
    // std::cout << &c << std::endl;
    
}