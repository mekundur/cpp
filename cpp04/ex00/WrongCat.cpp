#include "WrongCat.hpp"

void WrongCat::makeSound() const {
    std::cout << "Meeooooow! Here I am, the WrongCat! 😼" << std::endl;
}

WrongCat::WrongCat() {
    _type = "WrongCat 😼";
    std::cout << "WrongCat is constructed by default constructor 😼" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "WrongCat is constructed by copy constructor 😼" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other) {
        _type = other._type;
        std::cout << this->_type << "WrongCat is initialized by copy assignment! 😼" << std::endl;
    }
    return (*this);
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat is destructed! 😼" << std::endl;
}