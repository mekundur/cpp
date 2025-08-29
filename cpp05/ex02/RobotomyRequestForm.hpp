#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

# include <string>
# include <iostream>
# include <exception>
# include <stdlib.h>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm 
{
    private:
        std::string   _target;

    public:
        virtual void    execute(Bureaucrat const & executor) const;
        std::string     getTarget() const;

        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();
};

std::ostream& operator<<(std::ostream& out, const RobotomyRequestForm& form);

#endif