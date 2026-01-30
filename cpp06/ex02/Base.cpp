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
        std::cout << "Base *ptr is generated and pointing to type A that stored in address: " << ptr << std::endl;
    }
    else if (rand() % 3 == 1) {
        ptr = new B;   
        std::cout << "Base *ptr is generated and pointing to type B that stored in address: " << ptr << std::endl;
    }
    else {
        ptr = new C;
        std::cout << "Base *ptr is generated and pointing to type C that stored in address: " << ptr << std::endl;
    }
    return (ptr);
}

void identify(Base* p) {
    
    if (dynamic_cast<A*>(p)) {
        std::cout << "dynamic_cast from type Base* to type A* and now pointing to: " << p << std::endl;

    } else if (dynamic_cast<B*>(p)) {
        std::cout << "dynamic_cast from type Base* to type B* and now pointing to: " << p << std::endl;

    } else if (dynamic_cast<C*>(p)) {
        std::cout << "dynamic_cast from type Base* to type C* and now pointing to: " << p << std::endl;

    } else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p) {
    
    Base a, b, c;
    try {
        a = dynamic_cast<A&>(p);
        std::cout << &a << " Type of A copied from " << &p << std::endl;
    }
    catch(std::exception &e) {
        std::cerr <<  e.what()  << " (Not A)" << std::endl;
    }
    /////
    try {
        b = dynamic_cast<B&>(p);
        std::cout << &b << " Type of B copied from " << &p << std::endl;
    }
    catch(std::exception &e) {
        std::cerr <<  e.what()  << " (Not B)" << std::endl;
    }
    /////
    try {
        c = dynamic_cast<C&>(p);
        std::cout << &c << " Type of C copied from " << &p << std::endl;
    }
    catch(std::exception &e) {
        std::cerr <<  e.what()  << " (Not C)" << std::endl;
    }
    
    // static_cast converts without any safety
    // and checking wheter the type is compatiable

    // std::cout << &p << std::endl;
    // a = static_cast<A&>(p);
    // std::cout << &a << std::endl;
    // b = static_cast<B&>(p);
    // std::cout << &b << std::endl;
    // c = static_cast<C&>(p);
    // std::cout << &c << std::endl;   
}