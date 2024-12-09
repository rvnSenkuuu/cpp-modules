/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:28:59 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/09 13:28:59 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Cat assignement constructor called" << std::endl;
}

Cat::Cat(Cat const &other)
{
	std::cout << "Cat copy assignement constructor called" << std::endl;
	*this = other;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &other)
{
	std::cout << "Cat copy assignement operator called" << std::endl;
	if (this != &other)
		*this = other;
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "Miaou miaou miaou" << std::endl;
}