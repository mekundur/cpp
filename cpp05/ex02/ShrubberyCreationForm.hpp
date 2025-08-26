#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP

# include <string>
# include <iostream>
# include <exception>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm 
{
    private:
        std::string   _target;

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();
};

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& form);

#endif