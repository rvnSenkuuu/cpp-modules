/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:37:37 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/05 13:37:37 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_name = "Nameless";
	this->_health = 10;
	this->_energy = 10;
	this->_attack = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Assignement constructor called" << std::endl;
	this->_name = name;
	this->_health = 10;
	this->_energy = 10;
	this->_attack = 0;
}

ClapTrap::ClapTrap(ClapTrap const &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_name = other._name;
	this->_health = other._health;
	this->_energy = other._energy;
	this->_attack = other._attack;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Default destructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &other)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_health = other._health;
		this->_energy = other._energy;
		this->_attack = other._attack;
	}
	return *this;
}

unsigned int	ClapTrap::getHealth(void) const
{
	return this->_health;
}

unsigned int	ClapTrap::getEnergy(void) const
{
	return this->_energy;
}

unsigned int	ClapTrap::getAttack(void) const
{
	return this->_attack;
}

std::string	ClapTrap::getName(void) const
{
	return this->_name;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_energy == 0 || this->_health == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy or health cannot attack" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target <<
				 ", causing " << this->_attack << " points of damage !" << std::endl;
	this->_energy--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > this->_health)
		this->_health = 0;
	if (this->_health == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no health" << std::endl;
		return;
	}
	this->_health -= amount;
	std::cout << "ClapTrap " << this->_name << ": Health after taking damage: " << this->_health << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy cannot repair itself" << std::endl;
		return;
	}
	if (this->_health == MAX_HEALTH)
	{
		std::cout << "ClapTrap " << this->_name << " is full health" << std::endl;
		return;
	}
	this->_health += amount;
	this->_energy--;
	std::cout << "ClapTrap " << this->_name << ": Health after repairing: " << this->_health <<
				 ", Energy after repairing: " << this->_energy << std::endl;
}
