/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamonTrap.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:45:18 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/06 14:45:18 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	std::cout << "DiamonTrap default constructor called" << std::endl;
	this->_name = "Nameless";
	ClapTrap::_name = this->_name + "_clap_name";
	this->_health = FragTrap::getHealth();
	this->_energy = ScavTrap::getEnergy();
	this->_attack = FragTrap::getAttack();
}

DiamondTrap::DiamondTrap(std::string name)
{
	std::cout << "DiamonTrap assignement constructor called" << std::endl;
	this->_name = name;
	ClapTrap::_name = this->_name + "_clap_name";
	this->_health = FragTrap::getHealth();
	this->_energy = ScavTrap::getEnergy();
	this->_attack = FragTrap::getAttack();
}

DiamondTrap::DiamondTrap(DiamondTrap const &other)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	this->_name = other._name;
	ClapTrap::_name = other._name + "_clap_name";
	this->_health = other._health;
	this->_energy = other._energy;
	this->_attack = other._attack;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &other)
{
	std::cout << "DiamondTrap copy assignement operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		ClapTrap::_name = other._name + "_clap_name";
		this->_health = other._health;
		this->_energy = other._energy;
		this->_attack = other._attack;
	}
	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "---DiamondTrap---" << std::endl << 
				 "Name: " << this->_name << std::endl <<
				 "Clap_name: " << ClapTrap::getName() << std::endl;
}