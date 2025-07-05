#include "ClapTrap.hpp"

int main (void)
{
    ClapTrap wall_e("WALL.E");

    wall_e.attack("Spaceship");
    wall_e.takeDamage(5);
    wall_e.beRepaired(3);

    ClapTrap eve("EVE");
    // eve = wall_e; 
    eve.attack("Spaceship");
    eve.takeDamage(8);
    eve.beRepaired(5);    

    return 0;
}