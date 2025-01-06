/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 10:14:47 by tkara2            #+#    #+#             */
/*   Updated: 2025/01/06 13:26:07 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"

static void	easyFindVector(const int &find)
{
	const int	maxSize = 10;
	const int	tmp[maxSize] = {1, 2, 3, 10, 55, 65, 10, 99, 77, 10};
	std::vector<int>	data;

	for (int i = 0; i < maxSize; i++)
		data.push_back(tmp[i]);

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
	const int	tmp[maxSize] = {1, 2, 3, 10, 55, 65, 10, 99, 77, 10};
	std::list<int>	data;

	for (int i = 0; i < maxSize; i++)
		data.push_back(tmp[i]);
	
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
	int	findList = 10;
	const int	findVector = 99;

	easyFindVector(findVector);
	std::cout << "-------------------------" << '\n';
	easyFindList(findList);
	return 0;
}