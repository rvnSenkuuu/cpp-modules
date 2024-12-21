/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:57:08 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/21 18:57:08 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	std::srand(std::time(0));
	int	random = 1 + (std::rand() % 3);

	switch (random)
	{
		case 1:
			return new A();
			break;
		case 2:
			return new B();
			break;
		case 3:
			return new C();
			break;
		default:
			break;
	}
	return new Base();
}

void	identify(Base *p)
{
	Base	*identify = dynamic_cast<A*>(p);

	if (identify)
		identify->announce();

	identify = dynamic_cast<B*>(p);
	if (identify)
		identify->announce();

	identify = dynamic_cast<C*>(p);
	if (identify)
		identify->announce();
}

void	identify(Base &p)
{
	try
	{
		A	&identify = dynamic_cast<A&>(p);
		identify.announce();
		return;
	}
	catch (const std::exception &e)
	{
	}

	try
	{
		B	&identify = dynamic_cast<B&>(p);
		identify.announce();
		return;
	}
	catch (const std::exception &e)
	{
	}

	try
	{
		C	&identify = dynamic_cast<C&>(p);
		identify.announce();
		return;
	}
	catch (const std::exception &e)
	{
	}
}