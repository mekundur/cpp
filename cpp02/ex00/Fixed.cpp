#include "Fixed.hpp"

Fixed& Fixed::operator=(const Fixed& other) {
    exponent = other.exponent;
    // mantissa = other.mantissa
    std::cout << "COPY ASSIGNMENT!" << std::endl;

    return (*this); //Required for chaining
}

Fixed::Fixed(const Fixed& other) : exponent(other.exponent) {
    // std::cout << &this->test << " CONSTRUCTED!" << std::endl;
    std::cout << "COPY CONSTRCTUION!" << std::endl;
}

Fixed::Fixed() {
    // std::cout << &this->test << " CONSTRUCTED!" << std::endl;
    std::cout << "DEFAULT CONSTRCTUION!" << std::endl;

    exponent = 0;
}

Fixed::~Fixed() {
    std::cout << "DECONSTRCTUION!" << std::endl;
}
