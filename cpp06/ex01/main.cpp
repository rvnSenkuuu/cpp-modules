/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:14:54 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/20 13:14:54 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

int	main(void)
{
	unsigned int	age[MAX_PERSON] =
	{
		10, 43, 12, 54, 65,
		65, 78, 33, 20, 74
	};
	std::string		name[MAX_PERSON] =
	{
		"Name1", "Name2", "Name3", "Name4", "Name5",
		"Name6", "Name7", "Name8", "Name9", "Name10"
	};
	std::string		address[MAX_PERSON] =
	{
		"Pos A", "Pos B", "Pos C", "Pos D", "Pos E",
		"Pos F", "Pos G", "Pos H", "Pos I", "Pos J"
	};
	Data	data(name, address, age);

	Serializer::serialize(&data);

	return 0;
}