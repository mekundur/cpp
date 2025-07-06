#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main (void)
{
    ClapTrap    wallE("WALL.E🤖");
    FragTrap    eve("EVE🥚");
    ClapTrap    spaceship("Spaceship🚀");
    
    wallE.attack("Spaceship");
    spaceship.takeDamage(5);
    wallE.beRepaired(3);

    eve.attack("Spaceship");
    spaceship.takeDamage(8);
    eve.highFivesGuys();
    eve.beRepaired(5);   
 
    // spaceship.attack("WALL.E");
    // spaceship.beRepaired(3);
    // spaceship.attack("WALL.E");
    // wallE.takeDamage(8);
    // wallE.attack("Spaceship");

    return 0;
}