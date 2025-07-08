#include "Fixed.hpp"

int main(void)
{
    {
        Fixed       a;
        Fixed const b( 10 );
        Fixed const c( 42.42f );
        Fixed const d( b );
        Fixed const e( 3.14f );

        a = Fixed( 1234.4321f );
        
        std::cout << "a is " << a << std::endl;
        std::cout << "b is " << b << std::endl;
        std::cout << "c is " << c << std::endl;
        std::cout << "d is " << d << std::endl;

        std::cout << "a is " << a.toInt() << " as integer" << std::endl;
        std::cout << "b is " << b.toInt() << " as integer" << std::endl;
        std::cout << "c is " << c.toInt() << " as integer" << std::endl;
        std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    }
    {
        float   a;
        Fixed   const b(10.5f);
        a = b.toFloat();
        std::cout << a << std::endl;
        std::cout << (3.14 * (1 << 8)) << std::endl;
        Fixed   c(11.1f);
    }

    return 0;
}