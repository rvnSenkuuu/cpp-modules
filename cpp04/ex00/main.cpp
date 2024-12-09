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

int	main(void)
{
	const Animal	*a = new Animal();
	const Animal	*b = new Dog();
	const Animal	*c = new Cat();

	const WrongAnimal	*d = new WrongAnimal();
	const WrongAnimal	*e = new WrongCat();

	std::cout << "A type: " << a->getType() << std::endl;
	std::cout << "B type: " << b->getType() << std::endl;
	std::cout << "C type: " << c->getType() << std::endl;
	std::cout << "D type: " << d->getType() << std::endl;
	std::cout << "E type: " << e->getType() << std::endl;

	a->makeSound();
	b->makeSound();
	c->makeSound();
	d->makeSound();
	e->makeSound();

	delete a;
	delete b;
	delete c;
	delete d;
	delete e;
	return 0;
}