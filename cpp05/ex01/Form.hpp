#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>

class Form
{
    private:
        const std::string   _name; 
        bool                _signed;
        const int           _gradeSign;
        const int           _gradeExec;

    public:
        std::string     getName() const;
        int             getGradeSign() const;
        int             getGradeExec() const;
        void            gradeIncrement();
        void            gradeDecrement();

        Form();
        Form(const std::string& name, int grade);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const Form& Form);

#endif