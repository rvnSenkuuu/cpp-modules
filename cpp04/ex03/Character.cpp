/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:21:39 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/10 13:21:39 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
	std::cout << "Character default constructor called" << std::endl;
	this->_name = "Nameless";
	for (int i = 0; i < MAX_MATERIA; i++)
		this->_inventory[i] = NULL;
	for (int i = 0; i < MAX_GROUND_MATERIA; i++)
		this->_ground[i] = NULL;
}

Character::Character(std::string name)
{
	std::cout << "Character assignement constructor called" << std::endl;
	this->_name = name;
	for (int i = 0; i < MAX_MATERIA; i++)
		this->_inventory[i] = NULL;
	for (int i = 0; i < MAX_GROUND_MATERIA; i++)
		this->_ground[i] = NULL;
}

Character::Character(Character const &other)
{
	std::cout << "Character copy assignement constructor called" << std::endl;
	*this = other;
}

Character::~Character(void)
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
	for (int i = 0; i < MAX_GROUND_MATERIA; i++)
	{
		if (this->_ground[i] != NULL)
			delete this->_ground[i];
	}
}

Character &Character::operator=(Character const &other)
{
	std::cout << "Character copy assignement operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < MAX_MATERIA; i++)
		{
			if (this->_inventory[i] != NULL)
				delete this->_inventory[i];
		}
		for (int i = 0; i < MAX_GROUND_MATERIA; i++)
		{
			if (this->_ground[i] != NULL)
				delete this->_ground[i];
		}
		this->_name = other._name;
		for (int i = 0; i < MAX_MATERIA; i++)
			this->_inventory[i] = other._inventory[i]->clone();
		for (int i = 0; i < MAX_GROUND_MATERIA; i++)
			this->_ground[i] = other._ground[i]->clone();
	}
	return *this;
}

std::string const	&Character::getName(void) const
{
	return this->_name;
}

void	Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout << "Error while trying to equip the spell" << std::endl;
		return;
	}
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (this->_inventory[i] == m)
		{
			std::cout << "This spell already exists, didn't add to the inventory" << std::endl;
			break;
		}
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m->clone();
			std::cout << "The spell at index " << i << " " << m->getType() <<
			 " is equipped" << std::endl;
			delete m;
			return;
		}
	}
	std::cout << this->_name << " can't equip the spell " << m->getType() << std::endl;
	delete m;
	m = NULL;
}

void	Character::unequip(int i)
{
	if (!this->_inventory[i])
	{
		std::cout << "There is no spell to unequip" << std::endl;
		return;
	}
	if (i > MAX_MATERIA || i < 0)
	{
		std::cout << "Spell index beyond the inventory capacity" << std::endl;
		return;
	}
	for (int j = 0; j < MAX_GROUND_MATERIA; j++)
	{
		if (!this->_ground[j])
		{
			this->_ground[j] = this->_inventory[i];
			this->_inventory[i] = NULL;
			std::cout << "The spell at index " << i << " " << this->_ground[j]->getType() <<
						 " is unequipped" << std::endl;
			return;
		}
	}
}

void	Character::use(int i, ICharacter &target)
{
	if (i < 0 || i >= 4)
	{
		std::cout << "Trying to use a spell at the wrong index" << std::endl;
		return;
	}
	if (this->_inventory[i] != NULL)
	{
		std::cout << this->getName() << " -> ";
		this->_inventory[i]->use(target);
	}
	else
		std::cout << "Didn't find a spell at this index" << std::endl;
}