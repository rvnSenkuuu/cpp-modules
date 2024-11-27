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
#include <iostream>
#include <fstream>

static void	print_usage(void)
{
	std::cout << "Wrong argument number " << std::endl <<
				 "Usage: ./sed <filename> <to_find> <to_replace>" << std::endl;
}

static bool	check_stream(std::ifstream &ifs, std::ofstream &ofs)
{
	if (!ifs.is_open())
	{
		std::cerr << "Fail open ifstream" << std::endl;
		return false;
	}
	if (!ofs.is_open())
	{
		std::cerr << "Fail open ofstream" << std::endl;
		return false;
	}
	return true;
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		print_usage();
		return 1;
	}

	std::string		line;
	std::string		output = argv[1];
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];
	output.append(".replace");

	std::ifstream	ifs(argv[1]);
	std::ofstream	ofs(output.c_str());

	if (!check_stream(ifs, ofs)) return 1;
	while (getline(ifs, line))
	{
		size_t	pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();
	return 0;
}