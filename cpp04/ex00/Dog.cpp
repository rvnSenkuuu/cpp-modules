/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:29:00 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/09 13:29:00 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << "Dog assignement constructor called" << std::endl;
}

Dog::Dog(Dog const &other)
{
	std::cout << "Dog copy assignement constructor called" << std::endl;
	*this = other;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &other)
{
	std::cout << "Dog copy assignement operator called" << std::endl;
	if (this != &other)
		*this = other;
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof woof woof" << std::endl;
}