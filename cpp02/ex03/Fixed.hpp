/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:44:29 by tkara2            #+#    #+#             */
/*   Updated: 2024/11/29 10:44:29 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	public:
		Fixed();
		Fixed(int const value);
		Fixed(float const value);
		Fixed(Fixed const &other);
		~Fixed();

		bool	operator<(Fixed const &other) const;
		bool	operator<=(Fixed const &other) const;
		bool	operator>(Fixed const &other) const;
		bool	operator>=(Fixed const &other) const;
		bool	operator==(Fixed const &other) const;
		bool	operator!=(Fixed const &other) const;
		Fixed	&operator=(Fixed const &other);
		Fixed	operator+(Fixed const &other) const;
		Fixed	operator-(Fixed const &other) const;
		Fixed	operator*(Fixed const &other) const;
		Fixed	operator/(Fixed const &other) const;
		Fixed	&operator++(void);
		Fixed	operator++(int value);
		Fixed	&operator--(void);
		Fixed	operator--(int value);

		static Fixed			&min(Fixed &lhs, Fixed &rhs);
		static const Fixed		&min(Fixed const &lhs, Fixed const &rhs);
		static Fixed			&max(Fixed &lhs, Fixed &rhs);
		static const Fixed		&max(Fixed const &lhs, Fixed const &rhs);

		void	setRawBits(int const raw);
		int		getRawBits(void) const;
		int		toInt(void) const;
		float	toFloat(void) const;

	private:
		int					_value;
		static const int	_rawbits = 8;
};

std::ostream	&operator<<(std::ostream &os, Fixed const &src);

#endif