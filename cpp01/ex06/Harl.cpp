/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:11:03 by tkara2            #+#    #+#             */
/*   Updated: 2024/11/27 14:11:03 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ] " << std::endl <<
				 "DEBUG DEBUG DEBUG" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ] " << std::endl <<
				 "INFO INFO INFO" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ] " << std::endl <<
				 "WARNING WARNING WARNING" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ] " << std::endl <<
				 "ERROR ERROR ERROR" << std::endl;
}

void	Harl::empty(void)
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

int	Harl::getComplainLevel(std::string level) const
{
	std::string	level_array[MAX_LEVEL] = 
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
		"EMPTY",
	};

	for (int i = 0; i < MAX_LEVEL; i++)
	{
		if (level_array[i] == level)
			return i;
	}
	return -1;
}

void	Harl::complain(std::string level)
{
	void	(Harl::*f_array[5])(void) =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
		&Harl::empty,
	};

	int	complain_level = getComplainLevel(level);
	switch (complain_level)
	{
		case 0:
			(this->*f_array[0])();
			std::cout << std::endl;
		case 1:
			(this->*f_array[1])();
			std::cout << std::endl;
		case 2:
			(this->*f_array[2])();
			std::cout << std::endl;
		case 3:
			(this->*f_array[3])();
			std::cout << std::endl;
			break;
		default:
			(this->*f_array[4])();
			break;
	}
}
