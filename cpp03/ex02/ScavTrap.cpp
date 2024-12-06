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
	this->setName("Nameless");
	this->setHealth(100);
	this->setEnergy(50);
	this->setAttack(20);
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap assignement constructor called" << std::endl;
	this->setName(name);
	this->setHealth(100);
	this->setEnergy(50);
	this->setAttack(20);
}

ScavTrap::ScavTrap(ScavTrap const &other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	this->setName(other.getName());
	this->setHealth(other.getHealth());
	this->setEnergy(other.getEnergy());
	this->setAttack(other.getAttack());
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
		this->setName(other.getName());
		this->setHealth(other.getHealth());
		this->setEnergy(other.getEnergy());
		this->setAttack(other.getAttack());
	}
	return *this;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->getName() << " is now on Gate Keeper Mode" << std::endl;
}