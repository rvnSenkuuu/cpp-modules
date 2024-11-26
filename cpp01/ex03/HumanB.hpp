/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:13:09 by tkara2            #+#    #+#             */
/*   Updated: 2024/11/26 15:13:09 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

# include "main.h"

class	HumanB
{
	public:
		HumanB(std::string name);
		~HumanB();
	void	setWeapon(Weapon &weapon);

	void	attack(void);
	private:
		std::string	_name;
		Weapon		*_weapon;
};

#endif