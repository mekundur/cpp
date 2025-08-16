#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
    std::cout << "Bureaucrat is constructed" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
    std::cout << "Bureucrat is parameterizely constructed" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
    std::cout << "Bureucrat is copy-constructed" << std::endl;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat is destructed" << std::endl;
}

void    Bureaucrat::getName() {
    std::cout << _name;
}

void    Bureaucrat::getGrade() {
    std::cout << _grade;
}