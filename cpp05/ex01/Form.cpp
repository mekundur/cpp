#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw() {
    return ("Grade is too high!\n");
}

const char* Form::GradeTooLowException::what() const throw() {
    return ("Grade is too low!\n");
}
      
std::string    Form::getName() const {
    // std::cout << "Name: " << _name << std::endl;
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

// orthodox canonical form / rule of three (+one)
Form::Form() :
    _name("Default"),
    _signed(0),
    _gradeSign(1),
    _gradeExec(1) {
        if (_gradeSign < 1 || _gradeExec < 1)
            throw   GradeTooHighException();
        else if (_gradeSign > 150 || _gradeExec > 150)
            throw   GradeTooLowException();
        std::cout << "Form is constructed" << std::endl;
}

Form::Form(const std::string& name, int grade) :
    _name("Default"),
    _signed(0),
    _gradeSign(1),
    _gradeExec(1) {
        if (_gradeSign < 1 || _gradeExec < 1)
            throw   GradeTooHighException();
        else if (_gradeSign > 150 || _gradeExec > 150)
            throw   GradeTooLowException();
        std::cout << "Bureucrat is parameterizely constructed" << std::endl;
}

Form::Form(const Form& other) :
    _name(other._name),
    _signed(other._signed),
    _gradeSign(other._gradeSign),
    _gradeExec(other._gradeExec) {
        std::cout << "Bureucrat is copy-constructed" << std::endl;
}

Form& Form::operator=(const Form& other) {
    if (this != & other) {
        // this->_name = other._name;
        // this->_gradeSign = other._gradeSign;
        // this->_gradeSign = other._gradeExec;
        this->_signed = other._signed;
    }
    return (*this);
}

Form::~Form() {
    std::cout << "Form is destructed" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Form& Form) {
    return (out << Form.getName() << ", Form signing grade: " << Form.getGradeSign()
                << "Form exectuing grade:" << Form.getGradeExec());
}