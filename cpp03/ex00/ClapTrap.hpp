/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:37:37 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/05 13:37:37 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <iostream>

# define MAX_HEALTH 10

class	ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &other);
		~ClapTrap(void);
		ClapTrap	&operator=(ClapTrap const &other);

		unsigned int	getAttack(void) const;
		unsigned int	getHealth(void) const;
		unsigned int	getEnergy(void) const;
		std::string		getName(void) const;

		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

	private:
		std::string		_name;
		unsigned int	_health;
		unsigned int	_energy;
		unsigned int	_attack;
};

#endif