/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:38:47 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/09 15:38:47 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

# define MAX_IDEAS_COUNT 100

# include <iostream>

class	Brain
{
	public:
		Brain(void);
		Brain(std::string ideas);
		Brain(Brain const &other);
		~Brain(void);
		Brain	&operator=(Brain const &other);

		std::string	getIdeas(unsigned int i) const;

	protected:
		std::string	_ideas[MAX_IDEAS_COUNT];
};

#endif