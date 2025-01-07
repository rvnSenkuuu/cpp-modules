/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:15:14 by tkara2            #+#    #+#             */
/*   Updated: 2025/01/07 17:15:44 by tkara2           ###   ########.fr       */
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

class	PmergeMe
{
	public:
		PmergeMe(int argc, char **argv);
		~PmergeMe(void);

		void	checkArg(int argc, char **argv);
		void	loadArg(int argc, char **argv);
		void	FordJohnsonSort(int argc);

		void	mergeInsertionVec(std::vector<int>::iterator begin, std::vector<int>::iterator end);


	private:
		PmergeMe(void);
		PmergeMe(PmergeMe const &other);
		PmergeMe	&operator=(PmergeMe const &other);

		VecIt	binarysearch(VecIt begin, VecIt end, int value);
		std::vector<int>	genJacobsthalSeq(int n);
		std::vector<int>	genInsertionPos(int n);

	private:
		std::vector<int>	_vecData;
};

#endif