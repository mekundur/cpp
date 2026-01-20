#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>

class AForm;  // forward declaration

class Bureaucrat {
 private:
  const std::string _name;
  int _grade;

 public:
  Bureaucrat();
  Bureaucrat(const std::string name, int grade);
  Bureaucrat(const Bureaucrat& other);
  Bureaucrat& operator=(const Bureaucrat& other);
  ~Bureaucrat();

  const std::string& getName() const;
  int getGrade() const;
  void gradeIncrement();
  void gradeDecrement();
  void signAForm(AForm& AForm);
  void executeForm(AForm const& form) const;

  class GradeTooHighException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& Bureaucrat);

#pragma once
#ifdef DEBUG
#define DEBUG_PRINT(x)           \
  do {                           \
    std::cerr << x << std::endl; \
  } while (0)
#else
#define DEBUG_PRINT(x) \
  do {                 \
  } while (0)
#endif

#endif