#include <iostream>
#include "Bureaucrat.hpp"

int main(void) {

  // TEST1 Bureaucrat with too high grade!
  try {
    Bureaucrat b("PERSON1", 0);
    std::cout << b << std::endl;
    std::cout << b << "CHECKPOINT\n" << std::endl;
  } catch (std::exception& e) {
    std::cout << "Error: " << e.what() << std::endl;
  }
  std::cout << std::endl;

  // TEST2 Bureaucrat with too low grade!
  try {
    Bureaucrat b("PERSON2", 151);
    std::cout << b << std::endl;
    std::cout << b << "CHECKPOINT\n" << std::endl;
  } catch (std::exception& e) {
    std::cout << "Error: " << e.what() << std::endl;
  }
  std::cout << std::endl;

  // TEST3 _grade incrementing test!
  try {
    Bureaucrat b("PERSON3", 5);
    std::cout << b << std::endl;
    while (1) {
      b.gradeIncrement();
      std::cout << b << std::endl;
    }
    std::cout << b << "CHECKPOINT\n" << std::endl;
  } catch (std::exception& e) {
    std::cout << "Error: " << e.what() << std::endl;
  }
  std::cout << std::endl;

  // TEST3 _grade decrementing test!
  try {
    Bureaucrat b("PERSON4", 145);
    std::cout << b << std::endl;
    while (1) {
      b.gradeDecrement();
      std::cout << b << std::endl;
    }
    std::cout << b << "CHECKPOINT\n" << std::endl;
  } catch (std::exception& e) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  return (0);
}