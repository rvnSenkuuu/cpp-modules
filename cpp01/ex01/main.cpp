/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:57:38 by tkara2            #+#    #+#             */
/*   Updated: 2024/11/26 10:57:39 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int		n = 10;
	Zombie	zombie_stack = Zombie("Zombie_stack");
	Zombie	*horde = zombieHorde(n, "Horde");

	zombie_stack.announce();
	for (int j = 0; j < n; j++)
		horde->announce();
	delete[] horde;
	return EXIT_SUCCESS;
}