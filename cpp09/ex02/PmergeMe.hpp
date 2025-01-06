/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:15:14 by tkara2            #+#    #+#             */
/*   Updated: 2025/01/06 11:10:01 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <iostream>
# include <cstdlib>
# include <cstring>
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

		std::deque<int>	getDeque(void) const;
		std::vector<int>	getVector(void) const;

		void	checkArg(int argc, char **argv);
		void	loadArg(int argc, char **argv);

	private:
		PmergeMe(void);
		PmergeMe(PmergeMe const &other);
		PmergeMe	&operator=(PmergeMe const &other);

	private:
		std::deque<int>	_deqData;
		std::vector<int>	_vecData;
};

#endif