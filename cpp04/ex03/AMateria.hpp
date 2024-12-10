/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:50:38 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/10 10:50:38 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class	AMateria
{
	public:
		AMateria(void);
		AMateria(std::string const &type);
		AMateria(AMateria const &other);
		virtual ~AMateria(void);
		AMateria	&operator=(AMateria const &other);

		std::string const	&getType(void) const;

		virtual void		use(ICharacter &target);
		virtual AMateria	*clone(void) = 0;

	protected:
		std::string	_type;
};

#endif