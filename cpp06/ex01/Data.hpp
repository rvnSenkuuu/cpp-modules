/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:20:12 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/20 13:20:12 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

# include <iostream>

# define MAX_PERSON 5

class	Data
{
	public:
		Data(void);
		Data(std::string *name, std::string *address, unsigned int *age);
		Data(Data const &other);
		~Data(void);
		Data	&operator=(Data const &other);

		void	printData(void) const;

	private:
		unsigned int	_age[MAX_PERSON];
		std::string		_name[MAX_PERSON];
		std::string		_address[MAX_PERSON];
};

#endif