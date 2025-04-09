/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekundur <mekundur@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:11:19 by mekundur          #+#    #+#             */
/*   Updated: 2025/04/09 18:36:30 by mekundur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{

	std::string str = "Hello Mertcan";
	std::cout<<str << std::endl;
	for(int i = 0; str[i]; i++)
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] -= 32; 
	}
	std::cout << str << std::endl;
//	str = toupper(str);
  //  	std::cout<<"\n"<<str<<"\n";
    return 0;
}

