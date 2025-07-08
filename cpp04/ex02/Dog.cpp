#include "Dog.hpp"

void Dog::makeSound() const {
    std::cout << "Woff woff! Here I am, the Dog! 🐶 " << std::endl;
}

Dog::Dog() {
    _type = "Dog";
    _brain = new Brain();
    std::cout << "Dog with a brain is constructed by default constructor 🐶 " << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other) {
    _brain = new Brain(*other._brain);
    std::cout << "Dog with a brain is constructed by copy constructor 🐶 " << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        _type = other._type;
        if (_brain)
            delete _brain;
        _brain = new Brain(*other._brain); // Deep copy: allocates completely new object by copy constructing already existing other's brain!
        // _brain = other._brain; // this is a shallow copy both this and other objects are pointing to other's already initialized brain.
        std::cout << this->_type << " Dog with a brain is initialized by copy assignment! 🐶 " << std::endl;
    }
    return (*this);
}

Dog::~Dog() {
    delete  this->_brain;
    std::cout << "Dog with a brain is destructed! 🐶 " << std::endl;
}