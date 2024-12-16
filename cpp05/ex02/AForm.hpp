/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:46:02 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/13 10:46:02 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	public:
		AForm(void);
		AForm(const std::string &name, const std::string &target, const int &sign, const int &exec);
		AForm(AForm const &other);
		virtual ~AForm(void);
		AForm	&operator=(AForm const &other);
		
		virtual void				setIsSigned(bool isSigned);
		virtual bool				getIsSigned(void) const;
		virtual int					getGradeSign(void) const;
		virtual int					getGradeExecute(void) const;
		virtual const std::string	getName(void) const;
		virtual const std::string	getTarget(void) const;

		void			beSigned(Bureaucrat const &bureaucrat);
		void			checkForm(Bureaucrat const &bureaucrat) const;
		virtual void	execute(Bureaucrat const &executor) const = 0;
		class	GradeTooLowException;
		class	GradeTooHighException;
		class	FormNotSigned;

	protected:
		bool				_isSigned;
		const int			_gradeSign;
		const int			_gradeExecute;
		const std::string	_name;
		const std::string	_target;
};

class	AForm::GradeTooLowException : public std::exception
{
	public:
		const char	*what(void) const throw();
};
class	AForm::GradeTooHighException : public std::exception
{
	public:
		const char	*what(void) const throw();
};
class	AForm::FormNotSigned : public std::exception
{
	public:
		const char	*what(void) const throw();
};

std::ostream	&operator<<(std::ostream &os, AForm const &src);

#endif