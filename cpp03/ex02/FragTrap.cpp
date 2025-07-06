#include "FragTrap.hpp"

void    FragTrap::highFivesGuys() {
    std::cout << CYAN << "FragTrap " << this->_name << ": 'Heeey give me Hi5 folks!🖐️'" << RESET << std::endl;
}

FragTrap::FragTrap() {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20; 
    std::cout << CYAN << "FragTrap" << " is constructed by default" << RESET << std::endl;
}

FragTrap::FragTrap(const std::string& str) : ClapTrap(str) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << CYAN << "FragTrap " << this->_name << " is constructed with parameterized constructor" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << CYAN << "FragTrap " << this->_name << " is copy constructed" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != & other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
        std::cout << CYAN << "COPY ASSIGNMENT!" << RESET << std::endl;
    }
    return (*this);
}

FragTrap::~FragTrap() {
    std::cout << CYAN << "FragTrap " << this->_name << " is destructed" << RESET << std::endl;
}
