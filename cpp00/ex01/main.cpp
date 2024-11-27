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
#include "Phonebook.hpp"

static void	print_welcome(void)
{
	std::cout << "Welcome to my Phonebook" << std::endl;
}

static void	print_command(void)
{
	std::cout << "Available commands:\n"
				 "[ADD]: Used for adding a new contact\n"
				 "[SEARCH]: Search for contacts in the phonebook\n"
				 "[HELP]: Show all available commands\n"
				 "[EXIT]: Quit Phonebook" << std::endl;
}

static void	print_exit(void)
{
	std::cout << "Exiting Phonebook" << std::endl;
}

int	main(void)
{
	std::string	line;
	Phonebook	book;

	print_welcome();
	print_command();
	while (true)
	{
		std::cout << "Enter a command > ";
		std::getline(std::cin, line);
		if (std::cin.eof())
			break;
		if (line == "EXIT")
		{
			print_exit();
			return 0;
		}
		if (line == "ADD" && !book.add_contact())
			break;
		if (line == "SEARCH" && !book.display_contact())
			break;
		if (line == "HELP")
			print_command();
	}
	std::cout << std::endl;
	print_exit();
	return 0;
}