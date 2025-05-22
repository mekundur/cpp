#ifndef CRAPPY_HPP
# define CRAPPY_HPP

# include <string>
# include <stdio.h>
# include <iostream>
# include <iomanip>
# include <limits>

# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define CYAN    "\033[36m"
# define RESET   "\033[0m"

std::string ft_strTrim(std::string str);
std::string ft_truncate(std::string str);
bool    	isAlphabetic(const std::string& str);
bool	    isDigit(const std::string& str);
bool        is_whiteLine(const std::string& str);

#endif