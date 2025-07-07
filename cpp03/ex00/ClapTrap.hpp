#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define CYAN    "\033[36m"
# define RESET   "\033[0m"

class ClapTrap {
    
    private:
        std::string     _name;
        int             _hitPoints;
        int             _energyPoints;
        int             _attackDamage;
    
    public:
        void            attack(const std::string& target);
        void            takeDamage(unsigned int amount);
        void            beRepaired(unsigned int amount);
        ClapTrap();
        ClapTrap(const std::string& str);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();
};

#endif