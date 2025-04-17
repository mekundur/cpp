/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekundur <mekundur@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:01:48 by mekundur          #+#    #+#             */
/*   Updated: 2025/04/17 15:39:01 by mekundur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_HPP
# define PHONE_HPP

#include <string>
#include <cstdio>
#include <iostream>

class	Contact
{
	public:
		Contact()
		{
			std::cout << "HELLO" << std::endl;
			std::cin >> first_name;
			std::cout << first_name << std::endl;
				
		}
		void	ft_display(void)
		{
			std::cout << first_name << std::endl;
			
		
		
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
	Contact contacts[8];

};


#endif
