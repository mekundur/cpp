#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP

# include <string>
# include <iostream>
# include <exception>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm 
{
    private:
        std::string   _target;

    public:
        virtual void    execute(Bureaucrat const & executor) const;
        std::string     getTarget() const;

        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();
};

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& form);

#endif