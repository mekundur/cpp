#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

# ifdef DEBUG
#   define DEBUG_PRINT(x) do { std::cerr << x << std::endl; } while(0)
# else
#   define DEBUG_PRINT(x) do {} while(0)
# endif

class Bureaucrat
{
private:
    const std::string   _name;
    int                 _grade;

public:
    const std::string   &getName() const;
    int                 getGrade() const;
    void                gradeIncrement();
    void                gradeDecrement();

    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &Bureaucrat);

#endif