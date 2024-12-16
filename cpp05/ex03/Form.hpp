/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:46:02 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/13 10:46:02 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	public:
		Form(void);
		Form(const std::string &name, const std::string &target, const int &sign, const int &exec);
		Form(Form const &other);
		virtual ~Form(void);
		Form	&operator=(Form const &other);
		
		virtual void				setIsSigned(bool isSigned);
		virtual bool				getIsSigned(void) const;
		virtual int					getGradeSign(void) const;
		virtual int					getGradeExecute(void) const;
		virtual const std::string	getName(void) const;
		virtual const std::string	getTarget(void) const;

		void			beSigned(Bureaucrat const &bureaucrat);
		void			checkForm(Bureaucrat const &bureaucrat) const;
		virtual void	execute(Bureaucrat const &executor) const;
		class	GradeTooLowException;
		class	GradeTooHighException;
		class	FormNotSigned;
		class	FormNotFound;

	private:
		bool				_isSigned;
		const int			_gradeSign;
		const int			_gradeExecute;
		const std::string	_name;
		const std::string	_target;
};

class	Form::GradeTooLowException : public std::exception
{
	public:
		const char	*what(void) const throw();
};
class	Form::GradeTooHighException : public std::exception
{
	public:
		const char	*what(void) const throw();
};
class	Form::FormNotSigned : public std::exception
{
	public:
		const char	*what(void) const throw();
};
class	Form::FormNotFound : public std::exception
{
	public:
		const char	*what(void) const throw();
};

std::ostream	&operator<<(std::ostream &os, Form const &src);

#endif