/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:21:39 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/10 13:21:39 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

# define MAX_MATERIA 4
# define MAX_GROUND_MATERIA 42

class	Character : virtual public ICharacter
{
	public:
		Character(void);
		Character(std::string name);
		Character(Character const &other);
		virtual ~Character(void);
		Character	&operator=(Character const &other);

		void		equip(AMateria *m);
		void		unequip(int i);
		void		use(int i, ICharacter &target);
		std::string const	&getName(void) const;

	private:
		std::string	_name;
		AMateria	*_inventory[MAX_MATERIA];
		AMateria	*_ground[MAX_GROUND_MATERIA];
};

#endif