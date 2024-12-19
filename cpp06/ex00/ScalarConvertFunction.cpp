/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertFunction.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:57:15 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/19 11:57:15 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"

void	convertToNan(void)
{
	std::cout << "Char: impossible" << std::endl;
	std::cout << "Int: impossible" << std::endl;
	std::cout << "Float: nanf" << std::endl;
	std::cout << "Double: nanf" << std::endl;
}

void	printNoDisplayable(void)
{
	std::cout << "Char: Non displayable" << std::endl << 
				 "Int: 0" << std::endl << 
				 "Float: 0.0f" << std::endl << 
				 "Double: 0.0" << std::endl;
}

void	convertToChar(std::string &toConvert)
{
	char	c = toConvert[0];
	if (!std::isprint(c))
		printNoDisplayable();
	std::cout << "Char: " << "'" << static_cast<char>(c) << "'" << std::endl;
	std::cout << "Int: " << static_cast<int>(c) << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(2) << static_cast<float>(c) << std::endl;
	std::cout << "Double: " << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void	convertToInt(std::string &toConvert)
{
	//TODO
	(void)toConvert;
}