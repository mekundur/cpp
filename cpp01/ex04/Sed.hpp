#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <string>
# include <fstream>

class Sed
{
    private:
	std::string filename;
	std::string s1;
	std::string s2;
    std::ifstream infile;
	std::ofstream outfile;

    public:
    Sed(std::string arg1, std::string arg2, std::string arg3);
    ~Sed();
    bool    manageFiles();
    void    replace();
};

#endif