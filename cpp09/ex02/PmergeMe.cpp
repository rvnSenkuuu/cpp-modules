/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:15:55 by tkara2            #+#    #+#             */
/*   Updated: 2025/01/06 11:06:41 by tkara2           ###   ########.fr       */
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
	{
		this->_deqData = other._deqData;
		this->_vecData = other._vecData;
	}
	return *this;
}

std::deque<int>	PmergeMe::getDeque(void) const
{
	return this->_deqData;
}

std::vector<int>	PmergeMe::getVector(void) const
{
	return this->_vecData;
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
		this->_deqData.push_back(value);
		this->_vecData.push_back(value);
	}
}