/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:34:53 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/20 13:34:53 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
	std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::Serializer(Serializer const &other)
{
	std::cout << "Serializer copy assignement contructor called" << std::endl;
	*this = other;
}

Serializer::~Serializer(void)
{
	std::cout << "Serializer destructor called" << std::endl;
}

Serializer	&Serializer::operator=(Serializer const &other)
{
	std::cout << "Serializer copy assignement operator called" << std::endl;
	if (this != &other)
		*this = other;
	return *this;
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	(void)ptr;
	std::cout << "Serializer function called" << std::endl;
	return 0;
}