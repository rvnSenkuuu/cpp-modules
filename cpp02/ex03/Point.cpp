/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:33:08 by tkara2            #+#    #+#             */
/*   Updated: 2024/11/30 17:33:08 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

Point::Point(const Point &other) : _x(other.getX()), _y(other.getY())
{
}

Point::~Point(void)
{
}

Point	&Point::operator=(Point const &other)
{
	(void)other;
	return *this;
}

Fixed const	&Point::getX(void) const
{
	return this->_x;
}

Fixed const	&Point::getY(void) const
{
	return this->_y;
}