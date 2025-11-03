#include "ScalarConverter.hpp"

int main (int argc, char **argv) {

    // ScalarConverter con();

    if (argc != 2)
        return (std::cout << "Please pass a single argument!\n", 0);
    
    int         a = 10;
    short       b;
    // ScalarConverter a;
    // a.hello();
    b = a;

    std::cout << a << " / size: " << sizeof(a) << std::endl;
    std::cout << b << " / size: " << sizeof(b) << std::endl;

    ScalarConverter::hello();
    ScalarConverter::convert(argv[1]);
}