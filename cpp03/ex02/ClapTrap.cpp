#include "ClapTrap.hpp"

void    ClapTrap::attack(const std::string& target) {    
    
    if  (_hitPoints <= 0 && _energyPoints > 0)
        std::cout << YELLOW << "ClapTrap " << _name << " can't attack because it's dead but you can still revive him!" << RESET << std::endl;
    else if (_hitPoints <= 0 && _energyPoints <= 0)
        std::cout << YELLOW << "ClapTrap "<< _name << " can't attack because it's ultimately disintegrated to its cells :(" << RESET << std::endl;
    else {
        std::cout << YELLOW << "ClapTrap " << this->_name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << RESET << std::endl;
        _energyPoints--;
    }
}

void    ClapTrap::takeDamage(unsigned int amount) {
    
    std::cout << YELLOW << "ClapTrap " << this->_name << " is attacked and damaged by " << amount << " points!" << RESET << std::endl;
    _hitPoints -= amount;
    if (_hitPoints < 0)
        this->_hitPoints = 0;
    std::cout << YELLOW << "ClapTrap " << this->_name << " health status " << this->_hitPoints << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount) {
    
    if (_energyPoints) {
        std::cout << YELLOW << "ClapTrap " << this->_name << " is repaired by " << amount << " points!" << RESET << std::endl;
        _hitPoints += amount;
        _energyPoints--;
    }
    else 
        std::cout << YELLOW << "ClapTrap " << this->_name << " 's energy has already drained!" << RESET << std::endl;

}


ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << YELLOW << "ClapTrap " << " is constructed by default" << RESET  << std::endl;
}

ClapTrap::ClapTrap(const std::string& str) : _name(str), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << YELLOW << "ClapTrap " << this->_name << " is constructed with parameterized constructor" << RESET  << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap&other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
    std::cout << YELLOW << "ClapTrap " << this->_name << " is copy constructed" << RESET  << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap&other) {
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
        std::cout << YELLOW << "COPY ASSIGNMENT!" << RESET << std::endl;
    }
    return (*this);
}

ClapTrap::~ClapTrap() {
    std::cout << YELLOW << "ClapTrap " << this->_name << " is destructed" << RESET  << std::endl;
}
