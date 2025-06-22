#include "HumanB.hpp"

void    HumanB::attack()
{
    std::cout << name << " attacks with their ";
    if (weapon)
        std::cout << weapon->getType() << std::endl;
    else
        std::cout << "inexsistent weapon!" << std::endl;
}

void    HumanB::setWeapon(Weapon& tool)
{
    weapon = &tool;
}

HumanB::HumanB(std::string str) : name(str) 
{
    weapon = NULL;
}