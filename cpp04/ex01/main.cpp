#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int aSize = 10;

int main(void) {
    {
        const   Animal* animals[aSize];
        
        for (int i = 0; i < aSize; i++) {            
            if (i < aSize / 2)
                animals[i] = new Dog();       
            else if (i >= aSize / 2)
                animals[i] = new Cat();
        }
        Dog dog1;
        Dog dog2(dog1);

        // animals[aSize - 1](animals[aSize-2]);
        // animals[1] = animals[2];

        for (int i = 0; i < aSize; i++)
            delete animals[i];
    }

    return 0;
}