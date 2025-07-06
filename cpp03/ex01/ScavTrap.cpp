#include "ScavTrap.hpp"

void    ScavTrap::attack(const std::string& target) {    
    
    if  (_hitPoints <= 0 && _energyPoints > 0)
        std::cout << CYAN << "ScavTrap " << _name << " can't attack because it's dead but you can still revive him!" << RESET << std::endl;
    else if (_hitPoints <= 0 && _energyPoints <= 0)
        std::cout << CYAN << "ScavTrap "<< _name << " can't attack because it's ultimately disintegrated to its cells :(" << RESET << std::endl;
    else {
        std::cout << CYAN << "ScavTrap " << this->_name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << RESET << std::endl;
        _energyPoints--;
    }
}

void    ScavTrap::guardGate() {
    std::cout << CYAN << "ScavTrap " << this->_name << " is now in Gate keeper mode" << RESET << std::endl;
}

ScavTrap::ScavTrap() {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20; 
    std::cout << CYAN << "ScavTrap" << " is constructed by default" << RESET << std::endl;
}

ScavTrap::ScavTrap(const std::string& str) : ClapTrap(str) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << CYAN << "ScavTrap " << this->_name << " is constructed with parameterized constructor" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << CYAN << "ScavTrap " << this->_name << " is copy constructed" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != & other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
        std::cout << CYAN << "COPY ASSIGNMENT!" << RESET << std::endl;
    }
    return (*this);
}

ScavTrap::~ScavTrap() {
    std::cout << CYAN << "ScavTrap " << this->_name << " is destructed" << RESET << std::endl;
}
