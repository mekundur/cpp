#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char* AForm::GradeTooHighException::what() const throw() {
    return ("Grade is too high!\n");
}

const char* AForm::GradeTooLowException::what() const throw() {
    return ("Grade is too low!\n");
}

const char* AForm::AlreadySigned::what() const throw() {
    return ("It's already signed!\n");
}

void    AForm::beSigned(Bureaucrat& person) {
    if (_signed == 1)
        throw AlreadySigned();
    else if (person.getGrade() > this->getGradeSign())
        throw GradeTooLowException();
    else {
        this->_signed = 1;
        std::cout << person.getName() << " signed " << this->getName() << std::endl;
    }
}

// *** Getter methods:    
const std::string&  AForm::getName() const {
    return _name;
}

int AForm::getGradeSign() const {
    return _gradeSign;
}

int AForm::getGradeExec() const {
    return _gradeExec;
}

bool AForm::getSigned() const {
    return _signed;
}

// *** Constructors + Destructor + Overload of (<<)
// *** Orthodox canonical AForm / rule of three (+one)
AForm::AForm() :
    _name("Default"),
    _signed(0),
    _gradeSign(1),
    _gradeExec(1) {
        if (_gradeSign < 1 || _gradeExec < 1)
            throw   GradeTooHighException();
        else if (_gradeSign > 150 || _gradeExec > 150)
            throw   GradeTooLowException();
        std::cout << "AForm is constructed" << std::endl;
}

AForm::AForm(const std::string& name, int sign, int exec) :
    _name(name),
    _signed(0),
    _gradeSign(sign),
    _gradeExec(exec) {
        if (_gradeSign < 1 || _gradeExec < 1)
            throw   GradeTooHighException();
        else if (_gradeSign > 150 || _gradeExec > 150)
            throw   GradeTooLowException();
        std::cout << "AForm is parameterizely constructed" << std::endl;
}

AForm::AForm(const AForm& other) :
    _name(other._name),
    _signed(other._signed),
    _gradeSign(other._gradeSign),
    _gradeExec(other._gradeExec) {
        std::cout << "AForm is copy-constructed" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other)
        this->_signed = other._signed;
    return (*this);
}

AForm::~AForm() {
    std::cout << "AForm is destructed" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const AForm& AForm) {
    return (out << AForm.getName() << ", Signing grade: " << AForm.getGradeSign()
                << ", Executing grade: " << AForm.getGradeExec() << ", Sign: " << AForm.getSigned());
}