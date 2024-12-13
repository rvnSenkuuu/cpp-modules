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
#include "Form.hpp"

static void	testCreatingForm(std::string name, int sign, int exec)
{
	try
	{
		Form	test(name, sign, exec);
		std::cout << "Form " << name << " created" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

static void	testSigningForm(Form &form, Bureaucrat &bureaucrat)
{
	try
	{
		Bureaucrat	test_bureaucrat(bureaucrat);
		Form	test_form(form);

		std::cout << "~~~~~~~~" << std::endl;
		test_bureaucrat.signForm(test_form);
		std::cout << test_bureaucrat;
		std::cout << test_form;
		std::cout << "~~~~~~~~" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

static void	testSigningFormIncrementing(Form &form, Bureaucrat &bureaucrat)
{
	try
	{
		Bureaucrat	test_bureaucrat(bureaucrat);
		Form	test_form(form);

		std::cout << "~~~~~~~~" << std::endl;
		test_bureaucrat.incrementGrade();
		test_bureaucrat.signForm(test_form);
		std::cout << test_bureaucrat;
		std::cout << test_form;
		std::cout << "~~~~~~~~" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

static void	testSigningFormDecrementing(Form &form, Bureaucrat &bureaucrat)
{
	try
	{
		Bureaucrat	test_bureaucrat(bureaucrat);
		Form	test_form(form);

		std::cout << "~~~~~~~~" << std::endl;
		test_bureaucrat.decrementGrade();
		test_bureaucrat.signForm(test_form);
		std::cout << test_bureaucrat;
		std::cout << test_form;
		std::cout << "~~~~~~~~" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

int	main(void)
{
	std::cout << "----------------------------------------" << std::endl;
	testCreatingForm("Test1", 1, 10);
	std::cout << "----------------------------------------" << std::endl;
	Bureaucrat	test2_b("Test2_Bureaucrat", 1);
	Form	test2_f("Test2_Form", 11, 10);
	testSigningForm(test2_f, test2_b);
	std::cout << "----------------------------------------" << std::endl;
	Bureaucrat	test3_b("Test3_Bureaucrat", 150);
	Form	test3_f("Test3_Form", 11, 150);
	testSigningFormIncrementing(test3_f, test3_b);
	std::cout << "----------------------------------------" << std::endl;
	Bureaucrat	test4_b("Test4_Bureaucrat", 149);
	Form	test4_f("Test4_Form", 11, 150);
	testSigningFormDecrementing(test4_f, test4_b);
	std::cout << "----------------------------------------" << std::endl;
	Bureaucrat	test5_b("Test5_Bureaucrat", 11);
	Form	test5_f("Test5_Form", 11, 9);
	testSigningFormIncrementing(test5_f, test5_b);
	std::cout << "----------------------------------------" << std::endl;
	Bureaucrat	test6_b("Test6_Bureaucrat", 148);
	Form	test6_f("Test6_Form", 11, 148);
	testSigningFormDecrementing(test6_f, test6_b);
	std::cout << "----------------------------------------" << std::endl;
	return 0;
}