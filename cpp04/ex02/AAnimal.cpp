/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:44:38 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/09 11:44:38 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("Typeless")
{
	std::cout << "Animal default constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string type) : _type(type)
{
	std::cout << "Animal assignement constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}

AAnimal::~AAnimal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

AAnimal	&AAnimal::operator=(AAnimal const &other)
{
	std::cout << "Animal copy assignement operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}

std::string	AAnimal::getType(void) const
{
	return this->_type;
}

void	AAnimal::makeSound(void) const
{
	std::cout << "................" << std::endl;
}