#include "Zombie.hpp"

void    randomChump(std::string name)
{
    Zombie  foo;
    foo.set_name(name);
    foo.announce();
}
