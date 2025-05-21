#include "crappy.hpp"

bool	isDigit(const std::string& str)
{
	for (std::string::size_type i = 0; i < str.length(); i++) {
		if (!(str[i] >= '0' && str[i] <= '9')) {
			return false;
		}
	}
	return true;
}

std::string	ft_strTrim(std::string str)
{
	// std::string::size_type len = str.length();
	for (std::string::size_type i = 0; i < str.length() && str[i] == ' '; i++)
	{
		str = str.substr(i);
	}
	return str;
}

bool	isAlphabetic(const std::string& str)
{
	for (std::string::size_type i = 0; i < str.length(); i++) {
		if (str[i] == ' ')
			continue;
		else if (!isalpha(str[i]))
			return false;
			}
	return true;
}

std::string	ft_truncate(std::string str)
{
	if (str.length() > 10){
		str = str.substr(0, 9);
		str.append(".");
	}
	return str;
}
