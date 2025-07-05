#include "ClapTrap.hpp"

void    ClapTrap::attack(const std::string& target) {
        
    std::cout << "ClapTrap " << this->name << " attacks " << target 
                << ", causing " << attackDamage << " points of damage!" << std::endl;
    energyPoints--;
}

void    ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "ClapTrap " << this->name << " is attacked and damaged by " 
                << amount << " points!" << std::endl;
    hitPoints -= amount;
}

void    ClapTrap::beRepaired(unsigned int amount) {
    std::cout << "ClapTrap " << this->name << " is repaired by "
                << amount << " points!" << std::endl;
    hitPoints += amount;
    energyPoints--;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != & other) {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
        std::cout << "COPY ASSIGNMENT!" << std::endl;
    }
    return (*this);
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
    std::cout << " is copy constructed" << std::endl;
}

ClapTrap::ClapTrap(std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    // name = str;
    std::cout << this->name << " is constructed with parameter(s)" << std::endl;
}

ClapTrap::ClapTrap() : hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << this->name << " is constructed by default" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << this->name << " is deconstructed" << std::endl;
}
        