/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:14:08 by tkara2            #+#    #+#             */
/*   Updated: 2024/11/26 13:14:09 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int n, std::string name)
{
	Zombie	*horde = new Zombie[n];

	for (int i = 0; i < n; i++)
		horde[i].set_name(name);
	return horde;
}