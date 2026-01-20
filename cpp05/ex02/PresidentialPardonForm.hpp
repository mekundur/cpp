#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

#include <stdlib.h>
#include <exception>
#include <iostream>
#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 private:
  std::string _target;

 public:
  virtual void execute(Bureaucrat const& executor) const;
  std::string getTarget() const;

  PresidentialPardonForm();
  PresidentialPardonForm(const std::string& target);
  PresidentialPardonForm(const PresidentialPardonForm& other);
  PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
  ~PresidentialPardonForm();
};

std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& form);

#endif