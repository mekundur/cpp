#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
  AForm::execute(executor);
  std::ofstream file;
  file.open((_target + "_shrubbery").c_str(), std::ios::out | std::ios::trunc);
  if (file.is_open()) {
    file << "   MMMM_    ,..,\n        \"_ \"__\"MMMMM          ,...,,\n ,..., "
            "__.\" --\"    ,.,     _-\"MMMMMMM\nMMMMMM\"___ \"_._   "
            "MMM\"_.\"\" _ \"\"\"\"\"\"\n \"\"\"\"\"    \"\" , \\_.   \"_. "
            ".\"\n           ,., _\"__ \\__./ .\"\n       MMMMM_\"  \"_    "
            "./\n        ''''      (    )\n ._______________.-'____\"---._.\n";
    file.close();
  }
}

// *** Getter methods:
std::string ShrubberyCreationForm::getTarget() const {
  return _target;
}

// *** Constructors + Destructor + Overload of (<<)
// *** Orthodox canonical ShrubberyCreationForm / rule of three (+one)
ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("default", 145, 137), _target("default") {
  DEBUG_PRINT("ShrubberyCreationForm is constructed");
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
  DEBUG_PRINT("ShrubberyCreationForm is parameterizely constructed");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {
  DEBUG_PRINT("ShrubberyCreationForm is copy-constructed");
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& other) {
  if (this != &other) {
    this->_target = other._target;
  }
  return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
  DEBUG_PRINT("ShrubberyCreationForm is destructed");
}

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& form) {
  return (out << form.getName() << ", Signing grade: " << form.getGradeSign()
              << ", Executing grade: " << form.getGradeExec()
              << ", Sign: " << form.getSigned());
}