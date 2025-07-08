#include "Fixed.hpp"

int main(void)
{
    {
        Fixed a;
        Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << Fixed::max( a, b ) << std::endl;
    }
        std::cout << std::endl;
    {
        Fixed a(11.1f);
        Fixed b(2);
        Fixed c(a / b);

        if (a >= b)
            std::cout << "TRUE: a >= b" << std::endl; 
        
        std::cout << c << std::endl;
        int x =  c.toInt();
        std::cout << x << std::endl; 

        std::cout << b << std::endl;
        std::cout << "_pre_incr._: " << ++b << std::endl;
        std::cout << "_post_incr._: " << b++ << std::endl;
        b.setRawBits(2 << 8);
        std::cout << b << std::endl;
        std::cout << "_pre_decr._: " << --b << std::endl;
        std::cout << "_post_decr._: " << b-- << std::endl;        
    }
    return 0;
}