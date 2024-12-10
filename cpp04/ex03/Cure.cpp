/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:08:13 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/10 11:08:13 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(std::string type) : AMateria(type)
{
	std::cout << "Cure assignement constructor called" << std::endl;
}

Cure::Cure(Cure const &other)
{
	std::cout << "Cure copy assignement constructor called" << std::endl;
	*this = other;
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure	&Cure::operator=(Cure const &other)
{
	std::cout << "Cure copy assignement operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}

AMateria	*Cure::clone(void)
{
	AMateria	*materia = new Cure();

	return materia;
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals's " << target.getName() << " wounds *" << std::endl;
}