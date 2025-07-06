#ifndef FragTrap_HPP
# define FragTrap_HPP

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define CYAN    "\033[36m"
# define RESET   "\033[0m"

class FragTrap: public ClapTrap {

    public:
        void    highFivesGuys(void);
        FragTrap();
        FragTrap(const std::string& str);
        FragTrap(const FragTrap& other);
        FragTrap& operator=(const FragTrap& other);
        ~FragTrap();
};

#endif