#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int aSize = 4;

int main(void) {
    {
        const   Animal* animals[aSize];
        
        for (int i = 0; i < aSize; i++) {            
            if (i < aSize / 2)
                animals[i] = new Dog();       
            else if (i >= aSize / 2)
                animals[i] = new Cat();
        }

        for (int i = 0; i < aSize; i++)
            delete animals[i];
    }
    std::cout << std::endl;
    {
        Dog dog1;
        Dog dog2(dog1);
        dog1.setBrainIdea(5, "Let's fight nihahaha");
        std::cout << dog1.getBrainIdea(5) << std::endl;
        std::cout << dog2.getBrainIdea(5) << std::endl;
    }

    return 0;
}