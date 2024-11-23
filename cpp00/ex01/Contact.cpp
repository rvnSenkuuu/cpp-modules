/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-21 16:11:27 by tkara2            #+#    #+#             */
/*   Updated: 2024-11-21 16:11:27 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void	Contact::set_fname(std::string str)
{
	this->_fname = str;
	return;
}

void	Contact::set_lname(std::string str)
{
	this->_lname = str;
	return;
}

void	Contact::set_nname(std::string str)
{
	this->_nname = str;
	return;
}

void	Contact::set_number(std::string str)
{
	this->_phone_number = str;
	return;
}

void	Contact::set_secret(std::string str)
{
	this->_secret = str;
	return;
}

std::string	Contact::get_fname(void) const
{
	return this->_fname;
}

std::string	Contact::get_lname(void) const
{
	return this->_lname;
}

std::string	Contact::get_nname(void) const
{
	return this->_nname;
}

std::string	Contact::get_number(void) const
{
	return this->_phone_number;
}

std::string	Contact::get_secret(void) const
{
	return this->_secret;
}

std::string	get_contact_info(int info)
{
	std::string	str;

	switch (info)
	{
		case FIRST_NAME:
			std::cout << "Enter the first name: ";
			break;
		case LAST_NAME:
			std::cout << "Enter the last name: ";
			break;
		case NICK_NAME:
			std::cout << "Enter the nickname: ";
			break;
		case NUMBER:
			std::cout << "Enter the phone number: ";
			break;
		case SECRET:
			std::cout << "Enter the deepest secret: ";
			break;
		default:
			break;
	}
	while (str.empty())
	{
		std::getline(std::cin, str);
		if (std::cin.eof())
			return NULL;
	}
	return str;
}

bool	Contact::create_contact(void)
{
	std::string	str;

	str = get_contact_info(FIRST_NAME);
	if (str.empty())
		return false;
	set_fname(str);

	str = get_contact_info(LAST_NAME);
	if (str.empty())
		return false;
	set_lname(str);

	str = get_contact_info(NICK_NAME);
	if (str.empty())
		return false;
	set_nname(str);

	str = get_contact_info(NUMBER);
	if (str.empty())
		return false;
	set_number(str);

	str = get_contact_info(SECRET);
	if (str.empty())
		return false;
	set_secret(str);

	return true;
}
