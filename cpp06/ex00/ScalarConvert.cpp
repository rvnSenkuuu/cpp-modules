/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:12:50 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/18 15:12:50 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"

ScalarConvert::ScalarConvert(void)
{
    std::cout << "ScalarConvert default constructor called" << std::endl;
}

ScalarConvert::~ScalarConvert(void)
{
    std::cout << "ScalarConvert destructor called" << std::endl;
}

ScalarConvert::ScalarConvert(ScalarConvert const &other)
{
	std::cout << "ScalarConvert copy assignement constructor called" << std::endl;
	*this = other;
}

ScalarConvert   &ScalarConvert::operator=(ScalarConvert const &other)
{
    std::cout << "ScalarConvert copy assignement operator called" << std::endl;
    if (this != &other)
        *this = other;
    return *this;
}

ScalarType	ScalarConvert::getScalarType(std::string toConvert)
{
	if (toConvert == "nan")
		return NAN;

	if (toConvert.length() == 1 && !std::isdigit(toConvert[0]))
		return CHAR;
	
	int	i = std::atoi(toConvert.c_str());
	std::stringstream	ss;
	ss << i;
	if (toConvert == ss.str())
		return INT;

	if (toConvert == "-inff" || toConvert == "+inff" || toConvert == "nanf" || isFloat(toConvert) == true)
		return FLOAT;

	if (toConvert == "-inf" || toConvert == "+inf" || isDouble(toConvert) == true)
		return DOUBLE;
	return INVALID;
}

void	ScalarConvert::convert(std::string toConvert)
{
	ScalarType	type = getScalarType(toConvert);

	switch (type)
	{
		case NAN:
			convertToNan();
			break;
		case CHAR:
			convertToChar(toConvert);
			break;
		case INT:
			convertToInt(toConvert);
			break;
		case FLOAT:
			convertToFloat(toConvert);
			break;
		case DOUBLE:
			convertToDouble(toConvert);
			break;
		default:
			printNoDisplayable();
			break;
	}
	return;
}