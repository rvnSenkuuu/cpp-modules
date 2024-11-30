/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:33:08 by tkara2            #+#    #+#             */
/*   Updated: 2024/11/30 17:33:08 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

# include "Fixed.hpp"

class	Point
{
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &other);
		~Point();

		Point		&operator=(Point const &other);
		Fixed const	&get_x(void) const;
		Fixed const	&get_y(void) const;

	private:
		Fixed const	_x;
		Fixed const	_y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif