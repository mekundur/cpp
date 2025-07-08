#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class   Cat : public AAnimal {
 
    private:
        Brain*  _brain;

    public:
        virtual void makeSound() const;
        Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        ~Cat();
};

#endif