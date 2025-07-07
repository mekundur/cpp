#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class   Brain {

    private:
        std::string _ideas[100];
    
    public:
        Brain();
        Brain(const std::string& _ideas);
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        ~Brain();
};

#endif