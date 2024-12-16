/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:03:14 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/12 14:03:14 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _grade(42), _name("Nameless")
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _grade(grade), _name(name)
{
	std::cout << "Bureaucrat assignement constructor called" << std::endl;
	if (this->_grade < 1)
		throw GradeTooHighException();
	if (this->_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _grade(other._grade), _name(other._name)
{
	std::cout << "Bureaucrat copy assignement constructor called" << std::endl;
	*this = other;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &other)
{
	std::cout << "Bureaucrat copy assignement operator called" << std::endl;
	if (this != &other)
	{
		this->_grade = other._grade;
		if (this->_grade < 1)
			throw GradeTooHighException();
		if (this->_grade > 150)
			throw GradeTooLowException();
	}
	return *this;
}

int	Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

std::string	Bureaucrat::getName(void) const
{
	return this->_name;
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Grade too low";
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Grade too high";
}

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &src)
{
	return os << src.getName() << ", bureaucrat grade " << src.getGrade();
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	this->_grade--;
}
void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	this->_grade++;
}