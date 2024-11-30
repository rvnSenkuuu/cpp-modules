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

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

Point::Point(const Point &other) : _x(other.get_x()), _y(other.get_y())
{
}

Point::~Point()
{
}

Point	&Point::operator=(Point const &other)
{
	(void)other;
	return *this;
}

Fixed const	&Point::get_x(void) const
{
	return this->_x;
}

Fixed const	&Point::get_y(void) const
{
	return this->_y;
}