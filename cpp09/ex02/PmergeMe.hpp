/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:15:14 by tkara2            #+#    #+#             */
/*   Updated: 2025/01/06 15:31:57 by tkara2           ###   ########.fr       */
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
# include <vector>
# include <deque>
# include <set>

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
		void	doFordJohnsonSort(int argc);

		void	mergeInsertionVec(std::vector<int>::iterator begin, std::vector<int>::iterator end);


	private:
		PmergeMe(void);
		PmergeMe(PmergeMe const &other);
		PmergeMe	&operator=(PmergeMe const &other);

	private:
		std::vector<int>	_vecData;
};

#endif