#include "Bureaucrat.hpp"
#include <iostream>

// Orthodox canonical form / rule of three (+one)
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
  if (_grade < 1)
    throw GradeTooHighException();
  else if (_grade > 150)
    throw GradeTooLowException();
  DEBUG_PRINT("Bureaucrat is default constructed");
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
    : _name(name), _grade(grade) {
  if (_grade < 1)
    throw GradeTooHighException();
  else if (_grade > 150)
    throw GradeTooLowException();
  DEBUG_PRINT("Bureucrat is constructed\n");
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : _name(other._name), _grade(other._grade) {
  DEBUG_PRINT("Bureaucrat is copy-constructed\n");
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  if (this != &other) {
    // this->_name = other._name;
    this->_grade = other._grade;
  }
  return (*this);
}

Bureaucrat::~Bureaucrat() {
  DEBUG_PRINT("Bureaucrat is destructed" << std::endl);
}

// Getters
const std::string& Bureaucrat::getName() const {
  return _name;
}

int Bureaucrat::getGrade() const {
  return _grade;
}

// Helpers
void Bureaucrat::gradeIncrement() {
  if (_grade <= 1)
    throw GradeTooHighException();
  _grade--;
}

void Bureaucrat::gradeDecrement() {
  if (_grade >= 150)
    throw GradeTooLowException();
  _grade++;
}

// Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Grade is too low!");
}

// Overloading the insertion '<<' operator
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
  return (out << bureaucrat.getName() << ", bureaucrat grade "
              << bureaucrat.getGrade());
}
