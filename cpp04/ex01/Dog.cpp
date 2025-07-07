#include "Dog.hpp"

void Dog::makeSound() const {
    std::cout << "Woff woff! Here I am, the Dog! 🐶 " << std::endl;
}

Dog::Dog() {
    _type = "Dog 🐶 ";
    _brain = new Brain;
    std::cout << "Dog is constructed by default constructor 🐶 " << std::endl;
}

Dog::Dog(const std::string& type) : Animal(type) {
    _brain = new Brain();
    std::cout << "Dog is constructed by parameterized constructor 🐶 " << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog is constructed by copy constructor 🐶 " << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        _type = other._type;
        _brain = other._brain;
        std::cout << this->_type << " Dog is initialized by copy assignment! 🐶 " << std::endl;
    }
    return (*this);
}

Dog::~Dog() {
    std::cout << "Dog is destructed! 🐶 " << std::endl;
    delete  this->_brain;
}