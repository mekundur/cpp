/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekundur <mekundur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:01:48 by mekundur          #+#    #+#             */
/*   Updated: 2025/05/21 19:50:53 by mekundur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "crappy.hpp"

class	Contact
{
	public:	
		void	set_first_name(void);
		void	set_last_name(void);
		void	set_nickname(void);
		void	set_phone_number(void);
		void	set_darkest_secret(void);
		void	DisplayAll(int i, int *count);
		void	DisplaySingle(int index);

		private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
};

#endif
