/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekundur <mekundur@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:07:44 by mekundur          #+#    #+#             */
/*   Updated: 2025/04/17 15:37:23 by mekundur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crappy.hpp"

void    Contact::set_first_name(void)
{
    std::cout << "First name of the contact" << std::endl;	
    while (1)
    {
        std::getline(std::cin, first_name);
        if (std::cin.eof()){	
			std::cout << "Bye bye!" << "\n";
            exit(1);
		}
        if (!first_name.compare(""))
            std::cout << "Please enter a valid first name" << '\n';
        else
            break;
    }
}

void    Contact::set_last_name(void)
{
    std::cout << "Last name of the contact" << std::endl;	
    while (1)
    {
        std::getline(std::cin, last_name);
        if (std::cin.eof()){	
			std::cout << "Bye bye!" << "\n";
            exit(1);
		}
        if (!last_name.compare(""))
            std::cout << "Please enter a valid last name" << '\n';
        else
            break;
    }
}

void    Contact::set_nickname(void)
{
    std::cout << "Nickname for the contact" << std::endl;	
    while (1)
    {
        std::getline(std::cin, nickname);
        if (std::cin.eof()){	
			std::cout << "Bye bye!" << "\n";
            exit(1);
		}
        if (!nickname.compare(""))
            std::cout << "Please enter a valid nickname" << '\n';
        else
            break;
    }
}

void    Contact::set_phone_number(void)
{
    std::cout << "Phone number of the contact" << std::endl;	
    while (1)
    {
        std::getline(std::cin, phone_number);
        if (std::cin.eof()){	
			std::cout << "Bye bye!" << "\n";
            exit(1);
		}
        if (!phone_number.compare(""))
            std::cout << "Please enter a valid phone number" << '\n';
        else
            break;
    }
}

void    Contact::set_darkest_secret(void)
{
    std::cout << "Darkest secret of the contact hmm!" << std::endl;	
    while (1)
    {
        std::getline(std::cin, darkest_secret);
        if (std::cin.eof()){	
			std::cout << "Bye bye!" << "\n";
            exit(1);
		}
        if (!darkest_secret.compare(""))
            std::cout << "Please enter the darkest secret" << '\n';
        else
            break;
    }
}

void	Contact::DisplayAll(int i, int *count)
{
    if (first_name.length() > 0){
        std::cout << std::setw(10) <<  i << "|";
        std::cout << std::setw(10) << ft_truncate(first_name) << "|";
        std::cout << std::setw(10) << ft_truncate(last_name) << "|";
        std::cout << std::setw(10) << ft_truncate(nickname) << std::endl;
        *count += 1;
    }    
}

void	Contact::DisplaySingle(int index)
{
    if (first_name.length() > 0)
    {
        std::cout << "First Name     : " << first_name << std::endl;
        std::cout << "Last Name      : " << last_name << std::endl;
        std::cout << "Nickname       : " << nickname << std::endl;
        std::cout << "Phone Number   : " << phone_number << std::endl;
        std::cout << "Darkest Secret : " << darkest_secret << std::endl;

    }
    else
        std::cout << "There's no contact in index: " << index << std::endl;


}