/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 10:25:29 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/25 10:25:29 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template<typename T>
typename T::iterator	easyFind(T &data, int &search)
{
	typename T::iterator	it = std::find(data.begin(), data.end(), search);

	if (it == data.end())
		throw std::out_of_range("No such value");
	return it;
}

template<typename T>
typename T::iterator	easyFind(T &data, const int &search)
{
	typename T::iterator	it = std::find(data.begin(), data.end(), search);

	if (it == data.end())
		throw std::out_of_range("No such value");
	return it;
}

template<typename T>
void	displayContainers(T &data)
{
	for (typename T::iterator it = data.begin(); it != data.end(); it++)
		std::cout << "Data: " << *it << '\n';
}

#endif