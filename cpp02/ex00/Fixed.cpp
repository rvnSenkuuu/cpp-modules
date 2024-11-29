/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:44:29 by tkara2            #+#    #+#             */
/*   Updated: 2024/11/29 10:44:29 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value) : _value(value)
{
	std::cout << "Copy assignment operator called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this->_value != other._value)
		this->_value = other.get_raw_bits();
	return *this;
}

void	Fixed::set_raw_bits(int const raw)
{
	this->_value = raw;
}

int	Fixed::get_raw_bits(void) const
{
	std::cout << "get_raw_bits member function called" << std::endl;
	return this->_value;
}

std::ostream	&operator<<(std::ostream &os, Fixed const &src)
{
	return os << src.get_raw_bits();
}