#ifndef CRAPPY_HPP
# define CRAPPY_HPP

# include <string>
# include <stdlib.h>
# include <stdio.h>
# include <iostream>
# include <iomanip>
# include <limits>

# include "Contact.hpp"
# include "PhoneBook.hpp"

std::string ft_strTrim(std::string str);
std::string ft_truncate(std::string str);
bool    	isAlphabetic(const std::string& str);
bool	    isDigit(const std::string& str);


#endif