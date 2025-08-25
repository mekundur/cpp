#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

// const char* ShrubberyCreationForm::GradeTooHighException::what() const throw() {
//     return ("Grade is too high!\n");
// }

// const char* ShrubberyCreationForm::GradeTooLowException::what() const throw() {
//     return ("Grade is too low!\n");
// }

// const char* ShrubberyCreationForm::AlreadySigned::what() const throw() {
//     return ("It's already signed!\n");
// }

// void    ShrubberyCreationForm::beSigned(Bureaucrat& person) {
//     if (_signed == 1)
//         throw AlreadySigned();
//     else if (person.getGrade() > this->getGradeSign())
//         throw GradeTooLowException();
//     else {
//         this->_signed = 1;
//         std::cout << person.getName() << " signed " << this->getName() << std::endl;
//     }
// }

// // *** Getter methods:    
// const std::string&  ShrubberyCreationForm::getName() const {
//     // std::cout << "Name: " << _name << std::endl;
//     return _name;
// }

// int ShrubberyCreationForm::getGradeSign() const {
//     // std::cout << "Grade: " << _grade << std::endl;
//     return _gradeSign;
// }

// int ShrubberyCreationForm::getGradeExec() const {
//     // std::cout << "Grade: " << _grade << std::endl;
//     return _gradeExec;
// }

// bool ShrubberyCreationForm::getSigned() const {
//     // std::cout << "Grade: " << _grade << std::endl;
//     return _signed;
// }

// *** Constructors + Destructor + Overload of (<<)
// *** Orthodox canonical ShrubberyCreationForm / rule of three (+one)
ShrubberyCreationForm::ShrubberyCreationForm() : 
    AForm("ShrubberyCreationForm", 145, 137),
    _target("default") {
        std::cout << "ShrubberyCreationForm is constructed" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
    AForm("ShrubberyCreationForm", 145, 137),
    _target(target) {
        std::cout << "ShrubberyCreationForm is parameterizely constructed" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
    AForm(other), _target(other._target) {
        std::cout << "ShrubberyCreationForm is copy-constructed" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != & other){
        _target = other._target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm is destructed" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& ShrubberyCreationForm) {
    return (out << ShrubberyCreationForm.getName() << ", Signing grade: " << ShrubberyCreationForm.getGradeSign()
                << ", Executing grade: " << ShrubberyCreationForm.getGradeExec() << ", Sign: " << ShrubberyCreationForm.getSigned());
}