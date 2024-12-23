/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:03:14 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/12 14:03:14 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class	AForm;

class	Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(Bureaucrat const &other);
		~Bureaucrat(void);
		Bureaucrat	&operator=(Bureaucrat const &other);

		int				getGrade(void) const;
		std::string		getName(void) const;

		void	incrementGrade(void);
		void	decrementGrade(void);
		void	signForm(AForm &form);
		void	executeForm(AForm const &form);
		class	GradeTooHighException;
		class	GradeTooLowException;

	private:
		int						_grade;
		const std::string		_name;
};

class	Bureaucrat::GradeTooHighException : public std::exception
{
	public:
		const char	*what(void) const throw();
};
class	Bureaucrat::GradeTooLowException : public std::exception
{
	public:
		const char	*what(void) const throw();
};

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &src);

#endif