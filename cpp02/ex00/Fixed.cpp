#include "Fixed.hpp"

int     Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (exponent);
}

void    Fixed::setRawBits( int const raw ) {
    exponent = raw;
}

// COPY ASSIGNEMNT (with OPERATOR OVERLOADING)
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != & other) {
        exponent = other.exponent;
        // mantissa = other.mantissa
        std::cout << "COPY ASSIGNMENT!" << std::endl;
    }
    return (*this);
}

// COPY CONSTRUCTOR
Fixed::Fixed(const Fixed& other) : exponent(other.exponent) {       
    // std::cout << &this->test << " CONSTRUCTED!" << std::endl;
    std::cout << "COPY CONSTRCTUION!" << std::endl;
}

// DEFAULT CONSTRUCTOR
Fixed::Fixed() {
    // std::cout << &this->test << " CONSTRUCTED!" << std::endl;
    std::cout << "DEFAULT CONSTRCTUION!" << std::endl;

    exponent = 0;
}

// DESTRUCTOR
Fixed::~Fixed() { // DESTRUCTOR
    std::cout << "DESTRUCTION!" << std::endl;
}
