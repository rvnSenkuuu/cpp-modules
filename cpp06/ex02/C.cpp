/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:28:28 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/21 18:28:28 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"

C::C(void)
{
	std::cout << "C default constructor called" << std::endl; 
}

C::~C(void)
{
	std::cout << "C destructor called" << std::endl; 
}

void	C::announce(void)
{
	std::cout << "It's C Class" << std::endl;
}