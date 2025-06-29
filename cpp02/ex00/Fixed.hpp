#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class   Fixed
{
    private:
    int                 exponent;
    static const int    mantissa = 8;

    public:
    int     getRawBits( void ) const;
    void    setRawBits( int const raw );
    Fixed();
    ~Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);

};


#endif