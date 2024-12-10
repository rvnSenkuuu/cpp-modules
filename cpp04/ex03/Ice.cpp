/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:08:12 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/10 11:08:12 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(std::string type) : AMateria(type)
{
	std::cout << "Ice assignement constructor called" << std::endl;
}

Ice::Ice(Ice const &other)
{
	std::cout << "Ice copy assignement constructor called" << std::endl;
	*this = other;
}

Ice::~Ice(void)
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice	&Ice::operator=(Ice const &other)
{
	std::cout << "Ice copy assignement operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}

AMateria	*Ice::clone(void)
{
	AMateria	*materia = new Ice();

	return materia;
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoot an ice bolt at " << target.getName() << " *" << std::endl;
}