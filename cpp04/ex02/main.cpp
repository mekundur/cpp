#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int aSize = 4;

int main(void) {
    {
        // const   AAnimal* meta = new AAnimal();
        const   AAnimal* j = new Dog();
        const   AAnimal* i = new Cat();

        std::cout << j->getType() << " " << std::endl;
        j->makeSound();
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
        // meta->makeSound();

        delete i;
        delete j;
        // delete meta;
    }
    // {
    //     const   AAnimal* AAnimals[aSize];
        
    //     for (int i = 0; i < aSize; i++) {            
    //         if (i < aSize / 2)
    //             AAnimals[i] = new Dog();       
    //         else if (i >= aSize / 2)
    //             AAnimals[i] = new Cat();
    //     }
    //     // Dog dog1;
    //     // Dog dog2(dog1);

    //     // AAnimals[aSize - 1](AAnimals[aSize-2]);
    //     // AAnimals[1] = AAnimals[2];

    //     for (int i = 0; i < aSize; i++)
    //         delete AAnimals[i];
    // }

    return 0;
}