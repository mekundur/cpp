#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 private:
  std::string _target;

 public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(const std::string& target);
  ShrubberyCreationForm(const ShrubberyCreationForm& other);
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
  ~ShrubberyCreationForm();

  const std::string& getTarget() const;
  virtual void execute(Bureaucrat const& executor) const;
};

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& form);

#endif