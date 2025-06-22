#include "Weapon.hpp"

const   std::string& Weapon::getType()
{
    const std::string& typeREF = type;
    return (typeREF);
}

void    Weapon::setType(std::string str)
{
    type = str;
}

Weapon::Weapon(std::string str)
{
    setType(str);    
    // std::cout << "Weapon type is set!" << std::endl;
}

Weapon::~Weapon()
{
    // std::cout << "Weapon is deconstructed!" << std::endl;
}
