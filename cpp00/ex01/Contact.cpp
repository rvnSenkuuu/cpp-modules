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

bool	has_number(std::string number)
{
	for (size_t i = 0; i < number.length(); i++)
		if (std::isdigit(number[i]) == false) return false;
	return true;
}

std::string	trim_space(std::string& str)
{
	str.erase(0, str.find_first_not_of(' '));
	str.erase(str.find_last_not_of(' ') + 1);
	return str;
}

bool	Contact::create_contact(void)
{
	std::string	fname, lname, nname, number, secret;

	while (fname.empty())
	{
		std::cout << "Enter the first name: ";
		std::getline(std::cin, fname);
		if (std::cin.eof()) return false;
	}
	while (lname.empty())
	{
		std::cout << "Enter the last name: ";
		std::getline(std::cin, lname);
		if (std::cin.eof()) return false;
	}
	while (nname.empty())
	{
		std::cout << "Enter the nickname: ";
		std::getline(std::cin, nname);
		if (std::cin.eof()) return false;
	}
	while (number.empty())
	{
		std::cout << "Enter the phone number: ";
		std::getline(std::cin, number);
		if (has_number(number) == false)
		{
			std::cout << "Enter a valid phone number" << std::endl;
			number.clear();
			continue;
		}
		if (std::cin.eof()) return false;
	}
	while (secret.empty())
	{
		std::cout << "Enter the deepest secret: ";
		std::getline(std::cin, secret);
		if (std::cin.eof()) return false;
	}
	set_fname(trim_space(fname));
	set_lname(trim_space(lname));
	set_nname(trim_space(nname));
	set_number(number);
	set_secret(trim_space(secret));
	return true;
}
