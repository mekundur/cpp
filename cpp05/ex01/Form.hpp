#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class Form {
 private:
  const std::string _name;
  bool _signed;
  const int _gradeSign;
  const int _gradeExec;

 public:
  Form();
  Form(const std::string& name, int sign, int exec);
  Form(const Form& other);
  Form& operator=(const Form& other);
  ~Form();

  const std::string& getName() const;
  int getGradeSign() const;
  int getGradeExec() const;
  bool getSigned() const;
  void beSigned(Bureaucrat& person);

  class GradeTooHighException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  class AlreadySigned : public std::exception {
   public:
    virtual const char* what() const throw();
  };
};

std::ostream& operator<<(std::ostream& out, const Form& Form);

#endif