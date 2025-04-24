/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekundur <mekundur@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:07:44 by mekundur          #+#    #+#             */
/*   Updated: 2025/04/17 15:37:23 by mekundur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.hpp"

int	main(void)
{

	PhoneBook myBook;
/*	myBook->contacts[0].first_name = "Mertcan";
	myBook->contacts[0].last_name = "Kunduraci";
	myBook->contacts[0].phone_number = 4915258437614;
*/
//	Contact random;
//	random.ft_display();
	std::cout << "Welcome to crappy phonebook!" << std::endl;
	std::string	input;
	while (1)
	{
		std::cout << "Please enter a command ADD or SEARCH or EXIT" << std::endl;
		std::getline(std::cin, input);
		if (!input.compare("ADD"))
			myBook.ADD();
		else if (!input.compare("SEARCH"))
			myBook.SEARCH();
		else if (!input.compare("EXIT"))
			break;
	}
	return (0);
}
