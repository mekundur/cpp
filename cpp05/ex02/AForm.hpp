#ifndef AForm_HPP
#define AForm_HPP

#include <stdint.h>
#include <exception>
#include <fstream>
#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
 private:
  const std::string _name;
  bool _signed;
  const int _gradeSign;
  const int _gradeExec;

 public:
  AForm();
  AForm(const std::string& name, int sign, int exec);
  AForm(const AForm& other);
  AForm& operator=(const AForm& other);
  ~AForm();

  const std::string& getName() const;
  int getGradeSign() const;
  int getGradeExec() const;
  bool getSigned() const;
  void beSigned(Bureaucrat& person);
  virtual void execute(Bureaucrat const& executor) const = 0;

  class GradeTooHighException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  class AlreadySignedException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  class NotSignedException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif