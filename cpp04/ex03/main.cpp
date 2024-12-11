/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:50:19 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/10 10:50:19 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

int main(void)
{
	IMateriaSource	*src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());

	ICharacter	*me = new Character("ME");

	AMateria	*tmp;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("ice"); 
	me->equip(tmp);

	ICharacter	*ennemy = new Character("ENNEMY");

	std::cout << std::endl;
	std::cout << "------------------------" << std::endl;
	me->use(0, *ennemy);
	me->use(1, *ennemy);
	std::cout << "------------------------" << std::endl;

	std::cout << std::endl;
	std::cout << "------------------------" << std::endl;
	me->unequip(2);
	me->use(2, *ennemy);
	std::cout << "------------------------" << std::endl;
	std::cout << std::endl;

	delete ennemy;
	delete me;
	delete src;
	return 0;
}