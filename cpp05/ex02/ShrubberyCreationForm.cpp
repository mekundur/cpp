#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

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
        this->_target = other._target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm is destructed" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& form) {
    return (out << form.getName() << ", Signing grade: " << form.getGradeSign()
                << ", Executing grade: " << form.getGradeExec() << ", Sign: " << form.getSigned());
}