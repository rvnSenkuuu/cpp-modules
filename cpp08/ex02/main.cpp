/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:21:58 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/25 17:21:58 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main(void)
{
	std::string			input;
	MutantStack<int>	mstack;

	displayCommand();
	while (true)
	{
		std::cout << "Enter a command > ";
		std::getline(std::cin, input);
		convertLowercase(input);
		if (std::cin.eof() || std::cin.fail())
		{
			std::cin.clear();
			break;
		}

		CommandType	type = getCommandType(input);
		switch (type)
		{
			case 0:
				if (!addNumber(mstack)) continue;
				break;
			case 1:
				mstack.pop();
				break;
			case 2:
				displayCommand();
				break;
			case 3:
				std::for_each(mstack.cbegin(), mstack.cend(), displayStackContent);
				break;
			case 4:
				std::cout << "Exiting the program" << std::endl;
				return 0;
			default:
				std::cout << "Invalid command" << '\n';
				break;
		}
	}
	return 0;
}