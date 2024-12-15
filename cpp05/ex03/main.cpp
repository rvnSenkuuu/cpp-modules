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
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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

static void	testInternRequest(Bureaucrat &bureaucrat, const std::string request, const std::string target)
{
	Intern		test_intern;
	Form		*test_form = NULL;
	Bureaucrat	test_bureaucrat(bureaucrat);
	try
	{
		test_form = test_intern.makeForm(request, target);
		test_form->beSigned(test_bureaucrat);
		test_bureaucrat.executeForm(*test_form);
		if (test_form != NULL)
			delete test_form;
	}
	catch (std::exception &e)
	{
		if (test_form != NULL)
			delete test_form;
		std::cerr << "testInternRequest exception: " << e.what() << std::endl;
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
	std::cout << "-------------------------------------" << std::endl;
	Bureaucrat	test4_b("Test4_Bureaucrat", 15);
	testInternRequest(test4_b, "shrubbery request", "Test4_Form");
	std::cout << "-------------------------------------" << std::endl;
	Bureaucrat	test5_b("Test5_Bureaucrat", 15);
	testInternRequest(test5_b, "robotomy request", "Test5_Form");
	std::cout << "-------------------------------------" << std::endl;
	Bureaucrat	test6_b("Test6_Bureaucrat", 1);
	testInternRequest(test6_b, "presidential request", "Test6_Form");
	std::cout << "-------------------------------------" << std::endl;
	Bureaucrat	test7_b("Test7_Bureaucrat", 1);
	testInternRequest(test7_b, "defaut request", "Test7_Form");
	std::cout << "-------------------------------------" << std::endl;
	return 0;
}