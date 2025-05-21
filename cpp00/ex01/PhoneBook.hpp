/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekundur <mekundur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:01:48 by mekundur          #+#    #+#             */
/*   Updated: 2025/05/21 19:49:41 by mekundur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "crappy.hpp"

class	PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void	ADD(void);
		void	SEARCH(void);
		
	private:
		Contact contacts[8];
		int		index;
};

#endif
