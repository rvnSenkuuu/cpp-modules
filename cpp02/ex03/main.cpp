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

#include "Point.hpp"

static void	test_case(Point &a, Point &b, Point &c, Point &p)
{
	bool	result;

	std::cout << "--Point A--" << std::endl <<
				 "x: " << a.get_x() << " y: " << a.get_y() << std::endl;
	std::cout << "--Point B--" << std::endl <<
				 "x: " << b.get_x() << " y: " << b.get_y() << std::endl;
	std::cout << "--Point C--" << std::endl <<
				 "x: " << c.get_x() << " y: " << c.get_y() << std::endl;
	std::cout << "--Point P--" << std::endl <<
				 "x: " << p.get_x() << " y: " << p.get_y() << std::endl;

	result = bsp(a, b, c, p);
	if (result)
		std::cout << "The point lies inside the triangle" << std::endl;
	else
		std::cout << "The point is outside or on the line of the triangle" << std::endl;
}

int	main(void) 
{
	Point	a(2, 1);
	Point	b(4, 3);
	Point	c(6, 1);

	Point	p1(4, 2);
	Point	p2(5, 2);
	Point	p3(2, 3);

	test_case(a, b, c, p1);
	std::cout << std::endl;
	test_case(a, b, c, p2);
	std::cout << std::endl;
	test_case(a, b, c, p3);
	return 0;
}