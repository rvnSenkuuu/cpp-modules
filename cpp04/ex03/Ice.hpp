/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:08:12 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/10 11:08:12 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

# include "AMateria.hpp"

class	Ice : virtual public AMateria
{
	public:
		Ice(void);
		Ice(std::string type);
		Ice(Ice const &other);
		~Ice(void);
		Ice	&operator=(Ice const &other);

		void		use(ICharacter &target);
		AMateria	*clone(void);
};

#endif