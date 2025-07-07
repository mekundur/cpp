#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class   Cat : public Animal {
 
    private:
        // Brain*  _brain;

    public:
        virtual void makeSound() const;
        Cat();
        Cat(const std::string& type);
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        ~Cat();
};

#endif