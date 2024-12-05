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

Fixed::Fixed(int const value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = (int)roundf(value * (1 << this->_rawbits));
}

Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = (float)roundf(value * (1 << this->_rawbits));
}

Fixed::Fixed(Fixed const &other) : _value(other._value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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

Fixed	&Fixed::operator=(Fixed const &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (*this != other)
		this->_value = other.getRawBits();
	return *this;
}

Fixed	Fixed::operator+(Fixed const &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(Fixed const &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed	Fixed::operator*(Fixed const &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(Fixed const &other) const
{
	if (other._value == 0)
		return 0;
	return Fixed(this->toFloat() / other.toFloat());
}

bool	Fixed::operator<(Fixed const &other) const
{
	return this->_value < other._value;
}

bool	Fixed::operator<=(Fixed const &other) const
{
	return this->_value <= other._value;
}

bool	Fixed::operator>(Fixed const &other) const
{
	return this->_value > other._value;
}

bool	Fixed::operator>=(Fixed const &other) const
{
	return this->_value >= other._value;
}

bool	Fixed::operator==(Fixed const &other) const
{
	return this->_value == other._value;
}

bool	Fixed::operator!=(Fixed const &other) const
{
	return this->_value != other._value;
}

Fixed	&Fixed::operator++(void)
{
	this->_value++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	_value++;
	return tmp;
}

Fixed	&Fixed::operator--(void)
{
	this->_value--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	_value--;
	return tmp;
}

Fixed	&Fixed::min(Fixed &lhs, Fixed &rhs)
{
	if (lhs > rhs)
		return rhs;
	return lhs;
}

Fixed	&Fixed::max(Fixed &lhs, Fixed &rhs)
{
	if (lhs > rhs)
		return lhs;
	return rhs;
}

const Fixed	&Fixed::min(Fixed const &lhs, Fixed const &rhs)
{
	if (lhs > rhs)
		return rhs;
	return lhs;
}

const Fixed	&Fixed::max(Fixed const &lhs, Fixed const &rhs)
{
	if (lhs > rhs)
		return lhs;
	return rhs;
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
