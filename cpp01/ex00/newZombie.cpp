#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie *boo;
    boo = new Zombie;
    boo->set_name(name);
    return boo;
}