/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:08:13 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/10 11:08:13 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class	Cure : virtual public AMateria
{
	public:
		Cure(void);
		Cure(std::string type);
		Cure(Cure const &type);
		~Cure(void);
		Cure	&operator=(Cure const &other);

		void		use(ICharacter &target);
		AMateria	*clone(void);
};

#endif