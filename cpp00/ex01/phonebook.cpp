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

#include "phonebook.hpp"

Phonebook::Phonebook(void)
{
	this->contact_index = 0;
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

void	Phonebook::add_contact(void)
{
	int	i = 0;
	std::string	line;

	if (i > 8)
	{
		std::cout << "For now not handling beyond 8 contacts" << std::endl;
		return;
	}
	line = "";
	while (line == "")
	{
		std::cout << "Enter the first name: ";
		std::getline(std::cin, line);
		this->contact[i].set_fname(line);
	}
	line = "";
	while (line == "")
	{
		std::cout << "Enter the last name: ";
		std::getline(std::cin, line);
		this->contact[i].set_lname(line);
	}
	line = "";
	while (line == "")
	{
		std::cout << "Enter the nickname: ";
		std::getline(std::cin, line);
		this->contact[i].set_nname(line);
	}
	line = "";
	while (line == "")
	{
		std::cout << "Enter the phone number: ";
		std::getline(std::cin, line);
		this->contact[i].set_number(line);
	}
	line = "";
	while (line == "")
	{
		std::cout << "Enter the deepest secret: ";
		std::getline(std::cin, line);
		this->contact[i].set_secret(line);
	}
	++i;
	if (std::cin.eof())
		return;
}
