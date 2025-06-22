#include "HumanA.hpp"

void    HumanA::attack()
{
    std::cout << name << " attacks with their ";
    std::cout << weapon.getType() << std::endl;;
}

HumanA::HumanA(std::string str, Weapon& tool) : name(str), weapon(tool) 
{}