/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:58:34 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/05 16:58:34 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_name = "Nameless";
	this->_health = 100;
	this->_energy = 50;
	this->_attack = 20;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap assignement constructor called" << std::endl;
	this->_name = name;
	this->_health = 100;
	this->_energy = 50;
	this->_attack = 20;
}

ScavTrap::ScavTrap(ScavTrap const &other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	this->_name = other._name;
	this->_health = other._health;
	this->_energy = other._energy;
	this->_attack = other._attack;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &other)
{
	std::cout << "ScavTrap copy assignement operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_health = other._health;
		this->_energy = other._energy;
		this->_attack = other._attack;
	}
	return *this;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->getName() << " is now on Gate Keeper Mode" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_energy == 0 || this->_health == 0)
	{
		std::cout << "ScavTrap " << this->_name << " has no energy or health cannot attack" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target <<
				 ", causing " << this->_attack << " points of damage !" << std::endl;
	this->_energy--;
}