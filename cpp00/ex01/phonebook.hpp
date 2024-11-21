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

#include "contact.hpp"
#define CONTACT_NUMBER 8

class	Phonebook
{
	public:
		Phonebook(void);
		~Phonebook(void);
		void	add_contact(void);
	private:
		int	contact_index;
		Contact contact[CONTACT_NUMBER];
};

#endif