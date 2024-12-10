/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:03:08 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/10 11:03:08 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

# include <iostream>

class	AMateria;

class	ICharacter
{
	public:
		virtual ~ICharacter(void) {}

		virtual std::string const	&getName() const = 0;

		virtual void	equip(AMateria *m) = 0;
		virtual void	unequip(int i) = 0;
		virtual void	use(int i, ICharacter &target) = 0;
};

#endif