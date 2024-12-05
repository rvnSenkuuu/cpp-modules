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

static void	displayClapTrapInfo(ClapTrap &claptrap)
{
	std::cout << "---ClapTrap Info---" << std::endl <<
				 "Name: " << claptrap.getName() << std::endl <<
				 "Health: " << claptrap.getHealth() << std::endl <<
				 "Energy: " << claptrap.getEnergy() << std::endl <<
				 "Attack: " << claptrap.getAttack() << std::endl;
}

int	main(void)
{
	ClapTrap	a;
	ClapTrap	b("TEST");

	displayClapTrapInfo(a);
	displayClapTrapInfo(b);

	a = b;
	displayClapTrapInfo(a);
	for (int i = 0; i < 10; i++)
	{
		a.attack(b.getName());
		b.takeDamage(a.getAttack());
	}
	displayClapTrapInfo(b);
	for (int j = 0; j < 10; j++)
		b.beRepaired(1);
	displayClapTrapInfo(b);
	return 0;
}