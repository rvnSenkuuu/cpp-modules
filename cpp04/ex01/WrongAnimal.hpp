/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:19:57 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/09 14:19:57 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

# include <iostream>

class	WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const &other);
		virtual ~WrongAnimal(void);
		WrongAnimal	&operator=(WrongAnimal const &other);

		std::string	getType(void) const;

		void	makeSound(void) const;

	protected:
		std::string	_type;
};

#endif