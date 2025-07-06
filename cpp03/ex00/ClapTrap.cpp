#include "ClapTrap.hpp"

void    ClapTrap::attack(const std::string& target) {    
    
    if  (_hitPoints <= 0 && _energyPoints > 0)
        std::cout << _name << " can't attack because it's dead but you can still revive him!" << std::endl;
    else if (_hitPoints <= 0 && _energyPoints <= 0)
        std::cout << _name << " can't attack because it's ultimately disintegrated to its cells :(" << std::endl;
    else {
        std::cout << RED << this->_name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << RESET << std::endl;
        _energyPoints--;
    }
}

void    ClapTrap::takeDamage(unsigned int amount) {
    
    std::cout << RED << this->_name << " is attacked and damaged by " << amount << " points!" << RESET << std::endl;
    _hitPoints -= amount;
    if (_hitPoints < 0)
        this->_hitPoints = 0;
    std::cout << this->_name << " health status " << this->_hitPoints << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount) {
    
    if (_energyPoints) {
        std::cout << GREEN << this->_name << " is repaired by " << amount << " points!" << RESET << std::endl;
        _hitPoints += amount;
        _energyPoints--;
    }
    else 
        std::cout << RED << _name << " 's energy has already drained!" << RESET << std::endl;

}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != & other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
        std::cout << "COPY ASSIGNMENT!" << std::endl;
    }
    return (*this);
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
    std::cout << this->_name << " is copy constructed" << std::endl;
}

ClapTrap::ClapTrap(const std::string& str) : _name(str), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << this->_name << " is constructed with parameterized constructor" << std::endl;
}

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << this->_name << " is constructed by default" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << this->_name << " is destructed" << std::endl;
}
        