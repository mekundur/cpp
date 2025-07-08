#include "Fixed.hpp"

// min max functions
Fixed&  Fixed::max(Fixed& x, Fixed &y) {
    if (x > y)
        return (x);
    else
        return (y);
}

const Fixed&  Fixed::max(const Fixed& x, const Fixed &y) {
    if (x > y)
        return (x);
    else
        return (y);
}

Fixed&  Fixed::min(Fixed& x, Fixed &y) {
    if (x < y)
        return (x);
    else
        return (y);
}

const Fixed&  Fixed::min(const Fixed& x, const Fixed &y) {
    if (x < y)
        return (x);
    else
        return (y);
}

 // increment/decrement operators overloading
Fixed&  Fixed::operator++() {
    this->_number++;
    return (*this);
}

Fixed   Fixed::operator++(int) {
    Fixed tmp = *this;
    this->_number++;
    return tmp;
}

Fixed&  Fixed::operator--() {
    this->_number--;
    return (*this);
}

Fixed   Fixed::operator--(int) {
    Fixed tmp = *this;
    this->_number--;
    return tmp;
}

// arithmetic opearators overloading
Fixed   Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed   Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed   Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed   Fixed::operator/(const Fixed& other) const {
    return  Fixed(this->toFloat() / other.toFloat());
}

// comparasion operators overlading
bool    Fixed::operator>(const Fixed& other) const {
        return (this->_number > other._number);
}

bool    Fixed::operator<(const Fixed& other) const {
        return (this->_number < other._number);
}

bool    Fixed::operator>=(const Fixed& other) const {
        return (this->_number >= other._number);
}

bool    Fixed::operator<=(const Fixed& other) const {
        return (this->_number <= other._number);
}

bool    Fixed::operator==(const Fixed& other) const {
        return (this->_number == other._number);
}

bool    Fixed::operator!=(const Fixed& other) const {
        return (this->_number != other._number);
}

// getter and setter functions
int     Fixed::getRawBits( void ) const {
    // std::cout << "getRawBits member function called" << std::endl;
    return (_number);
}

void    Fixed::setRawBits( int const raw ) {
    _number = raw;
    // std::cout << "Number is set to value: " << raw << std::endl;
}

// convertors from fixed point number to int and float
float   Fixed::toFloat(void) const {
    return ((float)_number / (1 << _mantissa));
}

int     Fixed::toInt(void) const {
    return (_number >> _mantissa);
}

// int and float constructors
Fixed::Fixed(const int value) {
    _number = value << _mantissa;
    // std::cout << "Int constructor called and " << value << " stored as > " << _number << std::endl;
}

Fixed::Fixed(const float value) {
    _number = roundf(value * (1 << _mantissa));
    // std::cout << "Float constructor called and " << value << " stored as > " << _number << std::endl;
}

// standart constructors (Orthodox Caninocal / Rule of Three)
Fixed::Fixed() : _number(0) {
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _number(other._number) {       
    // std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != & other) {
        _number = other._number;
        // std::cout << "Copy assignment operator called" << std::endl;
    }
    return (*this);
}

Fixed::~Fixed() {
    // std::cout << "Destructor called" << std::endl;
}

// overloading Fixed for std::cout
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    return (out << fixed.toFloat());
}
