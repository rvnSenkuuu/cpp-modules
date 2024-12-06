/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:08:31 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/06 11:08:31 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->setName("Nameless");
	this->setHealth(100);
	this->setEnergy(100);
	this->setAttack(30);
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap assignement constructor called" << std::endl;
	this->setName(name);
	this->setHealth(100);
	this->setEnergy(100);
	this->setAttack(30);
}

FragTrap::FragTrap(FragTrap const &other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	this->setName(other.getName());
	this->setHealth(other.getHealth());
	this->setEnergy(other.getEnergy());
	this->setAttack(other.getAttack());
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &other)
{
	std::cout << "FragTrap copy assignement operator called" << std::endl;
	if (this != &other)
	{
		this->setName(other.getName());
		this->setHealth(other.getHealth());
		this->setEnergy(other.getEnergy());
		this->setAttack(other.getAttack());	
	}
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->getName() << " request a high five (NOW!!!!)" << std::endl;
}