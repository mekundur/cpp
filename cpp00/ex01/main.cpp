/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekundur <mekundur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:46:43 by mekundur          #+#    #+#             */
/*   Updated: 2025/05/22 18:34:07 by mekundur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crappy.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook myBook;
	std::string	input;
	while (1)
	{
		std::cout << YELLOW << "Please enter a command: ADD or SEARCH or EXIT" << RESET << std::endl;
		if (!std::getline(std::cin, input)) {
			std::cin.clear();
            clearerr(stdin);
            continue;
		}
		if (!input.compare("EXIT") || !input.compare("exit") || std::cin.eof()){	
			std::cout << CYAN << "BYE BYE DEAR!" << RESET << std::endl;
			return 0;	
		}
		else if (!input.compare("ADD") || !input.compare("add"))
			myBook.ADD();
		else if (!input.compare("SEARCH") || !input.compare("search"))
			myBook.SEARCH();
	}
	return (0);
}