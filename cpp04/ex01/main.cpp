#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void) {
    {
        const   Animal* meta = new Animal();
        const   Animal* j = new Dog();
        const   Animal* i = new Cat();

        std::cout << j->getType() << " " << std::endl;
        j->makeSound();
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
        meta->makeSound();

        delete i;
        delete j;
        delete meta;
    }

    return 0;
}