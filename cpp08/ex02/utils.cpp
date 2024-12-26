/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:47:09 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/26 13:47:09 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

void	displayCommand(void)
{
	std::cout << "Available commands:\n"
				 "[PUSH]: Used for pushing a number onto the stack\n"
				 "[POP]: Removes the top number from the stack\n"
				 "[PRINT]: Display the values inside the stack\n"
				 "[RPRINT]: Displays the values in reverse order inside the stack\n"
				 "[HELP]: Show all available commands\n"
				 "[EXIT]: Exit the program" << std::endl;
}

void	convertLowercase(std::string &input)
{
	for (size_t i = 0; i < input.length(); i++)
		if (std::isupper(input[i]))
			input[i] += 32;
}

// void	displayStackContent(const int &content)
// {
// 	std::cout << "Value: " << content << '\n';
// }

CommandType	getCommandType(const std::string &input)
{
	if (input == "push")
		return PUSH;
	if (input == "pop")
		return POP;
	if (input == "exit")
		return EXIT;
	if (input == "help")
		return HELP;
	if (input == "print")
		return PRINT;
	if (input == "rprint")
		return RPRINT;
	return INVALID;
}