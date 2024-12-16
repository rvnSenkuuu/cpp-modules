/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:46:01 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/13 10:46:01 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _isSigned(false), _gradeSign(100), _gradeExecute(100), _name("Nameless")
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string &name, const int &sign, const int &exec) : _isSigned(false),
																		_gradeSign(sign),
																		_gradeExecute(exec),
																		_name(name)
{
	std::cout << "Form assignement constructor called" << std::endl;
	if (this->_gradeSign < 1 || this->_gradeExecute < 1)
		throw Form::GradeTooHighException();
	else if (this->_gradeSign > 150 || this->_gradeExecute > 150)
		throw Form::GradeTooLowException();;
}

Form::Form(Form const &other) : _isSigned(other._isSigned),
								_gradeSign(other._gradeSign),
								_gradeExecute(other._gradeExecute),
								_name(other._name)
{
	std::cout << "Form copy assignement contructor called" << std::endl;
	*this = other;
}

Form	&Form::operator=(Form const &other)
{
	std::cout << "Form copy assignement operator called" << std::endl;
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
}

void	Form::setIsSigned(bool isSigned)
{
	this->_isSigned = isSigned;
}

bool	Form::getIsSigned(void) const
{
	return this->_isSigned;
}

int	Form::getGradeSign(void) const
{
	return this->_gradeSign;
}

int	Form::getGradeExecute(void) const
{
	return this->_gradeExecute;
}

const std::string	Form::getName(void) const
{
	return this->_name;
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return "Grade too low";
}

const char	*Form::GradeTooHighException::what(void) const throw()
{
	return "Grade too high";
}

const char	*Form::FormAlreadySign::what(void) const throw()
{
	return "Form is already signed";
}

std::ostream	&operator<<(std::ostream &os, Form const &src)
{
	os << src.getName() << " bureaucrat, sign grade " << src.getGradeSign()
			<< ", execute grade " << src.getGradeExecute() << ", ";
	if (src.getIsSigned() == true)
		os << "form is signed";
	else
		os << "form is not signed";
	return os << std::endl;
}

void	Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (this->_isSigned == true)
		throw Form::FormAlreadySign();
	if (bureaucrat.getGrade() > this->_gradeSign)
		throw Form::GradeTooLowException();
	else
		this->_isSigned = true;
}