#include "Fixed.hpp"

int main(void)
{
    Fixed   a;
    Fixed   b(a);
    Fixed   c;

    c = b;

    // std::cout << &a.test << std::endl;
    // std::cout << &b.test << std::endl;


    return 0;
}