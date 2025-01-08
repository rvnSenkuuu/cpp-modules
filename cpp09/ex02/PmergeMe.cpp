/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:15:55 by tkara2            #+#    #+#             */
/*   Updated: 2025/01/08 10:25:52 by tkara2           ###   ########.fr       */
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

void	PmergeMe::FordJohnsonSort(int argc)
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

std::vector<int>	PmergeMe::genJacobsthalSeq(int n)
{
	std::vector<int>	seq;

	if (n == 0) return seq;
	seq.push_back(0);
	if (n == 1) return seq;
	seq.push_back(1);

	int	i = 2;
	while (seq.back() <= n)
	{
		int	value = seq[i - 1] + 2 * seq[i - 2];
		if (value > n) break;
		seq.push_back(value);
		++i;
	}
	return seq;
}

std::vector<int>	PmergeMe::genInsertionPos(int n)
{
	std::vector<int>	jacobseq = genJacobsthalSeq(n);
	std::vector<int>	pos;

	if (n == 0) return pos;
	pos.push_back(1);
	if (n == 1) return pos;
	
	for (size_t i = 1; i < jacobseq.size(); i++)
	{
		if (jacobseq[i] > pos.back())
		{
			int	tmp = jacobseq[i - 1];
			pos.push_back(jacobseq[i]);
			for (int j = jacobseq[i] - 1; j > tmp; j--)
				pos.push_back(j);
		}
	}

	for (int i = n; i > jacobseq.back(); i--)
		pos.push_back(i);

	return pos;
}

VecIt	PmergeMe::binarysearch(VecIt begin, VecIt end, int value)
{
	while (begin != end)
	{
		VecIt	mid = begin + (end - begin) / 2;
		
		if (*mid == value) return mid;
		if (*mid < value) begin = ++mid;
		else end = mid;
	}
	return begin;
}

void	PmergeMe::mergeInsertionVec(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (std::distance(begin, end) <= 1) return;

	VecIt	it = begin;
	std::vector<int>	leftover;
	std::vector<std::pair<int, int> >	pair;
	while (std::distance(it, end) >= 2)
	{
		int	first = *(it++);
		int	second = *(it++);

		if (first > second)
			std::swap(first, second);
		pair.push_back(std::make_pair(first, second));
	}
	if (it != end) leftover.push_back(*it);

	std::vector<int>	 mainChain;
	for (VecPairIt pairIt = pair.begin(); pairIt != pair.end(); pairIt++)
		mainChain.push_back(pairIt->second);

	if (mainChain.size() >= 2)
		mergeInsertionVec(mainChain.begin(), mainChain.end());
	
	std::vector<int>	pending;
	for (VecIt	it = mainChain.begin(); it != mainChain.end(); it++)
	{
		for (VecPairIt	pairIt = pair.begin(); pairIt != pair.end(); pairIt++)
		{
			if (*it == pairIt->second)
			{
				pending.push_back(pairIt->first);
				break;
			}
		}
	}

	std::vector<int>	indexPos = genInsertionPos(pending.size());
	for (size_t i = 0; i < indexPos.size(); i++)
	{
		VecIt	pendIt = pending.begin();
		if (indexPos[i] == 1) mainChain.insert(mainChain.begin(), *pendIt);
		else
		{
			std::advance(pendIt, indexPos[i] - 1);
			int	value;
			for (VecPairIt it = pair.begin(); it != pair.end(); it++)
			{
				if (it->first == *pendIt)
				{
					value = it->second; 
					break;
				}
			}
			VecIt	endIndex;
			for (endIndex = mainChain.begin(); endIndex != mainChain.end(); endIndex++)
				if (*endIndex == value) break;
			VecIt	pos = binarysearch(mainChain.begin(), endIndex, *pendIt);
			mainChain.insert(pos, *pendIt);
		}
	}

	if (!leftover.empty())
	{
		VecIt	posLast = binarysearch(mainChain.begin(), mainChain.end(), *leftover.begin());
		mainChain.insert(posLast, *leftover.begin());
	}
	std::copy(mainChain.begin(), mainChain.end(), begin);
}