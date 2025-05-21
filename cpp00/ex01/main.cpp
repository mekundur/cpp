/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekundur <mekundur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:46:43 by mekundur          #+#    #+#             */
/*   Updated: 2025/05/21 19:53:51 by mekundur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crappy.hpp"

int	main(void)
{
	PhoneBook myBook;
	std::string	input;
	while (1)
	{
		std::cout << "Please enter a command: ADD or SEARCH or EXIT" << std::endl;
		std::getline(std::cin, input);
		if (!input.compare("EXIT") || !input.compare("exit") || std::cin.eof()){	
			std::cout << "Bye bye!" << "\n";
            exit(1);
		}
		else if (!input.compare("ADD") || !input.compare("add"))
			myBook.ADD();
		else if (!input.compare("SEARCH") || !input.compare("search"))
			myBook.SEARCH();
	}
	return (0);
}