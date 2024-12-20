/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:20:12 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/20 13:20:12 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void)
{
	std::cout << "Data default constructor called" << std::endl;
	for (int i = 0; i < MAX_PERSON; i++)
	{
		this->_age[i] = 0;
		this->_name[i] = "Nameless";
		this->_address[i] = "Nowhere";
	}
}

Data::Data(std::string *name, std::string *address, unsigned int *age)
{
	std::cout << "Data assignement constructor called" << std::endl;
	for (int i = 0; i < MAX_PERSON; i++)
	{
		this->_age[i] = age[i];
		this->_name[i] = name[i];
		this->_address[i] = address[i];
	}
}

Data::Data(Data const &other)
{
	std::cout << "Data copy assignement constructor called" << std::endl;
	*this = other;
}

Data::~Data(void)
{
	std::cout << "Data destructor called" << std::endl;
}

Data	&Data::operator=(Data const &other)
{
	std::cout << "Data copy assignement operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < MAX_PERSON; i++)
		{
			this->_age[i] = other._age[i];
			this->_name[i] = other._name[i];
			this->_address[i] = other._address[i];
		}
	}
	return *this;
}

void	Data::printData(void) const
{
	for (int i = 0; i < MAX_PERSON; i++)
	{
		std::cout << "--------------------" << std::endl;
		std::cout << "Person [" << i << "] Data:" << std::endl;
		std::cout << "Name: " << this->_name[i] << std::endl;
		std::cout << "Age: " << this->_age[i] << std::endl;
		std::cout << "Address: " << this->_address[i] << std::endl;
	}
}