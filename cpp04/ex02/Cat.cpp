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

Cat::Cat(void) : AAnimal("Cat"), _brain(new Brain())
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string type) : AAnimal(type), _brain(new Brain())
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
	delete this->_brain;
}

Cat &Cat::operator=(Cat const &other)
{
	std::cout << "Cat copy assignement operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
		this->_brain = new Brain(*other._brain);
	}
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "Miaou miaou miaou" << std::endl;
}

void	Cat::tellIdea(void) const
{
	std::cout << _brain->getIdeas(42) << std::endl;
}