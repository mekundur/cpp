#include "AAnimal.hpp"

void AAnimal::makeSound() const {
    std::cout << "AAnimal has an identity crisis! Doesn't have a unique voice.." << std::endl;
}

std::string AAnimal::getType() const {
    return (this->_type);
}

AAnimal::AAnimal() {
    std::cout << "AAnimal is constructed by default constructor" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type) {
    std::cout << "AAnimal is constructed by copy constructor" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    if (this != &other) {
        _type = other._type;
        std::cout << this->_type << " AAnimal is initialized by copy assignment!" << std::endl;
    }
    return (*this);
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal is destructed!" << std::endl;
}