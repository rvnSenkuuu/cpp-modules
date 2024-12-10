/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:08:43 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/10 17:08:43 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < MAX_STOCK_MATERIA; i++)
		this->_stock[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
	std::cout << "MateriaSource copy assignement constructor called" << std::endl;
	*this = other;
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < MAX_STOCK_MATERIA; i++)
		if (this->_stock[i] != NULL)
			delete this->_stock[i];
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &other)
{
	std::cout << "MateriaSource copy assignement operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < MAX_STOCK_MATERIA; i++)
		{
			if (this->_stock[i] != NULL)
				delete this->_stock[i];
		}
		for (int i = 0; i < MAX_STOCK_MATERIA; i++)
			this->_stock[i] = other._stock[i]->clone();
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
	{
		std::cout << "Cannot learn the spell" << std::endl;
		return;
	}
	for (int i = 0; i < MAX_STOCK_MATERIA; i++)
	{
		if (!this->_stock[i])
		{
			this->_stock[i] = m;
			std::cout << "The spell " << m << " is stocked" << std::endl;
			return;
		}
	}
	delete m;
	m = NULL;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	if (type.compare("cure") || type.compare("ice"))
	{
		for (int i = 0; i < MAX_STOCK_MATERIA; i++)
		{
			if (this->_stock[i] && this->_stock[i]->getType() == type)
				return this->_stock[i]->clone();
		}
	}
	std::cout << "Didn't find the type. Ensure you write 'cure' or 'ice'." << std::endl;
	return NULL;
}