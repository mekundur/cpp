#include "Bureaucrat.hpp"

int main (void)
{
    // Bureaucrat  a;
    // Bureaucrat  b("Mertcan", 5);

    int x = 300;
    int y = 500;

    try {
        Bureaucrat  a;
        Bureaucrat  b("Mertcan", 5);
        
        if (b.getGrade() < 1)
            throw y;
        else if (b.getGrade() > 150)
            throw x;

        std::cout << "CHECKPOINT\n" << std::endl;
    }
    catch (int  num) {
        std::cout << "Error:" << num << std::endl;

    }
    // a.getName();
    // a.getGrade();
    // b.getName();
    // b.getGrade();


}