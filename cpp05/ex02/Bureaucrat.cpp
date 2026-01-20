#include "Bureaucrat.hpp"
#include <iostream>
#include "AForm.hpp"

void Bureaucrat::executeForm(AForm const& form) const {
  try {
    form.execute(*this);
  } catch (std::exception& e) {
    std::cout << this->_name << " couldn't execute " << form.getName()
              << " because " << e.what();
  }
}

void Bureaucrat::signAForm(AForm& AForm) {
  try {
    AForm.beSigned(*this);
  } catch (std::exception& e) {
    std::cout << this->_name << " couldn't sign " << AForm.getName()
              << " because " << e.what();
  }
}

// *** Getter methods:
const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Grade is too high!\n");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Grade is too low!\n");
}

// *** Grade manipulating methods:
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

// *** Getter methods:
const std::string& Bureaucrat::getName() const {
  // std::cout << "Name: " << _name << std::endl;
  return _name;
}

int Bureaucrat::getGrade() const {
  // std::cout << "Grade: " << _grade << std::endl;
  return _grade;
}

// *** Constructors + Destructor + Overload of (<<)
// *** Orthodox canonical AForm / rule of three (+one)
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
  if (_grade < 1)
    throw GradeTooHighException();
  else if (_grade > 150)
    throw GradeTooLowException();
  else
    DEBUG_PRINT("Bureaucrat constructed");
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : _name(name), _grade(grade) {
  if (_grade < 1)
    throw GradeTooHighException();
  else if (_grade > 150)
    throw GradeTooLowException();
  else
    DEBUG_PRINT("Bureucrat is parameterizely constructed");
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : _name(other._name), _grade(other._grade) {
  DEBUG_PRINT("Bureucrat is copy-constructed");
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  if (this != &other) {
    // this->_name = other._name;
    this->_grade = other._grade;
  }
  return (*this);
}

Bureaucrat::~Bureaucrat() {
  DEBUG_PRINT("Bureaucrat is destructed");
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
  return (out << bureaucrat.getName() << ", bureaucrat grade "
              << bureaucrat.getGrade());
}