#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class   Fixed
{
    private:
        int                 _number;
        static const int    _mantissa = 8;

    public:
        // min max functions
        static Fixed&  max(Fixed& x, Fixed &y);
        static const Fixed&  max(const Fixed& x, const Fixed &y);
        static Fixed&  min(Fixed& x, Fixed &y);
        static const Fixed&  min(const Fixed& x, const Fixed &y);
    

        // increment/decrement operators
        Fixed&  operator++();
        Fixed   operator++(int);
        Fixed&  operator--();
        Fixed   operator--(int);

        // arithmetic opearators
        Fixed   operator+(const Fixed& other) const;
        Fixed   operator-(const Fixed& other) const;
        Fixed   operator*(const Fixed& other) const;
        Fixed   operator/(const Fixed& other) const;

        // comparasion opearators
        bool    operator>(const Fixed& other) const;
        bool    operator<(const Fixed& other) const;
        bool    operator>=(const Fixed& other) const;
        bool    operator<=(const Fixed& other) const;
        bool    operator==(const Fixed& other) const;
        bool    operator!=(const Fixed& other) const;

        // getters and setters
        int     getRawBits(void) const;
        void    setRawBits(int const raw);

        // int and float constructors and convertors
        float   toFloat(void) const;
        int     toInt(void) const;
        Fixed(const int value);
        Fixed(const float value);

        // standart constructors
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif