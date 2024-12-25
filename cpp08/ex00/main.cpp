/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 10:14:47 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/25 10:14:47 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"

// #define MAX_SIZE 10

static void	easyFindVector(const int &find)
{
	const int	maxSize = 10;
	std::vector<int>	data;

	for (int i = 0; i < maxSize; i++)
		data.push_back(i * 10);

	displayContainers(data);

	try
	{
		std::vector<int>::iterator	it = easyFind(data, find);
		std::cout << "Searching " << find << ": Found" << std::endl;
		std::cout << "Next iteration in vector: " << *++it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "easyFindVector exception: " << e.what() << std::endl;
	}
}

static void easyFindList(int &find)
{
	const int	maxSize = 10;
	std::list<int>	data;

	for (int i = 0; i < maxSize; i++)
		data.push_back(i * 10);
	
	displayContainers(data);
	try
	{
		std::list<int>::iterator it = easyFind(data, find);
		std::cout << "Searching " << find << ": Found" << std::endl;
		std::cout << "Next iteration in list: " << *++it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "easyFindList exception: " << e.what() << std::endl;
	}
}

int	main(void)
{
	int			find = 20;
	const int	&findConst = 20;

	easyFindVector(findConst);
	std::cout << "-------------------------" << '\n';
	easyFindList(find);
	return 0;
}