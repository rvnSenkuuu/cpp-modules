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

class	Fixed
{
	public:
		Fixed();
		Fixed(int const value);
		Fixed(Fixed const &src);
		~Fixed();

		Fixed	&operator=(Fixed const &other);

		void	set_raw_bits(int const raw);
		int		get_raw_bits(void) const;

	private:
		int					_value;
		static const int	_rawbits = 8;
};

#endif