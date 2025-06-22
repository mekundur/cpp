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

#include "Zombie.hpp"

int	main(void)
{
	randomChump("foo");

	Zombie	*ptr;
	ptr = newZombie("boo");
	ptr->announce();
	delete ptr;
	return (0);
}