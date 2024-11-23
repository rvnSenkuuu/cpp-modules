/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-21 15:58:11 by tkara2            #+#    #+#             */
/*   Updated: 2024-11-21 15:58:11 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <cstring>
# include "Contact.hpp"
# define MAX_CONTACT 8

class	Phonebook
{
	public:
		Phonebook(void);
		~Phonebook(void);
		bool	add_contact(void);
		void	display_contact(void);
		bool	display_specific_contact(void);
		int		get_contact_index(void) const;
		void	set_contact_index(int i);
	private:
		int	_contact_index;
		int	_contact_size;
		Contact contact[MAX_CONTACT];
};

#endif