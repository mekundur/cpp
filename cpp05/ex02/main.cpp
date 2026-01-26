#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {

  std::srand(time(NULL));  //use current time as seed for random generator
  // AForm aform;
  try {
    Bureaucrat b("Mertcan", 5);
    std::cout << b << std::endl;
    ShrubberyCreationForm formS("FormS");
    RobotomyRequestForm formR("FormR");
    PresidentialPardonForm formP("FormP");
    std::cout << formS << std::endl;
    std::cout << formR << std::endl;
    std::cout << formP << std::endl;
    b.signAForm(formS);
    b.signAForm(formR);
    b.signAForm(formP);
    std::cout << formS << std::endl;
    std::cout << formR << std::endl;
    std::cout << formP << std::endl;
    b.executeForm(formS);
    b.executeForm(formR);
    b.executeForm(formP);
  } catch (std::exception& e) {
    std::cout << e.what();
  }
  return (0);
}