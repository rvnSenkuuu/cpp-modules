/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:08:43 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/10 17:08:43 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

# define MAX_STOCK_MATERIA 4

# include <iostream>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

class	AMateria;

class	MateriaSource : virtual public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const &other);
		~MateriaSource(void);
		MateriaSource	&operator=(MateriaSource const &other);

		void		learnMateria(AMateria *m);
		AMateria	*createMateria(std::string const &type);

	private:
		AMateria	*_stock[MAX_STOCK_MATERIA];
};

#endif