#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include "iostream"

class HumanA
{
    private:
        std::string name;
        Weapon&      weapon;

    public:
        HumanA(std::string str, Weapon& tool);
        void    attack();
};

#endif