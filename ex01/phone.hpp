/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekundur <mekundur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:01:48 by mekundur          #+#    #+#             */
/*   Updated: 2025/05/15 17:31:05 by mekundur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_HPP
# define PHONE_HPP

#include <string>
#include <cstdio>
#include <iostream>
#include <stdio.h>

int	index = 0;

class	Contact
{
	public:
/*		Contact()
		{
			std::cout << "HELLO" << std::endl;
			std::cin >> first_name;
			std::cout << first_name << std::endl;
				
		}
		void	ft_display(void)
		{
			std::cout << first_name << std::endl;
			printf("%.10s\n", first_name.c_str());	
		}
*/						
		void	Add(void)
		{
			std::cout << "Please enter following info for the contact #" << index % 8 << std::endl;
			std::cout << "First name of the contact" << std::endl;	
			std::getline(std::cin, first_name);
			std::cout << "Last name of the contact" << std::endl;	
			std::getline(std::cin, last_name);
			std::cout << "Nickname of the contact" << std::endl;	
			std::getline(std::cin, nickname);
			std::cout << "Phone number" << std::endl;	
			std::getline(std::cin, phone_number);
			std::cout << "Darkest secret!" << std::endl;	
			std::getline(std::cin, darkest_secret);

				
		}
		void	Search(void)
		{
		
		
		
		
		}
		void	Display(int i)
		{
			if (first_name.length() > 0)
				printf("%10d|%10s|%10s|%10s\n", i, first_name.c_str(), last_name.c_str(), nickname.c_str());	
			//	std::cout << i << "|" << first_name << "|" << last_name << "|" << nickname << std::endl;
		
		}


	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;

};

class	PhoneBook
{
	public:
		void	ADD(void)
		{
			contacts[index % 8].Add();
			

			index++;
		}
		void	SEARCH(void)
		{
	
			for (int i = 0; i < 8; i++)
				contacts[i].Display(i);
			
		
		}
	private:
		Contact contacts[8];

};


#endif
