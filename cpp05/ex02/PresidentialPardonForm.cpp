#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    AForm::execute(executor);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

// *** Getter methods:    
std::string PresidentialPardonForm::getTarget() const {
    return _target;
}

// *** Constructors + Destructor + Overload of (<<)
// *** Orthodox canonical PresidentialPardonForm / rule of three (+one)
PresidentialPardonForm::PresidentialPardonForm() :
    AForm("default", 25, 5),
    _target("default") {
        DEBUG_PRINT("PresidentialPardonForm is constructed");
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
    AForm("PresidentialPardonForm", 25, 5),
    _target(target) {
        DEBUG_PRINT("PresidentialPardonForm is parameterizely constructed");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
    AForm(other),
    _target(other._target) {
        DEBUG_PRINT("PresidentialPardonForm is copy-constructed");
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != & other) {
        this->_target = other._target;
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
    DEBUG_PRINT("PresidentialPardonForm is destructed");
}

std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& form) {
    return (out << form.getName() << ", Signing grade: " << form.getGradeSign()
               << ", Executing grade: " << form.getGradeExec() << ", Sign: " << form.getSigned());
}