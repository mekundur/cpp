#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
  try {
    Form form("Form", 10, 0);
  } catch (std::exception& e) {
    std::cout << e.what();
  }
  std::cout << std::endl;

  try {
    Form form("Application Form", 50, 25);
    Bureaucrat b("Gollum", 1);

    std::cout << form << std::endl;
    // form.beSigned(b);
    b.signForm(form);
    std::cout << form << std::endl;
    b.signForm(form);
  } catch (std::exception& e) {
    std::cout << e.what();
  }
  std::cout << std::endl;

  try {
    Form form("Project Form", 50, 25);
    Bureaucrat b("Frodo", 100);

    std::cout << form << std::endl;
    // form.beSigned(b);
    b.signForm(form);
    std::cout << form << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what();
  }
  std::cout << std::endl;

  return (0);
}