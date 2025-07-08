#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>
# include <sstream> 

class   Brain {

    private:
        std::string _ideas[100];
    
    public:
        void            setIdea(int index, const std::string& idea);
        std::string&    getIdea(int index);
        Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        ~Brain();
};

#endif