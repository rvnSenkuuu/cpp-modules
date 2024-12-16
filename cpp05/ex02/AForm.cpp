/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:46:01 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/13 10:46:01 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _isSigned(false),
					 _gradeSign(100),
					 _gradeExecute(100),
					 _name("Nameless"),
					 _target("Targetless")
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string &name, const std::string &target, const int &sign, const int &exec) : _isSigned(false),
																									 _gradeSign(sign),
																									 _gradeExecute(exec),
																									 _name(name),
																									 _target(target)
{
	std::cout << "AForm assignement constructor called" << std::endl;
	if (this->_gradeSign < 1 || this->_gradeExecute < 1)
		throw AForm::GradeTooHighException();
	else if (this->_gradeSign > 150 || this->_gradeExecute > 150)
		throw AForm::GradeTooLowException();;
}

AForm::AForm(AForm const &other) : _isSigned(other._isSigned),
								   _gradeSign(other._gradeSign),
								   _gradeExecute(other._gradeExecute),
								   _name(other._name),
								   _target(other._target)
{
	std::cout << "AForm copy assignement contructor called" << std::endl;
	*this = other;
}

AForm	&AForm::operator=(AForm const &other)
{
	std::cout << "AForm copy assignement operator called" << std::endl;
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

AForm::~AForm(void)
{
	std::cout << "AForm destructor called" << std::endl;
}

void	AForm::setIsSigned(bool isSigned)
{
	this->_isSigned = isSigned;
}

bool	AForm::getIsSigned(void) const
{
	return this->_isSigned;
}

int	AForm::getGradeSign(void) const
{
	return this->_gradeSign;
}

int	AForm::getGradeExecute(void) const
{
	return this->_gradeExecute;
}

const std::string	AForm::getName(void) const
{
	return this->_name;
}

const std::string	AForm::getTarget(void) const
{
	return this->_target;
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return "Grade too low";
}

const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return "Grade too high";
}

const char	*AForm::FormNotSigned::what(void) const throw()
{
	return "Form not signed";
}

std::ostream	&operator<<(std::ostream &os, AForm const &src)
{
	os << src.getName() << " bureaucrat, sign grade " << src.getGradeSign()
			<< ", execute grade " << src.getGradeExecute() << ", ";
	if (src.getIsSigned() == true)
		os << "AForm is signed";
	else
		os << "AForm is not signed";
	return os << std::endl;
}

void	AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (this->_isSigned == true)
	{
	    std::cout << "The form " << this->getName() << " is already signed !" << std::endl;
	    return;
	}
	if (bureaucrat.getGrade() > this->_gradeSign)
		throw AForm::GradeTooLowException();
	else
		this->_isSigned = true;
}

void	AForm::checkForm(Bureaucrat const &bureaucrat) const
{
	if (this->_isSigned != true)
		throw FormNotSigned();
	if (bureaucrat.getGrade() > this->_gradeExecute)
		throw GradeTooLowException();
}