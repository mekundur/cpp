#include "crappy.hpp"

std::string	ft_truncate(std::string str)
{
	if (str.length() > 10){
		str = str.substr(0, 9);
		str.append(".");
	}




	return str;
}
