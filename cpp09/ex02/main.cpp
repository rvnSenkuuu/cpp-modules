/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:14:24 by tkara2            #+#    #+#             */
/*   Updated: 2025/01/03 15:36:11 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <set>

static void	checkArg(int argc, char **argv)
{
	if (argc <= 2)
		throw std::invalid_argument("Wrong argument number\n"
									"Usage: ./PmergeMe <args1>...<argsN>");

	for (int i = 1; i < argc; i++)
	{
		for (size_t j = 0; j < std::strlen(argv[i]); j++)
			if (!std::isdigit(argv[i][j]))
				throw std::invalid_argument("Non digit argument detected");
	}

	for (int i = 1; i < argc; i++)
	{
		long number = std::atol(argv[i]);
		if (number < 0 || number > std::numeric_limits<int>::max())
			throw std::invalid_argument("Negatif numbers are not handled");
	}

	std::set<std::string>	args;
	for (int i = 1; i < argc; i++)
	{
		if (!args.insert(argv[i]).second)
				throw std::invalid_argument("Same arguments are not handled");
	}
}

static void	printArg(int argc, char **argv)
{
	std::cout << "Before: ";
	for (int i = 1; i < argc; i++)
		std::cout << argv[i] << " ";
	std::cout << std::endl;
}

int	main(int argc, char **argv)
{
	try
	{
		checkArg(argc, argv);
		printArg(argc, argv);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}