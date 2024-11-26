/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:10:58 by tkara2            #+#    #+#             */
/*   Updated: 2024/11/26 17:23:06 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>

static void	print_usage(void)
{
	std::cout << "Wrong argument number " << std::endl <<
				 "Usage: ./sed <filename> <to_find> <to_replace>" << std::endl;
}

int	main(int argc, char **argv)
{
	const char		*output_file = "output.replace";
	std::string		input;
	std::ifstream	ifs;
	std::ofstream	ofs;

	if (argc != 4)
		print_usage();
	ifs.open(argv[1]);
	ofs.open(output_file);

	while (getline(ifs, input))
		std::cout << "Input: " << input << std::endl;
	
	ifs.close();
	ofs.close();
	return EXIT_SUCCESS;
}