#include "Bureaucrat.hpp"

int c() {
    std::cout << "C here" << std::endl;
    return 3;
}

int b() {
    std::cout << "B here" << std::endl;
    c();
    return 2;
}

int a() {
    std::cout << "A here" << std::endl;
    throw 400;
    b();
    throw 500;
    return 1;
}


int main (void)
{
    Bureaucrat  person1;

    // int x = 5;



    try {
        a();
        
        throw 300;

    }
    catch (int  num) {
        std::cout << "Error:" << num << std::endl;

    }
    Bureaucrat b;



}