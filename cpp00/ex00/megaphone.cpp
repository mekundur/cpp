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
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int j = 1; argv[j]; j++)
		{
			for (int i = 0; argv[j][i]; i++)
			{
				if (argv[j][i] >= 97 && argv[j][i] <= 122)
					argv[j][i] = toupper(argv[j][i]); 
			}
			std::cout << argv[j];
		}
		std::cout << std::endl;
	}	
	return 0;
}

