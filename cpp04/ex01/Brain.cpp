#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain is constructed by default constructor" << std::endl;
}

Brain::Brain(const std::string& _ideas) {
    std::cout << "Brain is constructed by parameterized constructor" << std::endl;
}

Brain::Brain(const Brain& other) : _ideas(other._ideas) {
    std::cout << "Brain is constructed by copy constructor" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        std::cout << " Brain is initialized by copy assignment!" << std::endl;
    }
    return (*this);
}

Brain::~Brain() {
    std::cout << "Brain is destructed!" << std::endl;
}