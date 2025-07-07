#include "ClapTrap.hpp"

int main (void)
{
    ClapTrap    wallE("WALL.E🤖");
    ClapTrap    eve("EVE🥚");
    ClapTrap    spaceship("Spaceship🚀");
    
    wallE.attack("Spaceship");
    spaceship.takeDamage(5);
    wallE.beRepaired(3);

    eve.attack("Spaceship");
    spaceship.takeDamage(8);
    eve.beRepaired(5);   
    eve.attack("Spaceship");
 
    spaceship.attack("WALL.E");
    spaceship.beRepaired(3);
    spaceship.attack("WALL.E");
    wallE.takeDamage(8);

    return 0;
}