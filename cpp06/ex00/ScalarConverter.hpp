#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>

class ScalarConverter
{
    public:
        static void hello(){
            std::cout << "Hello\n"; 
        }
    // private:
        static int t;
        static void convert(std::string str);
        ScalarConverter(/* args */) {
            std::cout << "Constructed\n";
        }
        ~ScalarConverter() {
            std::cout << "Destructed\n";
        }
};



#endif