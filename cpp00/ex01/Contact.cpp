/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekundur <mekundur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:07:44 by mekundur          #+#    #+#             */
/*   Updated: 2025/05/21 20:16:40 by mekundur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crappy.hpp"

void    Contact::set_first_name(void)
{
    std::cout << GREEN << "First name of the contact:" << RESET << std::endl;	
    while (1)
    {
		if (!std::getline(std::cin, first_name)) {
			std::cin.clear();
            clearerr(stdin);
            continue;
		}
        if (first_name.empty() || !isAlphabetic(first_name) || is_whiteLine(first_name))
            std::cout << RED << "Please enter a valid first name:" << RESET << std::endl;
        else {
            first_name = ft_strTrim(first_name);
            break;
        }
    }
}

void    Contact::set_last_name(void)
{
    std::cout << GREEN << "Last name of the contact:" << RESET << std::endl;	
    while (1)
    {
		if (!std::getline(std::cin, last_name)) {
			std::cin.clear();
            clearerr(stdin);
            continue;
		}
        if (last_name.empty() || !isAlphabetic(last_name) || is_whiteLine(last_name))
            std::cout << RED << "Please enter a valid last name:" << RESET << std::endl;
        else {
            last_name = ft_strTrim(last_name);
            break;
        }
    }
}

void    Contact::set_nickname(void)
{
    std::cout << GREEN << "Nickname for the contact:" << RESET << std::endl;	
    while (1)
    {
		if (!std::getline(std::cin, nickname)) {
			std::cin.clear();
            clearerr(stdin);
            continue;
		}
        if (nickname.empty() || is_whiteLine(nickname))
            std::cout << RED << "Please enter a valid nickname:" << RESET << std::endl;
        else {
            nickname = ft_strTrim(nickname);
            break;
        }
    }
}

void    Contact::set_phone_number(void)
{
    std::cout << GREEN << "Phone number of the contact:" << RESET << std::endl;	
    while (1)
    {
		if (!std::getline(std::cin, phone_number)) {
			std::cin.clear();
            clearerr(stdin);
            continue;
		}
        if (phone_number.empty() || !isDigit(phone_number) || is_whiteLine(phone_number))
            std::cout << RED << "Please enter a valid phone number:" << RESET << std::endl;
        else {
            phone_number = ft_strTrim(phone_number);
            break;
        }
    }
}

void    Contact::set_darkest_secret(void)
{
    std::cout << GREEN << "Darkest secret of the contact hmm well:" << RESET  << std::endl;	
    while (1)
    {
		if (!std::getline(std::cin, darkest_secret)) {
			std::cin.clear();
            clearerr(stdin);
            continue;
		}
        if (darkest_secret.empty() || is_whiteLine(darkest_secret))
            std::cout << RED << "Please enter the darkest secret:" << RESET << std::endl;
        else {
            darkest_secret = ft_strTrim(darkest_secret);
            break;
        }
    }
}

void	Contact::DisplayAll(int i, int *count)
{
    if (first_name.length() > 0){
        std::cout << std::setw(10) <<  i << "|";
        std::cout << std::setw(10) << ft_truncate(first_name) << "|";
        std::cout << std::setw(10) << ft_truncate(last_name) << "|";
        std::cout << std::setw(10) << ft_truncate(nickname) << "|" << std::endl;
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
        std::cout << RED << "There's no contact in index: " << RESET << index << std::endl;
}

Contact::Contact()
{
    // std::cout << "Contact is constructed\n";
}

Contact::~Contact()
{
    // std::cout << "Contact is deconstructed\n";
}
