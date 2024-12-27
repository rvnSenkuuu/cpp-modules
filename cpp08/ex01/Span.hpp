/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 13:24:33 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/25 13:24:33 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

# include <climits>
# include <ctime>
# include <cmath>
# include <iostream>
# include <exception>
# include <algorithm>
# include <vector>

class	Span
{
	public:
		Span(unsigned int n);
		Span(Span const &other);
		~Span(void);
		Span	&operator=(Span const &other);

		void	addNTimes(unsigned int n);
		void	displayData(void) const;
		void	addNumber(int n);
		int		shortestSpan(void);
		int		longestSpan(void);

	private:
		Span(void);
		unsigned int		_size;
		std::vector<int>	_data;
};

#endif