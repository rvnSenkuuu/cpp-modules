/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:44:38 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/09 11:44:38 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <iostream>

class	Animal
{
	public:
		Animal(void);
		Animal(const std::string type);
		Animal(Animal const &other);
		virtual ~Animal(void);
		Animal	&operator=(Animal const &other);

		std::string	getType(void) const;

		virtual void	makeSound(void) const;
		virtual void	tellIdea(void) const;

	protected:
		std::string	_type;
};

#endif