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

#include <iostream>
#include <string>
#include <fcntl.h>
#include <fstream>
#include "Sed.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4) {
		std::cout << "Please pass <filename>, s1 and s2" << std::endl;
		return 1;
	}

	Sed	replacer(argv[1], argv[2], argv[3]);
	if (!replacer.manageFiles())
		return 1;
	replacer.replace();

	return 0;
}
