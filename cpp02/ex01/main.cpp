/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:44:29 by tkara2            #+#    #+#             */
/*   Updated: 2024/11/29 10:44:29 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed	a;
	Fixed	const b(10);
	Fixed	const c(42.42f);
	Fixed	const d(b);
	
	a = Fixed(1234.4321f);
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.to_int() << " as integer" << std::endl;
	std::cout << "b is " << b.to_int() << " as integer" << std::endl;
	std::cout << "c is " << c.to_int() << " as integer" << std::endl;
	std::cout << "d is " << d.to_int() << " as integer" << std::endl;
	return 0;
}