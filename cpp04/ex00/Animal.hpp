#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class   Animal {

    protected:
        std::string _type;
    
    public:
        virtual void makeSound() const;
        std::string getType() const;
        Animal();
        Animal(const std::string& type);
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        virtual ~Animal();
};

#endif