/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:09:00 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/18 15:09:00 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"

static void	printUsage(void)
{
	std::cerr << "[Error]Usage: ./Convert <args to convert>" << std::endl;
}

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		printUsage();
		return 1;
	}
	std::string	toConvert = argv[1];
	ScalarConvert::convert(toConvert);
	return 0;
}