#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include <iostream>
# include "Animal.hpp"

class   Dog : public Animal {
 
    public:
        virtual void makeSound() const;
        Dog();
        Dog(const std::string& type);
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        ~Dog();
};

#endif