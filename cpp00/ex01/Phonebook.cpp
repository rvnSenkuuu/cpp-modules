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
	this->_contact_size = 0;
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

std::string	resize_contact_name(std::string name)
{
	size_t	len = name.length();

	if (len > 9)
		return name.substr(0, 9) + ".";
	return name;
}

bool	Phonebook::display_specific_contact(void)
{
	std::string	index;

	std::cout << "Enter the index of the contact (1, " << this->_contact_size << "): ";
	while (index.empty())
	{
		std::getline(std::cin, index);
		if (std::cin.eof()) return false;
	}
	int i = std::atoi(index.c_str());
	if (i < 1 || i > this->_contact_size)
	{
		std::cout << "Didn't find a contact with the given index" << std::endl;
		return false;
	}
	else
	{
		std::cout << "Contact [" << i << "] First name: " << contact[i - 1].get_fname() << std::endl;
		std::cout << "Contact [" << i << "] Last name: " << contact[i - 1].get_lname() << std::endl;
		std::cout << "Contact [" << i << "] Nickname: " << contact[i - 1].get_nname() << std::endl;
		std::cout << "Contact [" << i << "] Phone number: " << contact[i - 1].get_number() << std::endl;
		std::cout << "Contact [" << i << "] Deepest secret: " << contact[i - 1].get_secret() << std::endl;
	}
	return true;
}

void	Phonebook::display_contact(void)
{
	std::string	fname, lname, nname;

	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|   index  |  f_name  |  l_name  |  n_name  |" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	for (int i = 0; i < this->_contact_size; i++)
	{
		fname = resize_contact_name(contact[i].get_fname());
		lname = resize_contact_name(contact[i].get_lname());
		nname = resize_contact_name(contact[i].get_nname());
		std::cout << "|" << std::setw(10) << i + 1;
		std::cout << "|" << std::setw(10) << fname;
		std::cout << "|" << std::setw(10) << lname;
		std::cout << "|" << std::setw(10) << nname << "|";
		std::cout << std::endl;
		std::cout << "|-------------------------------------------|" << std::endl;
	}
	if (!display_specific_contact()) return;
}

bool	Phonebook::add_contact(void)
{
	if (this->_contact_size == MAX_CONTACT)
		this->_contact_index = get_contact_index() % MAX_CONTACT;
	if (!this->contact[this->_contact_index].create_contact())
		return false;
	this->_contact_index++;	
	if (this->_contact_size < MAX_CONTACT)
		this->_contact_size++;	
	return true;
}