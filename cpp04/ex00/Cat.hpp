#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include <iostream>
# include "Animal.hpp"

class   Cat : public Animal {
 
    public:
        virtual void makeSound() const;
        Cat();
        Cat(const std::string& type);
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        ~Cat();
};

#endif