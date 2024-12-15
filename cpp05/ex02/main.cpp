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
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void	testShrubberyForm(Bureaucrat &bureaucrat, ShrubberyCreationForm &form)
{
	try
	{
		Bureaucrat	test_bureaucrat(bureaucrat);
		ShrubberyCreationForm	test_form(form);

		std::cout << "~~~~~~~~~~~" << std::endl;
		std::cout << test_bureaucrat;
		test_bureaucrat.signForm(test_form);
		test_bureaucrat.executeForm(test_form);
		std::cout << "~~~~~~~~~~~" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "testShrubberyForm exception: " << e.what() << std::endl;
		return;
	}
}

static void	testRobotomyForm(Bureaucrat &bureaucrat, RobotomyRequestForm &form)
{
	try
	{
		Bureaucrat	test_bureaucrat(bureaucrat);
		RobotomyRequestForm	test_form(form);

		std::cout << "~~~~~~~~~~~" << std::endl;
		std::cout << test_bureaucrat;
		test_bureaucrat.signForm(test_form);
		test_bureaucrat.executeForm(test_form);
		std::cout << "~~~~~~~~~~~" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "testRobotomyForm exception: " << e.what() << std::endl;
		return;
	}
}

static void	testPresidentialForm(Bureaucrat &bureaucrat, PresidentialPardonForm &form)
{
	try
	{
		Bureaucrat	test_bureaucrat(bureaucrat);
		PresidentialPardonForm	test_form(form);

		std::cout << "~~~~~~~~~~~" << std::endl;
		std::cout << test_bureaucrat;
		test_bureaucrat.signForm(test_form);
		test_bureaucrat.executeForm(test_form);
		std::cout << "~~~~~~~~~~~" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "testPresidentialForm exception: " << e.what() << std::endl;
		return;
	}
}

int	main(void)
{
	std::cout << "-------------------------------------" << std::endl;
	Bureaucrat	test1_b("Test1_Bureaucrat", 137);
	ShrubberyCreationForm	test1_f("Test1_Form");
	testShrubberyForm(test1_b, test1_f);
	std::cout << "-------------------------------------" << std::endl;
	Bureaucrat	test2_b("Test2_Bureaucrat", 15);
	RobotomyRequestForm	test2_f("Test2_Form");
	testRobotomyForm(test2_b, test2_f);
	std::cout << "-------------------------------------" << std::endl;
	Bureaucrat	test3_b("Test3_Bureaucrat", 1);
	PresidentialPardonForm	test3_f("Test3_Form");
	testPresidentialForm(test3_b, test3_f);
	return 0;
}