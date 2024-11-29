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
	Zombie	zombie_stack = Zombie("Zombie_stack");
	Zombie	*zombie_heap = newZombie("Zombie_heap");

	zombie_stack.announce();
	zombie_heap->announce();
	randomChump("Zombie_randomChump");

	delete zombie_heap;
	return 0;
}