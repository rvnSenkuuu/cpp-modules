/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:19:57 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/09 14:19:57 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	std::cout << "WrongCat assignement constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &other)
{
	std::cout << "WrongCat copy assignement constructor called" << std::endl;
	*this = other;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &other)
{
	std::cout << "WrongCat copy assignement operator called" << std::endl;
	if (this != &other)
		*this = other;
	return *this;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Miaou miaou miaou" << std::endl;
}