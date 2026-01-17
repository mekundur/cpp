#include "Bureaucrat.hpp"

int main (void)
{
    try {
        Bureaucrat  b("PERSON1", 0); // Bureaucrat with too high grade!
        std::cout << b << std::endl;
        std::cout << b << "CHECKPOINT\n" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        Bureaucrat  b("PERSON2", 151); // Bureaucrat with too low grade!
        std::cout << b << std::endl;
        std::cout << b << "CHECKPOINT\n" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        Bureaucrat  b("PERSON3", 5);
        std::cout << b << std::endl;
        while (b.getGrade() >= 0) {
            b.gradeIncrement();
            std::cout << b << std::endl;
        }
        std::cout << b << "CHECKPOINT\n" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        Bureaucrat  b("PERSON4", 145);
        std::cout << b << std::endl;
        while (b.getGrade() <= 150) {
           b.gradeDecrement();
            std::cout << b << std::endl
        }
        std::cout << b << "CHECKPOINT\n" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return (0);
}