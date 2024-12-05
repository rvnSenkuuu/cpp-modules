/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:32:49 by tkara2            #+#    #+#             */
/*   Updated: 2024/11/30 17:32:49 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Fixed	area(Point const a, Point const b, Point const c)
{
    Fixed area = (Fixed(1) / Fixed(2)) * 
                    		((a.getX() * (b.getY() - c.getY())) + 
                             (b.getX() * (c.getY() - a.getY())) + 
                             (c.getX() * (a.getY() - b.getY())));

	if (area < 0)
		return area * Fixed(-1);
	return area;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	area_abc = area(a, b, c);
	Fixed	area_abp = area(a, b, point);
	Fixed	area_bcp = area(b, c, point);
	Fixed	area_acp = area(a, c, point);

	if (area_abc == 0 || area_bcp == 0 || area_acp == 0)
		return false;
	if ((area_abp + area_bcp + area_acp) <= area_abc)
		return true;
	return false;
}