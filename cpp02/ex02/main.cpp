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
	std::cout << "---Constructor and copy---" << std::endl;
	Fixed	a;
	Fixed	b(5);
	Fixed	c(5.5f);
	Fixed	d(c);

	std::cout << "A: " << a << std::endl;
	std::cout << "B: " << b << std::endl;
	std::cout << "C: " << c << std::endl;
	std::cout << "D copy of B: " << d << std::endl;
	std::cout << std::endl;

	std::cout << "---Assignment operator---" << std::endl;
	a = Fixed(10.1f);
	std::cout << "A after assignment: " << a << std::endl;
	std::cout << std::endl;

	std::cout << "---Arithmetic operator---" << std::endl;
	std::cout << "A + B = " << a + b << std::endl;
	std::cout << "A - B = " << a - b << std::endl;
	std::cout << "A * B = " << a * b << std::endl;
	std::cout << "A / B = " << a / b << std::endl;
	std::cout << std::endl;

	std::cout << "---Comparison operator---" << std::endl;
	std::cout << "A > B : " << (a > b) << std::endl;
	std::cout << "A < B : " << (a < b) << std::endl;
	std::cout << "A >= B: " << (a >= b) << std::endl;
	std::cout << "A <= B: " << (a <= b) << std::endl;
	std::cout << "A == B: " << (a == b) << std::endl;
	std::cout << "A != B: " << (a != b) << std::endl;
	std::cout << std::endl;

	std::cout << "---PreIncrement/Decrement operator---" << std::endl;
	std::cout << "A: " << a << std::endl;
	std::cout << "A preincrement: " << ++a << std::endl;
	std::cout << "A: " << a << std::endl;
	std::cout << "A predecrement: " << --a << std::endl;
	std::cout << "A: " << a << std::endl;
	std::cout << std::endl;

	std::cout << "---PostIncrement/Decrement operator---" << std::endl;
	std::cout << "A: " << a << std::endl;
	std::cout << "A postincrement: " << a++ << std::endl;
	std::cout << "A: " << a << std::endl;
	std::cout << "A postdecrement: " << a-- << std::endl;
	std::cout << "A: " << a << std::endl;
	std::cout << std::endl;

	std::cout << "---Min/Max operator---" << std::endl;
	std::cout << "A: " << a << std::endl;
	std::cout << "B: " << b << std::endl;
	std::cout << "Min between A and B: " << Fixed::min(a, b) << std::endl;
	std::cout << "Max between A and B: " << Fixed::max(a, b) << std::endl;
	std::cout << std::endl;

	std::cout << "---Const Min/Max operator---" << std::endl;
	const Fixed	e(3.14f);
	const Fixed	f(6.28f);
	std::cout << "E: " << e << std::endl;
	std::cout << "F: " << f << std::endl;
	std::cout << "Min between E and F: " << Fixed::min(e, f) << std::endl;
	std::cout << "Max between E and F: " << Fixed::max(e, f) << std::endl;
	std::cout << std::endl;
	return 0;
}
