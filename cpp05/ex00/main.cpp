#include "Bureaucrat.hpp"

int main (void)
{
    Bureaucrat  a;
    Bureaucrat  b("Mertcan", 5);

    int x = 5;

    try {
        throw x;

    }
    catch (int  num) {
        std::cout << "Error:" << num << std::endl;

    }
    // Bureaucrat b;



}