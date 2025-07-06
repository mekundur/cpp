#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define CYAN    "\033[36m"
# define RESET   "\033[0m"

class ScavTrap: public ClapTrap {

    public:
        void    guardGate();
        void    attack(const std::string& target);    
        ScavTrap();
        ScavTrap(const std::string& str);
        ScavTrap(const ScavTrap& other);
        ScavTrap& operator=(const ScavTrap& other);
        ~ScavTrap();
};

#endif