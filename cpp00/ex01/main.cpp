/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-21 16:27:11 by tkara2            #+#    #+#             */
/*   Updated: 2024-11-21 16:27:11 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "phonebook.hpp"

void	display_new_contact(Contact new_contact)
{
	std::cout << "New contact first name: " << new_contact.get_fname() << std::endl;
	std::cout << "New contact last name: " << new_contact.get_lname() << std::endl;
	std::cout << "New contact nickname: " << new_contact.get_nname() << std::endl;
	std::cout << "New contact phone number: " << new_contact.get_number() << std::endl;
	std::cout << "New contact secret: " << new_contact.get_secret() << std::endl;
}

void	Phonebook::add_contact(void)
{
	Contact	new_contact;
	std::string	f_name, l_name, n_name, number, secret;

	while (1)
	{
		std::cout << "Enter the first name: ";
		std::getline(std::cin, f_name);
		std::cout << "Enter the last name: ";
		std::getline(std::cin, l_name);
		std::cout << "Enter the nickname: ";
		std::getline(std::cin, n_name);
		std::cout << "Enter the phone number: ";
		std::getline(std::cin, number);
		std::cout << "Enter your deepest secret: ";
		std::getline(std::cin, secret);
		new_contact.set_fname(f_name);
		new_contact.set_lname(l_name);
		new_contact.set_nname(n_name);
		new_contact.set_number(number);
		new_contact.set_secret(secret);
	}
	display_new_contact(new_contact); //Debug
}

int	main(void)
{
	std::string	line;
	Phonebook	book;

	while (1)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, line);
		if (line.empty())
			return EXIT_FAILURE;
		if (line.compare("EXIT") == 0)
			break;
		if (line.compare("ADD") == 0)
			book.add_contact();
		if (line.compare("SEARCH") == 0)
			break;
	}
	return EXIT_SUCCESS;
}