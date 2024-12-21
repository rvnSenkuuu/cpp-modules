/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:26:20 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/21 18:26:20 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"

A::A(void)
{
	std::cout << "A default constructor called" << std::endl; 
}

A::~A(void)
{
	std::cout << "A destructor called" << std::endl; 
}

void	A::announce(void)
{
	std::cout << "It's A Class" << std::endl;
}