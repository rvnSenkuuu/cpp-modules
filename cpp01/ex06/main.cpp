/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:11:03 by tkara2            #+#    #+#             */
/*   Updated: 2024/11/27 14:11:03 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static void	print_usage(void)
{
	std::cout << "Wrong argument number " << std::endl <<
				 "Usage: ./HarlFilter <level>" << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		print_usage();
		return 1;
	}
	std::string	input = argv[1];
	Harl		harl;

	harl.complain(input);
	return 0;
}