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
        int     getRawBits(void) const;
        void    setRawBits(int const raw);

        float   toFloat(void) const;
        int     toInt(void) const;
        Fixed(const int value);
        Fixed(const float value);

        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();


};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif