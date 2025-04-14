/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekundur <mekundur@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:07:44 by mekundur          #+#    #+#             */
/*   Updated: 2025/04/14 16:27:17 by mekundur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.hpp"

int	main(void)
{
	PhoneBook myBook;
	myBook->contacts[0].first_name = "Mertcan";
	myBook->contacts[0].last_name = "Kunduraci";
	myBook->contacts[0].phone_number = 4915258437614;

}
