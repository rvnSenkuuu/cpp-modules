/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:29:40 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/23 14:29:40 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.h"

int	main(void)
{
	size_t	size = 5;
	int		*int_array = new int[size];

	for (size_t i = 0; i < size; i++)
		int_array[i] = i;

	std::cout << "-----Before Iter(int)-----" << std::endl;
	displayArray(int_array, size);

	iter(int_array, size, addTen<int>);
	std::cout << std::endl;

	std::cout << "-----After Iter(int)-----" << std::endl;
	displayArray(int_array, size);
	std::cout << std::endl;

	std::string	str_array[MAX_SIZE] = 
	{
		"ceci ", "est ", "un ", "message ", "chiffrer"
	};

	std::cout << "-----Before Iter(str)-----" << std::endl;
	displayArray(str_array, MAX_SIZE);

	std::cout << std::endl;
	iter(str_array, MAX_SIZE, rot13<std::string>);

	std::cout << "-----After Iter(str)-----" << std::endl;
	displayArray(str_array, MAX_SIZE);

	delete[] int_array;
	return 0;
}