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

static void	print_exit(void)
{
	std::cout << "Exiting Phonebook" << std::endl;
}

int	main(void)
{
	std::string	line;
	Phonebook	book;

	print_welcome();
	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, line);
		if (std::cin.eof())
			break;
		if (line == "EXIT")
		{
			print_exit();
			return EXIT_SUCCESS;
		}
		if (line == "ADD" && !book.add_contact())
			break;
		if (line == "SEARCH" && !book.display_contact())
			break;
	}
	std::cout << std::endl;
	print_exit();
	return EXIT_SUCCESS;
}