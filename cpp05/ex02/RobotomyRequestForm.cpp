#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    AForm::execute(executor);
    std::cout << "WHIRRRZZZZ........!!!!!!" << std::endl;
    if (rand() % 2)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "Robotomy failed for " << _target << std::endl;
}

// *** Getter methods:    
std::string RobotomyRequestForm::getTarget() const {
    return _target;
}

// *** Constructors + Destructor + Overload of (<<)
// *** Orthodox canonical RobotomyRequestForm / rule of three (+one)
RobotomyRequestForm::RobotomyRequestForm() :
    AForm("default", 72, 45),
    _target("default") {
        DEBUG_PRINT("RobotomyRequestForm is constructed");
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
    AForm("RobotomyRequestForm", 72, 45),
    _target(target) {
        DEBUG_PRINT("RobotomyRequestForm is parameterizely constructed");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
    AForm(other),
    _target(other._target) {
        DEBUG_PRINT("RobotomyRequestForm is copy-constructed");
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != & other) {
        this->_target = other._target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
    DEBUG_PRINT("RobotomyRequestForm is destructed");
}

std::ostream& operator<<(std::ostream& out, const RobotomyRequestForm& form) {
    return (out << form.getName() << ", Signing grade: " << form.getGradeSign()
               << ", Executing grade: " << form.getGradeExec() << ", Sign: " << form.getSigned());
}