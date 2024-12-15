/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:07:57 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/14 19:07:57 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyForm", "Targetless", 72, 45)
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyForm", target, 72, 45)
{
	std::cout << "RobotomyRequestForm assignement constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(other)
{
	std::cout << "RobotomyRequestForm copy assignement constructor called" << std::endl;
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	std::cout << "RobotomyRequestForm copy assignement operator called" << std::endl;
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	this->checkForm(executor);

	std::cout << " * SOME DRILLING NOISE * " << std::endl;
	int	res = std::rand() % 2;

	if (res == 0)
		std::cout << this->getTarget() << " has been robotomized successfully !" << std::endl;
	else
		std::cout << "The robotomy of " << this->getTarget() << " failed !" << std::endl;
}