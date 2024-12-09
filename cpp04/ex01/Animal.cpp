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

#include "Animal.hpp"

Animal::Animal(void) : _type("Typeless")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string type) : _type(type)
{
	std::cout << "Animal assignement constructor called" << std::endl;
}

Animal::Animal(Animal const &other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal	&Animal::operator=(Animal const &other)
{
	std::cout << "Animal copy assignement operator called" << std::endl;
	if (this != &other)
		*this = other;
	return *this;
}

std::string	Animal::getType(void) const
{
	return this->_type;
}

void	Animal::makeSound(void) const
{
	std::cout << "................" << std::endl;
}

void	Animal::tellIdea(void) const
{
	std::cout << "None" << std::endl;
}