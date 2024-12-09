/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:38:47 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/09 15:38:47 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < MAX_IDEAS_COUNT; i++)
		this->_ideas[i] = "* Something the humans can't comprehend *";
}

Brain::Brain(std::string ideas)
{
	std::cout << "Brain assignement constructor called" << std::endl;
	for (int i = 0; i < MAX_IDEAS_COUNT; i++)
		this->_ideas[i] = ideas;
}

Brain::Brain(Brain const &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain	&Brain::operator=(Brain const &other)
{
	std::cout << "Brain copy assignement operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < MAX_IDEAS_COUNT; i++)
			this->_ideas[i] = other._ideas[i];
	}
	return *this;
}

std::string	Brain::getIdeas(unsigned int i) const
{
	return this->_ideas[i];
}