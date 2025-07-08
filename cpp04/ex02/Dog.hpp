#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class   Dog : public AAnimal {
    
    private:
        Brain*  _brain;

    public:
        virtual void makeSound() const;
        Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        ~Dog();
};

#endif