#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main (void)
{
    try {
        ShrubberyCreationForm    form;
        std::cout << form << std::endl;
    }
    catch(std::exception &e) {
        std::cout << e.what();
    }
    std::cout << std::endl;

    try {
        ShrubberyCreationForm    form("defaultTarget");
        Bureaucrat  b("Person", 1);

        std::cout << form << std::endl;    
        // AForm.beSigned(b);
        b.signAForm(form);
        std::cout << form << std::endl; 
        b.signAForm(form);
    }
    catch (std::exception& e) {
        std::cout << e.what();
    }
    std::cout << std::endl;
/*    
    try {
        AForm AForm("project", 50, 25);
        Bureaucrat  b("Person", 150);

        std::cout << AForm << std::endl;    
        // AForm.beSigned(b);
        b.signAForm(AForm);
        std::cout << AForm << std::endl;    
    }
    catch (std::exception& e) {
        std::cout << e.what();
    }
    std::cout << std::endl;

*/    return (0);
}