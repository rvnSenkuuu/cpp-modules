/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:11:06 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/15 18:11:06 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

# include <iostream>
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

# define MAX_REQUEST 3

class	Intern
{
	public:
		Intern(void);
		~Intern(void);

		int		getForm(const std::string userRequest) const;
		Form	*makeForm(const std::string &name, const std::string &target);
};

#endif