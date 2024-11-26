/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:12:27 by tkara2            #+#    #+#             */
/*   Updated: 2024/11/26 15:12:27 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

# include <iostream>

class	Weapon
{
	public:
		Weapon(std::string weapon);
		~Weapon();

		std::string	const &getType(void);
		void	setType(std::string type);
	private:
		std::string	_type;
};

#endif