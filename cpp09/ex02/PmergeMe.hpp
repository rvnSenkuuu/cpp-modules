/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:15:14 by tkara2            #+#    #+#             */
/*   Updated: 2025/01/09 09:24:33 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <cstring>
# include <ctime>
# include <limits>
# include <algorithm>
# include <iterator>
# include <vector>
# include <deque>
# include <set>

typedef	std::vector<int>::iterator	VecIt;
typedef	std::vector<std::pair<int, int> >::iterator	VecPairIt;

typedef std::deque<int>::iterator	DeqIt;
typedef std::deque<std::pair<int, int> >::iterator	DeqPairIt;

template<typename T>
void	displayData(T data, bool verbose)
{
	typename T::iterator	it = data.begin();
	typename T::iterator	ite = data.end();

	if (verbose == false)
		std::cout << "Before: ";
	else
		std::cout << "After: ";
	for (; it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template<typename I>
I	binarysearch(I begin, I end, int value)
{
	while (begin != end)
	{
		I	mid = begin + (end - begin) / 2;
		if (*mid == value) return mid;
		if (*mid < value) begin = ++mid;
		else end = mid;
	}
	return begin;
}

class	PmergeMe
{
	public:
		PmergeMe(int argc, char **argv);
		~PmergeMe(void);

		void	checkArg(int argc, char **argv);
		void	loadArg(int argc, char **argv);
		void	FordJohnsonSort(int argc);

		void	mergeInsertionVec(VecIt begin, VecIt end);
		void	mergeInsertionDeq(DeqIt begin, DeqIt end);

	private:
		PmergeMe(void);
		PmergeMe(PmergeMe const &other);
		PmergeMe	&operator=(PmergeMe const &other);

		std::vector<int>	genJacobsthalSeqVec(int n);
		std::vector<int>	genInsertionPosVec(int n);

		std::deque<int>	genJacobsthalSeqDeq(int n);
		std::deque<int>	genInsertionPosDeq(int n);

	private:
		std::vector<int>	_vecData;
		std::deque<int>	_deqData;
};

#endif