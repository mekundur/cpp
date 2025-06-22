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
	int	N = 5;
	Zombie	*ptr;
	ptr = zombieHorde(N, "Mertcan");
	
	for (int i = 0; i < N; i++){
        std::cout << i << " " << &ptr[i] << " ";
        ptr[i].announce();
	}
	delete[] ptr;
	return (0);
}