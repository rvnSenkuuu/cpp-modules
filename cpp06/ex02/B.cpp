/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:28:27 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/21 18:28:27 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"

B::B(void)
{
	std::cout << "B default constructor called" << std::endl; 
}

B::~B(void)
{
	std::cout << "B destructor called" << std::endl; 
}

void	B::announce(void)
{
	std::cout << "It's B Class" << std::endl;
}