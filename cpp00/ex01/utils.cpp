#include "crappy.hpp"

bool	isDigit(const std::string &str)
{	
	if (str.empty())
		return false;
	for (std::string::size_type i = 0; i < str.length(); i++) {
		if (str[i] == ' ')
			continue;
		if (!(str[i] >= '0' && str[i] <= '9')) {
			return false;
		}
	}
	return true;
}

bool is_whiteLine(const std::string &str)
{
	if (str.empty())
		return false;
    for (std::string::size_type i = 0; i < str.length(); ++i) {
        if (!std::isspace((str[i])))
            return false;
    }
    return true;
}

bool	isAlphabetic(const std::string &str)
{
	if (str.empty())
		return false;
	for (std::string::size_type i = 0; i < str.length(); i++) {
		if (str[i] == ' ')
			continue;
		else if (!isalpha(str[i]))
			return false;
	}
	return true;
}

std::string	ft_strTrim(std::string str)
{
	if (str.empty())
		return str;
 	std::string::size_type i = 0;
	std::string::size_type len = str.length() - 1;
	while (len > i && str[len] == ' ')
		len--;
	while (len > i && i < str.length() && str[i] == ' ')
		i++;
	str = str.substr(i, len - i + 1);
	return str;
}

std::string	ft_truncate(std::string str)
{
	if (str.empty())
		return str;
	if (str.length() > 10){
		str = str.substr(0, 9);
		str.append(".");
	}
	return str;
}
