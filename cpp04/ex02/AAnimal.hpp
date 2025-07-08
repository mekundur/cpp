#ifndef AAnimal_HPP
# define AAnimal_HPP

# include <string>
# include <iostream>

class   AAnimal {

    protected:
        std::string _type;
    
    public:
        virtual void makeSound() const =0;
        std::string getType() const;
        AAnimal();
        AAnimal(const AAnimal& other);
        AAnimal& operator=(const AAnimal& other);
        virtual ~AAnimal() =0;
};

#endif