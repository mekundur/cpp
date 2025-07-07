#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

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
    {
        const   WrongAnimal* wrongMeta = new WrongAnimal();
        const   WrongAnimal* wrongCat = new WrongCat();
        wrongMeta->makeSound();
        wrongCat->makeSound();

        delete wrongCat;
        delete wrongMeta;
    }
    return 0;
}