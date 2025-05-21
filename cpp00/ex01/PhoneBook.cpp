/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekundur <mekundur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:07:44 by mekundur          #+#    #+#             */
/*   Updated: 2025/05/21 19:37:56 by mekundur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crappy.hpp"

PhoneBook::PhoneBook()
{
	std::cout << "Welcome to crappy phonebook!" << std::endl;
	index = 0;
}

PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook destructed!" << std::endl;
}

void	PhoneBook::ADD(void)
{
    std::cout << "Please enter following info for the contact" << std::endl;
	contacts[index % 8].set_first_name();
	contacts[index % 8].set_last_name();
	contacts[index % 8].set_nickname();
	contacts[index % 8].set_phone_number();
	contacts[index % 8].set_darkest_secret();
	std::cout << "Contact saved into the index no: " << index << std::endl;
	index++;
}

void	PhoneBook::SEARCH(void)
{
	int display_index;
	int	count = 0;
	for (int i = 0; i < 8; i++)
		contacts[i].DisplayAll(i, &count);
	while (count){
		std::cout << "Enter an index number to display all details of respective contact:" << std::endl;
		std::cin >> display_index;
		if (std::cin.eof())
				break;
		while (!std::cin.good() || !(display_index >= 0 && display_index < 8)){
			std::cin.clear();			
			std::cin.ignore(1000000, '\n');
			std::cout << "Enter an index number to display all details of respective contact:" << std::endl;
			std::cin >> display_index;
			if (std::cin.eof())
				break;
		}
		contacts[display_index].DisplaySingle(display_index);
		break ;
	}
	std::cin.clear();			
	std::cin.ignore(1000000, '\n');
}

