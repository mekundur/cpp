#include "WrongAnimal.hpp"

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal has an identity crisis! Doesn't have a unique voice.." << std::endl;
}

std::string WrongAnimal::getType() const {
    return (this->_type);
}

WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal is constructed by default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : _type(type) {
    std::cout << "WrongAnimal is constructed by parameterized constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type) {
    std::cout << "WrongAnimal is constructed by copy constructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other) {
        _type = other._type;
        std::cout << this->_type << " WrongAnimal is initialized by copy assignment!" << std::endl;
    }
    return (*this);
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal is destructed!" << std::endl;
}