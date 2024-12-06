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
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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

static void	displayFragTrapInfo(FragTrap &fragtrap)
{
	std::cout << "---FragTrap Info---" << std::endl <<
				 "Name: " << fragtrap.getName() << std::endl <<
				 "Health: " << fragtrap.getHealth() << std::endl <<
				 "Energy: " << fragtrap.getEnergy() << std::endl <<
				 "Attack: " << fragtrap.getAttack() << std::endl;
}

static void	displayDiamondTrapInfo(DiamondTrap &diamondtrap)
{
	std::cout << "---DiamondTrap Info---" << std::endl <<
				 "Name: " << diamondtrap.getName() << std::endl <<
				 "Health: " << diamondtrap.getHealth() << std::endl <<
				 "Energy: " << diamondtrap.getEnergy() << std::endl <<
				 "Attack: " << diamondtrap.getAttack() << std::endl;
}

int	main(void)
{
	ClapTrap	clap("CL4P-TP");
	ScavTrap	scav("Tarkov");
	FragTrap	frag("Frag");
	DiamondTrap	diam("Diam's");

	displayClapTrapInfo(clap);
	displayScavTrapInfo(scav);
	displayFragTrapInfo(frag);
	displayDiamondTrapInfo(diam);

	scav.attack(clap.getName());
	clap.takeDamage(scav.getAttack());

	frag.attack(scav.getName());
	scav.takeDamage(frag.getAttack());

	diam.attack(frag.getName());
	frag.takeDamage(diam.getAttack());

	scav.guardGate();
	frag.highFivesGuys();
	diam.whoAmI();

	displayClapTrapInfo(clap);
	displayScavTrapInfo(scav);
	displayFragTrapInfo(frag);
	displayDiamondTrapInfo(diam);
	return 0;
}
