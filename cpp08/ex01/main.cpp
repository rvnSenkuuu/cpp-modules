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

static void	testSpanAdd(void)
{
	try
	{
		Span	sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.displayData();
	}
	catch (const std::exception &e)
	{
		std::cerr << "testSpanAdd exception: " << e.what() << std::endl;
	}
}

static void	testSpanDistance(void)
{
	try
	{
		Span	sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest distance: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest distance: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "testSpanDistance exception: " << e.what() << std::endl;
	}
}

static void	testAddNTimes(unsigned int time)
{
	try
	{
		Span	sp = Span(10000);
		sp.addNTimes(time);
		sp.displayData();
	}
	catch (const std::exception &e)
	{
		std::cerr << "testAddNTimes exception: " << e.what() << std::endl;
	}
}

int	main(void)
{
	testSpanAdd();
	std::cout << "---------------" << std::endl;
	testSpanDistance();
	std::cout << "---------------" << std::endl;
	testAddNTimes(100);

	return 0;
}