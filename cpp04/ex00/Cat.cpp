#include "Cat.hpp"

void Cat::makeSound() const {
    std::cout << "Meeooooow! Here I am, the Cat! 😼" << std::endl;
}

Cat::Cat() {
    _type = "Cat 😼";
    std::cout << "Cat is constructed by default constructor 😼" << std::endl;
}

Cat::Cat(const std::string& type) : Animal(type) {
    std::cout << "Cat is constructed by parameterized constructor 😼" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat is constructed by copy constructor 😼" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        _type = other._type;
        std::cout << this->_type << "Cat is initialized by copy assignment! 😼" << std::endl;
    }
    return (*this);
}

Cat::~Cat() {
    std::cout << "Cat is destructed! 😼" << std::endl;
}