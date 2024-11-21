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
		if (line == "EXIT")
			break;
		if (line == "ADD")
			book.add_contact();
		if (line == "SEARCH")
			book.display_contact();
	}
	std::cout << "Exiting Phonebook" << std::endl;
	return EXIT_SUCCESS;
}