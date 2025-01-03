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

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value) : _value(value)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = (int)roundf(value * (1 << this->_rawbits));
}

Fixed::Fixed(float const value)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = roundf(value * (1 << this->_rawbits));
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this->_value != other._value)
		this->_value = other.getRawBits();
	return *this;
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

int	Fixed::toInt(void) const
{
	return this->_value / (1 << this->_rawbits);
}

float	Fixed::toFloat(void) const
{
	return (float)this->_value / (float)(1 << this->_rawbits);
}

std::ostream	&operator<<(std::ostream &os, Fixed const &src)
{
	return os << src.toFloat();
}