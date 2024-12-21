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
		10, 43, 12, 54, 65
	};
	std::string		name[MAX_PERSON] =
	{
		"Name1", "Name2", "Name3", "Name4", "Name5"
	};
	std::string		address[MAX_PERSON] =
	{
		"Pos A", "Pos B", "Pos C", "Pos D", "Pos E"
	};

	Data	*data1 = new Data();
	Data	*data2 = new Data(name, address, age);

	uintptr_t	raw_data1 = Serializer::serialize(data1);
	uintptr_t	raw_data2 = Serializer::serialize(data2);

	std::cout << "-----------------------------------" << std::endl;
	std::cout << "           Serialization           " << std::endl;
	std::cout << "Raw_data1: " << raw_data1 << std::endl;
	std::cout << "Raw_data2: " << raw_data2 << std::endl;


	Data	*deserialize_data1 = Serializer::deserialize(raw_data1);
	Data	*deserialize_data2 = Serializer::deserialize(raw_data2);

	std::cout << "-----------------------------------" << std::endl;
	std::cout << "          Deserialization          " << std::endl;
	std::cout << "Data1: " << data1 << std::endl;
	std::cout << "Data2: " << data2 << std::endl;
	std::cout << "Deserialize_data1: " << deserialize_data1 << std::endl;
	std::cout << "Deserialize_data2: " << deserialize_data2 << std::endl;

	std::cout << "-----------------------------------" << std::endl;
	std::cout << "            Print Data             " << std::endl;
	std::cout << "Data1: " << std::endl;
	data1->printData();
	std::cout << std::endl;
	std::cout << "Deserialize_data1: " << std::endl;
	deserialize_data1->printData();

	std::cout << "Data2: " << std::endl;
	data2->printData();
	std::cout << std::endl;
	std::cout << "Deserialize_data2: " << std::endl;
	deserialize_data2->printData();
	std::cout << "-----------------------------------" << std::endl;

	delete deserialize_data1;
	delete deserialize_data2;
	return 0;
}