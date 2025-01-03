/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:29:40 by tkara2            #+#    #+#             */
/*   Updated: 2025/01/03 11:38:43 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define MAX_VALUE 42

int	main(void)
{
	Array<int>	intTArray(MAX_VALUE);
	int			*intArray = new int[MAX_VALUE];

	for (int i = 0; i < MAX_VALUE; i++)
	{
		std::srand(std::time(NULL));
		int random = std::rand();
		intTArray[i] = random;
		intArray[i] = random;
	}

	try
	{
		checkArrayValue(intTArray, intArray, MAX_VALUE);
	}
	catch (const std::exception &e)
	{
		std::cerr << "CheckArrayValue: " << e.what() << std::endl;
	}

	try
	{
		intTArray[-1] = 42;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Attempted to access index -1: " << e.what() << std::endl;
	}

	try
	{
		intTArray[MAX_VALUE] = 42;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Attempted to access index " << MAX_VALUE << ": " << e.what() << std::endl;
	}

	delete[] intArray;
	return 0;
}
