#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low!");
}

void Bureaucrat::gradeIncrement()
{
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::gradeDecrement()
{
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}

const std::string &Bureaucrat::getName() const
{
    // std::cout << "Name: " << _name << std::endl;
    return _name;
}

int Bureaucrat::getGrade() const
{
    // std::cout << "Grade: " << _grade << std::endl;
    return _grade;
}

// orthodox canonical form / rule of three (+one)
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
    if (_grade < 1)
        throw GradeTooHighException();
    else if (_grade > 150)
        throw GradeTooLowException();
    std::cout << "Bureaucrat is constructed" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
    if (_grade < 1)
        throw GradeTooHighException();
    else if (_grade > 150)
        throw GradeTooLowException();
    std::cout << "Bureucrat is parameterizely constructed" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
    std::cout << "Bureucrat is copy-constructed" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        // this->_name = other._name;
        this->_grade = other._grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat is destructed" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    return (out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade());
}