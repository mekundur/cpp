#include "Animal.hpp"

void Animal::makeSound() const {
    std::cout << "WrongAnimal has an identity crisis! Doesn't have a unique voice.." << std::endl;
}

std::string Animal::getType() const {
    return (this->_type);
}

Animal::Animal() {
    std::cout << "Animal is constructed by default constructor" << std::endl;
}

Animal::Animal(const std::string& type) : _type(type) {
    std::cout << "Animal is constructed by parameterized constructor" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type) {
    std::cout << "Animal is constructed by copy constructor" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        _type = other._type;
        std::cout << this->_type << " Animal is initialized by copy assignment!" << std::endl;
    }
    return (*this);
}

Animal::~Animal() {
    std::cout << "Animal is destructed!" << std::endl;
}