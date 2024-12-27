/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 13:24:33 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/25 13:24:33 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void)
{
	std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int n)
{
	std::cout << "Span assignement constructor called" << std::endl;
	this->_size = n;
}

Span::Span(Span const &other)
{
	std::cout << "Span copy assignement constructor called" << std::endl;
	*this = other;
}

Span	&Span::operator=(Span const &other)
{
	std::cout << "Span copy assignement operator called" << std::endl;
	if (this != &other)
	{
		this->_size = other._size;
		this->_data = other._data;
	}
	return *this;
}

Span::~Span(void)
{
	std::cout << "Span destructor called" << std::endl;
}

void	Span::displayData(void) const
{
	std::vector<int>::const_iterator	it;
	
	std::cout << "----------" << std::endl;
	for (it = this->_data.begin(); it != this->_data.end(); it++)
		std::cout << "Data: " << *it << '\n';
	std::cout << "----------" << std::endl;
}

void	Span::addNumber(int n)
{
	if (this->_data.size() >= this->_size)
		throw std::length_error("Not enough space");
	this->_data.insert(this->_data.end(), n);
}

void	Span::addNTimes(unsigned int n)
{
	if (n > this->_size)
		throw std::out_of_range("The range is greater than the max size");

	std::srand(std::time(0));
	for (unsigned int i = 0; i < n; i++)
	{
		int random = std::rand();
		this->addNumber(random);
	}
}

int	Span::shortestSpan(void)
{
	if (this->_size <= 1)
		throw std::length_error("The size of data is 1 or below");

	int	res = INT_MAX;
	std::vector<int>::iterator	it1;
	std::vector<int>::iterator	it2;

	for (it1 = this->_data.begin(); it1 != this->_data.end(); it1++)
	{
		for (it2 = it1 + 1; it2 != this->_data.end(); it2++)
		{
			int tmp = std::abs(*it2 - *it1);
			if (tmp < res)
				res = tmp;
		}
	}
	return res;
}

int	Span::longestSpan(void)
{
	if (this->_size <= 1)
		throw std::length_error("The size of data is 1 or below");

	int	res = INT_MIN;
	std::vector<int>::iterator	it1;
	std::vector<int>::iterator	it2;

	for (it1 = this->_data.begin(); it1 != this->_data.end(); it1++)
	{
		for (it2 = it1 + 1; it2 != this->_data.end(); it2++)
		{
			int tmp = std::abs(*it2 - *it1);
			if (tmp > res)
				res = tmp;
		}
	}
	return res;
}