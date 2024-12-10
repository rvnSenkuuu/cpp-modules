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

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

# include <iostream>

class	AAnimal
{
	public:
		AAnimal(void);
		AAnimal(const std::string type);
		AAnimal(AAnimal const &other);
		virtual ~AAnimal(void);
		AAnimal	&operator=(AAnimal const &other);

		std::string	getType(void) const;

		virtual void	makeSound(void) const;
		virtual void	tellIdea(void) const = 0;

	protected:
		std::string	_type;
};

#endif