/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:11:13 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/15 18:11:13 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
}

int	Intern::getForm(const std::string requestName) const
{
	std::string	request[MAX_REQUEST] = {
		"shrubbery request",
		"robotomy request",
		"presidential request"
	};

	for (int i = 0; i < MAX_REQUEST; i++)
		if (requestName == request[i])
			return i;
	return -1;
}

Form	*Intern::makeForm(const std::string &name, const std::string &target)
{
	int		request = getForm(name);
	Form	*form = NULL;

	switch (request)
	{
		case 0:
		{
			std::cout << "*******************" << std::endl;
			std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
			std::cout << "*******************" << std::endl;
			return form = new ShrubberyCreationForm(target);
		}
		case 1:
		{
			std::cout << "*******************" << std::endl;
			std::cout << "Intern creates RobotomyRequestForm" << std::endl;
			std::cout << "*******************"  << std::endl;
			return form = new RobotomyRequestForm(target);
		}
		case 2:
		{
			std::cout << "*******************" << std::endl;
			std::cout << "Intern creates PresidentialPardonForm" << std::endl;
			std::cout << "*******************" << std::endl;
			return form = new PresidentialPardonForm(target);
		}
		default:
			std::cout << "*******************" << std::endl;
			std::cout << "Error while creating Form make sure you requested one of those: " << std::endl
						<< "'shrubbery request'" << std::endl
						<< "'robotomy request'" << std::endl
						<< "'presidential request'" << std::endl;
			std::cout << "*******************" << std::endl;
			break;
	};
	throw Form::FormNotFound();
	return form;
}