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
	std::cout << "DEBUG DEBUG DEBUG" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "INFO INFO INFO" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "WARNING WARNING WARNING" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "ERROR ERROR ERROR "<< std::endl;
}

void	Harl::complain(std::string level)
{
	void	(Harl::*f_array[MAX_LEVEL])(void) =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
	};

	std::string	level_array[MAX_LEVEL] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
	};

	for (int i = 0; i < MAX_LEVEL; i++)
	{
		if (level == level_array[i])
			(this->*f_array[i])();
	}
}
