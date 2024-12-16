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
		Form(const std::string &name, const int &sign, const int &exec);
		Form(Form const &other);
		~Form(void);
		Form	&operator=(Form const &other);
		
		void				setIsSigned(bool isSigned);
		bool				getIsSigned(void) const;
		int					getGradeSign(void) const;
		int					getGradeExecute(void) const;
		const std::string	getName(void) const;

		void	beSigned(Bureaucrat const &bureaucrat);
		class	GradeTooLowException;
		class	GradeTooHighException;
		class	FormAlreadySign;

	private:
		bool				_isSigned;
		const int			_gradeSign;
		const int			_gradeExecute;
		const std::string	_name;
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
class	Form::FormAlreadySign : public std::exception
{
	public:
		const char	*what(void) const throw();
};

std::ostream	&operator<<(std::ostream &os, Form const &src);

#endif