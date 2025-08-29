#include "AForm.hpp"
#include "Bureaucrat.hpp"

void    AForm::execute(Bureaucrat const & executor) const {
    if (this->getSigned() == 0)
        throw NotSignedException();
    else if (executor.getGrade() > this->getGradeExec())
        throw GradeTooLowException();
    else
        std::cout << executor.getName() << " executed " << this->getName() << std::endl;   
}

void    AForm::beSigned(Bureaucrat& person) {
    if (_signed == 1)
        throw AlreadySignedException();
    else if (person.getGrade() > this->getGradeSign())
        throw GradeTooLowException();
    else {
        this->_signed = 1;
        std::cout << person.getName() << " signed " << this->getName() << std::endl;
    }
}

// *** Exceptions methods:
const char* AForm::GradeTooHighException::what() const throw() {
    return ("Grade is too high!\n");
}

const char* AForm::GradeTooLowException::what() const throw() {
    return ("Grade is too low!\n");
}

const char* AForm::AlreadySignedException::what() const throw() {
    return ("The form is already signed!\n");
}

const char* AForm::NotSignedException::what() const throw() {
    return ("Form is not signed!\n");
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
        DEBUG_PRINT("AForm is constructed");
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
        DEBUG_PRINT("AForm is parameterizely constructed");
}

AForm::AForm(const AForm& other) :
    _name(other._name),
    _signed(other._signed),
    _gradeSign(other._gradeSign),
    _gradeExec(other._gradeExec) {
        DEBUG_PRINT("AForm is copy-constructed");
}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other)
        this->_signed = other._signed;
    return (*this);
}

AForm::~AForm() {
    DEBUG_PRINT("AForm is destructed");
}

std::ostream& operator<<(std::ostream& out, const AForm& form) {
    return (out << form.getName() << ", Signing grade: " << form.getGradeSign()
                << ", Executing grade: " << form.getGradeExec() << ", Sign: " << form.getSigned());
}