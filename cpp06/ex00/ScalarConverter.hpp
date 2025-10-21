#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>

class ScalarConverter
{
    private:
        static int          t;
        ScalarConverter();

    public:
        static void convert(std::string str);
        static void hello() {
            std::cout << t << " Hello\n"; 
        }

};

#endif