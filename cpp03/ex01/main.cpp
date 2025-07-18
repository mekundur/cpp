#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main (void)
{
    ClapTrap    wallE("WALL.E🤖");
    ScavTrap    eve("EVE🥚");
    ClapTrap    spaceship("Spaceship🚀");
    
    wallE.attack("Spaceship");
    spaceship.takeDamage(5);
    wallE.beRepaired(3);

    eve.attack("Spaceship");
    spaceship.takeDamage(8);
    eve.guardGate();
    eve.beRepaired(5);   
 
    // spaceship.attack("WALL.E");
    // spaceship.beRepaired(3);
    // spaceship.attack("WALL.E");
    // wallE.takeDamage(8);
    // wallE.attack("Spaceship");

    return 0;
}