/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekundur <mekundur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:07:44 by mekundur          #+#    #+#             */
/*   Updated: 2025/05/22 18:35:28 by mekundur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::set_name(std::string str)
{
    name = str;
}

void	Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{
    // std::cout << name << " is constructed" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << name << " is destructed!" << std::endl;
}
