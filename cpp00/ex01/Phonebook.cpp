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

int	Phonebook::get_contact_index(void) const
{
	return this->_contact_index;
}

void	Phonebook::set_contact_index(int i)
{
	this->_contact_index = i;
}

void	Phonebook::display_contact(void)
{
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "| index | first name | last name | nickname |" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	for (int i = 0; i < this->_contact_index; i++)
	{
		std::cout << "|" << i + 1 << "|";
		std::cout << "|" << contact[i].get_fname() << "|";
		std::cout << "|" << contact[i].get_lname() << "|";
		std::cout << "|" << contact[i].get_nname() << "|";
		std::cout << std::endl;
	}
}

bool	Phonebook::add_contact(void)
{
	int	i = get_contact_index() % MAX_CONTACT;
	if (!this->contact[i].create_contact())
		return false;
	set_contact_index(++i);
	if (this->_contact_index > 8)
		return false;
	return true;
}
