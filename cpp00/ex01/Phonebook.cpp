/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-21 16:19:47 by tkara2            #+#    #+#             */
/*   Updated: 2024-11-21 16:19:47 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
	this->_contact_index = 0;
}

Phonebook::~Phonebook(void)
{
}

void	Phonebook::display_contact(void)
{
	for (int i = 0; i < 8; i++)
	{
		std::cout << "Contact first name: " << contact[i].get_fname() << std::endl;
		std::cout << "Contact last name: " << contact[i].get_lname() << std::endl;
		std::cout << "Contact nickname: " << contact[i].get_nname() << std::endl;
		std::cout << "Contact phone number: " << contact[i].get_number() << std::endl;
		std::cout << "Contact secret: " << contact[i].get_secret() << std::endl;
	}
}

bool	Phonebook::add_contact(void)
{
	int	i = 0;
	if (!this->contact[i].create_contact())
		return false;
	return true;
}
