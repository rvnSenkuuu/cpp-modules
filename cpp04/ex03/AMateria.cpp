/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:50:36 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/10 10:50:36 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : _type("Typeless")
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "AMateria assignement constructor called" << std::endl;
}

AMateria::AMateria(AMateria const &other)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = other;
}

AMateria	&AMateria::operator=(AMateria const &other)
{
	std::cout << "AMateria copy assignement operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const	&AMateria::getType(void) const
{
	return this->_type;
}

void	AMateria::use(ICharacter &target)
{
	(void)target;
	std::cout << "AMateria use function" << std::endl;
}