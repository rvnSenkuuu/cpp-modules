/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:01:57 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/12 14:01:57 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void	testCreateBureaucrat(std::string name, int grade)
{
	try
	{
		std::cout << "Trying to create Bureaucrat: " << std::endl <<
					 "Name: " << name << std::endl <<
					 "Grade: " << grade << std::endl;
		Bureaucrat	test(name, grade);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return;
	}
	std::cout << "Bureaucrat create successfully" << std::endl;
	return;
}

static void	testIncrementGrade(std::string name, unsigned int grade)
{
	Bureaucrat	test(name, grade);

	std::cout << test << std::endl;
	try
	{
		test.incrementGrade();
	}
	catch(std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return;
	}
	std::cout << "Bureaucrat's grade incremented successfully" << std::endl;
	std::cout << test << std::endl;
	return;
}

static void	testDecrementGrade(std::string name, unsigned int grade)
{
	Bureaucrat	test(name, grade);

	std::cout << test << std::endl;
	try
	{
		test.decrementGrade();
	}
	catch(std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return;
	}
	std::cout << "Bureaucrat's grade decremented successfully" << std::endl;
	std::cout << test << std::endl;
	return;
}

int	main(void)
{
	std::cout << "------------------------------" << std::endl;
	testCreateBureaucrat("Test1", -1);
	std::cout << "------------------------------" << std::endl;
	testCreateBureaucrat("Test2", 10);
	std::cout << "------------------------------" << std::endl;
	testCreateBureaucrat("Test3", 150);
	std::cout << "------------------------------" << std::endl;
	testIncrementGrade("Test4", 5);
	std::cout << "------------------------------" << std::endl;
	testIncrementGrade("Test5", 1);
	std::cout << "------------------------------" << std::endl;
	testDecrementGrade("Test6", 149);
	std::cout << "------------------------------" << std::endl;
	testDecrementGrade("Test7", 150);
	std::cout << "------------------------------" << std::endl;
	return 0;
}