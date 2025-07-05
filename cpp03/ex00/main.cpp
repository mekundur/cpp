#include "ClapTrap.hpp"

int main (void)
{
    
    ClapTrap wallE((std::string)"WALL.E");

    wallE.attack("Spaceship");
    wallE.takeDamage(5);
    wallE.beRepaired(3);

    ClapTrap eve("EVE");
    // eve = wall_e; 
    eve.attack("Spaceship");
    eve.takeDamage(8);
    eve.beRepaired(5);    

    return 0;
}