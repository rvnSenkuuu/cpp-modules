/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 10:14:47 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/25 10:14:47 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	Span	sp = Span(5);

	try
	{
		// sp.fillRandomValue();
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return 1;
	}
	sp.displayData();
	std::cout << "Result shortestSpan: " << sp.shortestSpan() << std::endl;
	std::cout << "Result longestSpan: " << sp.longestSpan() << std::endl;

	return 0;
}