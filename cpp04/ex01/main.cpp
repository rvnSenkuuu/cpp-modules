/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:43:15 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/09 11:43:15 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define COUNT 10

int	main(void)
{
	const Animal		*animal = new Animal();
	const Animal		*troop[COUNT];

	for (unsigned int i = 0; i < COUNT; i++)
	{
		if (i < (COUNT / 2))
			troop[i] = new Dog();
		else
			troop[i] = new Cat();
	}
	for (unsigned int i = 0; i < COUNT; i++)
	{
		troop[i]->makeSound();
		troop[i]->tellIdea();
	}
	animal->tellIdea();

	for (unsigned int i = 0; i < COUNT; i++)
		delete troop[i];
	delete animal;
	return 0;
}