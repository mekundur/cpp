#include "Brain.hpp"

void    Brain::setIdea(int index, const std::string& idea) {
    _ideas[index] = idea;
}

std::string&    Brain::getIdea(int index) {
    return (_ideas[index]);
}

Brain::Brain() {
    for (int i = 0; i < 100; i++) {
        std::ostringstream  tmp;
        tmp << "IDEA" << i;
        _ideas[i] = tmp.str();
    }
    std::cout << "Brain is constructed by default constructor 🧠" << std::endl;
    // std::cout << _ideas[50] << std::endl;
}

Brain::Brain(const Brain& other) {
    for (int i = 0; i < 100; i++)
        _ideas[i] = other._ideas[i];
    std::cout << "Brain is constructed by copy constructor 🧠" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (int i = 0; i < 100; i++)
            _ideas[i] = other._ideas[i];
        std::cout << " Brain is initialized by copy assignment! 🧠" << std::endl;
    }
    return (*this);
}

Brain::~Brain() {
    std::cout << "Brain is destructed! 🧠" << std::endl;
}