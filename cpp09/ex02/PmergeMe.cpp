/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:15:55 by tkara2            #+#    #+#             */
/*   Updated: 2025/01/06 15:51:07 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	std::cout << "PmergeMe default constructor called" << std::endl; 
}

PmergeMe::PmergeMe(int argc, char **argv)
{
	std::cout << "PmergeMe assigmement constructor called" << std::endl;
	checkArg(argc, argv);
	loadArg(argc, argv);
}

PmergeMe::PmergeMe(PmergeMe const &other)
{
	std::cout << "PmergeMe copy assigment constructor called" << std::endl;
	*this = other;
}

PmergeMe::~PmergeMe(void)
{
	std::cout << "PmergeMe destructor called" << std::endl;
}

PmergeMe	&PmergeMe::operator=(PmergeMe const &other)
{
	std::cout << "PmergeMe copy assignement opearator called" << std::endl;
	if (this != &other)
		this->_vecData = other._vecData;
	return *this;
}

void	PmergeMe::checkArg(int argc, char **argv)
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
			throw std::invalid_argument("Negatif numbers or more than INT_MAX are not handled");
	}

	std::set<std::string>	args;
	for (int i = 1; i < argc; i++)
	{
		if (!args.insert(argv[i]).second)
				throw std::invalid_argument("Same arguments are not handled");
	}
}

void	PmergeMe::loadArg(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		long	value = std::atol(argv[i]);
		this->_vecData.push_back(value);
	}
}

void	PmergeMe::doFordJohnsonSort(int argc)
{
	displayData(this->_vecData, false);

	std::clock_t	vecStart = std::clock();
	mergeInsertionVec(this->_vecData.begin(), this->_vecData.end());
	std::clock_t	vecEnd = std::clock();

	displayData(this->_vecData, true);
	double	timeElapsed = 1000.0 * (vecEnd - vecStart) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector: " <<
				std::fixed << std::setprecision(2) << timeElapsed << "ms" << std::endl;
}

void	PmergeMe::mergeInsertionVec(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	//TODO
	(void)begin;
	(void)end;
}