#include "Bureaucrat.hpp"

int main (void)
{
    try {
        Bureaucrat  b("Person1", 0);
        std::cout << b << std::endl;
        while (b.getGrade() >= 0)
            b.gradeIncrement();
          std::cout << b << "CHECKPOINT\n" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        Bureaucrat  b("Person2", 151);
        std::cout << b << std::endl;
        while (b.getGrade() >= 0)
            b.gradeIncrement();
          std::cout << b << "CHECKPOINT\n" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        Bureaucrat  b("Person3", 1);
        std::cout << b << std::endl;
        while (b.getGrade() >= 0)
            b.gradeIncrement();
          std::cout << b << "CHECKPOINT\n" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        Bureaucrat  b("Person4", 145);
        std::cout << b << std::endl;
        while (b.getGrade() <= 150)
            b.gradeDecrement();
        std::cout << b << "CHECKPOINT\n" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return (0);
}