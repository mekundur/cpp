/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekundur <mekundur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:07:44 by mekundur          #+#    #+#             */
/*   Updated: 2025/05/22 18:35:04 by mekundur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crappy.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	std::cout << CYAN << "WELCOME TO CRAPPY NOTEBOOK!" << RESET << std::endl;
	std::cout << CYAN << "(Crappy beacuse it's limited to save only 8 contacts!)" << RESET << std::endl;
	std::cout << CYAN << "(You can even memorize that amount of details if you try a bit! Anyway...)" << RESET << std::endl << std::endl;
	index = 0;
}

PhoneBook::~PhoneBook()
{
	std::cout << CYAN << "PhoneBook destructed!" << RESET << std::endl;
}

void	PhoneBook::ADD(void)
{
    std::cout << YELLOW << "Please enter the following info for the contact" << RESET << std::endl;
	contacts[index % 8].set_first_name();
	contacts[index % 8].set_last_name();
	contacts[index % 8].set_nickname();
	contacts[index % 8].set_phone_number();
	contacts[index % 8].set_darkest_secret();
	std::cout << GREEN << "Contact saved into the index no: " << RESET << index % 8 << std::endl;
	index++;
}

void	PhoneBook::SEARCH(void)
{
	int display_index;
	int	count = 0;
	for (int i = 0; i < 8; i++)
		contacts[i].DisplayAll(i, &count);
	while (count){
		std::cout << YELLOW << "Enter an index number between 0 and 7 to display all details of respective contact:" << RESET << std::endl;
		std::cin >> display_index;
		if (std::cin.eof()){
			std::cin.clear();
			clearerr(stdin);
			continue;
		}
		while (!std::cin.good() || !(display_index >= 0 && display_index < 8)){
			std::cin.clear();			
			std::cin.ignore(1000000, '\n');
			std::cout << RED << "Enter an index number between 0 and 7 to display all details of respective contact:" << RESET << std::endl;
			std::cin >> display_index;
			if (std::cin.eof())
				break;
		}
		contacts[display_index].DisplaySingle(display_index);
		std::cin.clear();			
		std::cin.ignore(1000000, '\n');
		break ;
	}
}

