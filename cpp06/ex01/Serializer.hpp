/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:16:00 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/20 13:16:00 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

# include <stdint.h>
# include "Data.hpp"

class	Serializer
{
	public:
		static uintptr_t	serialize(Data *ptr);
		static Data*		deserialize(uintptr_t raw);
	
	private:
		Serializer(void);
		Serializer(Serializer const &other);
		~Serializer(void);

		Serializer	&operator=(Serializer const &other);
};

#endif