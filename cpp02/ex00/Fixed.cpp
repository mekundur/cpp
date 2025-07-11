#include "Fixed.hpp"

int     Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (_number);
}

void    Fixed::setRawBits( int const raw ) {
    _number = raw;
    std::cout << "Number is set to value: " << raw << std::endl;
}

Fixed::Fixed() : _number(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _number(other._number) {       
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != & other) {
        _number = other._number;
        std::cout << "Copy assignment operator called" << std::endl;
    }
    return (*this);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}
