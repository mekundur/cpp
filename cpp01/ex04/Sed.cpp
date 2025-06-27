#include "Sed.hpp"

void	Sed::replace()
{
	std::string	line;
	std::string	tmp;
	std::size_t n1;
	std::size_t n2;

	n1 = 0;
	while (std::getline(infile, line)) {
		n1 = 0;
		while ((n2 = line.find(s1, n1)) != std::string::npos) {
			tmp.append(line, n1, n2 - n1);
			tmp.append(s2);
			n1 = n2 + s1.length();
			std::cout << n2 << std::endl;
		}
		tmp.append(line, n1, line.length() - n1);
		outfile << tmp << std::endl;
		tmp.clear();
	}
}

bool    Sed::manageFiles()
{
	if (filename.empty()) {
		std::cerr << "Error: <filename> cannot be NULL" << std::endl;
		return 0;
	}
	infile.open(filename.c_str(), std::ios::in);
	if (!infile.good()) {
		std::cerr << "Error: Unable to open the file: " << filename << std::endl;
		return 0;
	}
	outfile.open((filename + ".replace").c_str(), std::ios::out | std::ios::trunc);
	if (!outfile.good()) {
		std::cerr << "Error: Unable to create/open the file: " << filename << ".replace" << std::endl;
		return 0;
	}
	return 1;
}

Sed::Sed(std::string arg1, std::string arg2, std::string arg3)
{
	filename = arg1;
	s1 = arg2;
	s2 = arg3;
}

Sed::~Sed()
{
	infile.close();
	outfile.close();
	std::cout << "Sed run & deconstructed" << std::endl;
}