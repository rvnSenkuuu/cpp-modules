/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:29:00 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/09 13:29:00 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class	Dog : public AAnimal
{
	public:
		Dog(void);
		Dog(std::string type);
		Dog(Dog const &other);
		~Dog(void);
		Dog	&operator=(Dog const &other);

		void	makeSound(void) const;
		void	tellIdea(void) const;

	private:
		Brain	*_brain;
};

#endif