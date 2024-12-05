/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:30:02 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/05 13:30:02 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

static void	displayClapTrapInfo(ClapTrap &claptrap)
{
	std::cout << "---ClapTrap Info---" << std::endl <<
				 "Name: " << claptrap.getName() << std::endl <<
				 "Health: " << claptrap.getHealth() << std::endl <<
				 "Energy: " << claptrap.getEnergy() << std::endl <<
				 "Attack: " << claptrap.getAttack() << std::endl;
}

static void	displayScavTrapInfo(ScavTrap &scavtrap)
{
	std::cout << "---ScavTrap Info---" << std::endl <<
				 "Name: " << scavtrap.getName() << std::endl <<
				 "Health: " << scavtrap.getHealth() << std::endl <<
				 "Energy: " << scavtrap.getEnergy() << std::endl <<
				 "Attack: " << scavtrap.getAttack() << std::endl;
}

int	main(void)
{
	ScavTrap	scav("Tarkov");
	ClapTrap	clap("CL4P-TP");
	ScavTrap	s(scav);

	scav.attack(clap.getName());
	clap.takeDamage(scav.getAttack());

	displayClapTrapInfo(clap);
	displayScavTrapInfo(scav);
	return 0;
}