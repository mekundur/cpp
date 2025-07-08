#include "Cat.hpp"

void Cat::makeSound() const {
    std::cout << "Woff woff! Here I am, the Cat! 😼 " << std::endl;
}

Cat::Cat() {
    _type = "Cat";
    _brain = new Brain();
    std::cout << "Cat with a brain is constructed by default constructor 😼 " << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other) {
    _brain = new Brain(*other._brain);
    std::cout << "Cat with a brain is constructed by copy constructor 😼 " << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        _type = other._type;
        if (_brain)
            delete _brain;
        _brain = new Brain(*other._brain); // Deep copy: allocates completely new object by copy constructing already existing other's brain!
        // _brain = other._brain; // this is a shallow copy both this and other objects are pointing to other's already initialized brain.
        std::cout << this->_type << " Cat with a brain is initialized by copy assignment! 😼 " << std::endl;
    }
    return (*this);
}

Cat::~Cat() {
    delete  this->_brain;
    std::cout << "Cat with a brain is destructed! 😼 " << std::endl;
}