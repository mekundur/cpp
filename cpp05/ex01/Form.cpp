#include "Form.hpp"
#include "Bureaucrat.hpp"

// Orthodox canonical form / rule of three (+one)
Form::Form() : _name("Default"), _signed(0), _gradeSign(1), _gradeExec(1) {
  if (_gradeSign < 1 || _gradeExec < 1)
    throw GradeTooHighException();
  else if (_gradeSign > 150 || _gradeExec > 150)
    throw GradeTooLowException();
  std::cout << "Form is constructed" << std::endl;
}

Form::Form(const std::string& name, int sign, int exec)
    : _name(name), _signed(0), _gradeSign(sign), _gradeExec(exec) {
  if (_gradeSign < 1 || _gradeExec < 1)
    throw GradeTooHighException();
  else if (_gradeSign > 150 || _gradeExec > 150)
    throw GradeTooLowException();
  DEBUG_PRINT("Form is parameterizely constructed");
}

Form::Form(const Form& other)
    : _name(other._name),
      _signed(other._signed),
      _gradeSign(other._gradeSign),
      _gradeExec(other._gradeExec) {
  DEBUG_PRINT("Form is copy-constructed");
}

Form& Form::operator=(const Form& other) {
  if (this != &other) {
    // this->_name = other._name;
    // this->_gradeSign = other._gradeSign;
    // this->_gradeSign = other._gradeExec;
    this->_signed = other._signed;
  }
  return (*this);
}

Form::~Form() {
  DEBUG_PRINT("Form is destructed");
}

// Getters
const std::string& Form::getName() const {
  return _name;
}

int Form::getGradeSign() const {
  // std::cout << "Grade: " << _grade << std::endl;
  return _gradeSign;
}

int Form::getGradeExec() const {
  // std::cout << "Grade: " << _grade << std::endl;
  return _gradeExec;
}

bool Form::getSigned() const {
  // std::cout << "Grade: " << _grade << std::endl;
  return _signed;
}

// Helpers
void Form::beSigned(Bureaucrat& person) {
  if (_signed == 1)
    throw AlreadySigned();
  else if (person.getGrade() > this->getGradeSign())
    throw GradeTooLowException();
  else {
    this->_signed = 1;
    std::cout << person.getName() << " signed " << this->getName() << std::endl;
  }
}

// Exceptions
const char* Form::GradeTooHighException::what() const throw() {
  return ("Grade is too high!\n");
}

const char* Form::GradeTooLowException::what() const throw() {
  return ("Grade is too low!\n");
}

const char* Form::AlreadySigned::what() const throw() {
  return ("It's already signed!\n");
}

// Overloading the insertion '<<' operator
std::ostream& operator<<(std::ostream& out, const Form& Form) {
  return (out << Form.getName() << ", Signing grade: " << Form.getGradeSign()
              << ", Executing grade: " << Form.getGradeExec()
              << ", Sign: " << Form.getSigned());
}