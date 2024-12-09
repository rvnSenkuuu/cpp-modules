/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:28:59 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/09 13:28:59 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Cat : public Animal
{
	public:
		Cat(void);
		Cat(std::string type);
		Cat(Cat const &other);
		~Cat(void);
		Cat	&operator=(Cat const &other);

		void	makeSound(void) const;
		void	tellIdea(void) const;

	private:
		Brain	*_brain;
};

#endif