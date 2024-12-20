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

void	printNoDisplayable(void)
{
	std::cout << "Char: Non displayable" << std::endl << 
				 "Int: 0" << std::endl << 
				 "Float: 0.0f" << std::endl << 
				 "Double: 0.0" << std::endl;
}

bool	isFloat(std::string toConvert)
{
	int	dotCount = 0;
	int	fCount = 0;

	for (size_t i = 0; i < toConvert.length(); i++)
	{
		if (toConvert[i] == '.')
			dotCount++;
		if (toConvert[i] == 'f')
			fCount++;
	}
	if (dotCount != 1 || fCount != 1)
		return false;
	if (toConvert.find('.') == std::string::npos)
		return false;
	if (toConvert.rfind('f') == std::string::npos)
		return false;
	return true;
}

bool	isDouble(std::string toConvert)
{
	int	dotCount = 0;

	for (size_t i = 0; i < toConvert.length(); i++)
		if (toConvert[i] == '.')
			dotCount++;
	if (dotCount != 1)
		return false;
	if (toConvert.find('.') == std::string::npos)
		return false;
	return true;
}

void	convertToNan(void)
{
	std::cout << "Char: Impossible" << std::endl;
	std::cout << "Int: Impossible" << std::endl;
	std::cout << "Float: Nanf" << std::endl;
	std::cout << "Double: Nan" << std::endl;
}

void	convertToChar(std::string &toConvert)
{
	char	c = toConvert[0];
	if (!std::isprint(c))
		printNoDisplayable();
	std::cout << "Char: " << "'" << static_cast<char>(c) << "'" << std::endl << 
				 "Int: " << static_cast<int>(c) << std::endl << 
				 "Float: " << std::fixed << std::setprecision(2) << static_cast<float>(c) << std::endl << 
				 "Double: " << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void	convertToInt(std::string &toConvert)
{
	int	i = std::atoi(toConvert.c_str());
	if (i > std::numeric_limits<char>::max() || i < 0 || !std::isprint(i))
		std::cout << "Char: Impossible" << std::endl;
	else 
		std::cout << "Char: " << "'" << static_cast<char>(i) << "'" << std::endl;
	std::cout << "Int: " << i << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(2) << static_cast<float>(i) << std::endl;
	std::cout << "Double: " << std::setprecision(2) << static_cast<double>(i) << std::endl;
}

void	convertToFloat(std::string toConvert)
{
	float		f = std::atof(toConvert.c_str());
	long long	castLL = static_cast<long long>(f);

	if (castLL < 0 || castLL > std::numeric_limits<char>::max() || !std::isprint(castLL))
		std::cout << "Char: Impossible" << std::endl;
	else
		std::cout << "Char: " << "'" << static_cast<char>(castLL) << "'" << std::endl;
	if (castLL < std::numeric_limits<int>::min() || castLL > std::numeric_limits<int>::max())
		std::cout << "Int: Impossible" << std::endl;
	else
		std::cout << "Int: " << static_cast<int>(castLL) << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(2) << f << "f" << std::endl;
	std::cout << "Double: " << std::setprecision(2) << static_cast<double>(f) << std::endl;
}

void	convertToDouble(std::string toConvert)
{
	double	d = std::atof(toConvert.c_str());
	long long	castLL = static_cast<long long>(d);

	if (castLL < 0 || castLL > std::numeric_limits<char>::max() || !std::isprint(castLL))
		std::cout << "Char: Impossible" << std::endl;
	else
		std::cout << "Char: " << static_cast<char>(castLL) << std::endl;
	if (castLL < std::numeric_limits<int>::min() || castLL > std::numeric_limits<int>::max())
		std::cout << "Int: Impossible" << std::endl;
	else
		std::cout << "Int: " << static_cast<int>(castLL) << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(2) << static_cast<float>(d) << "f" << std::endl;
	std::cout << "Double: " << std::setprecision(2) << d << std::endl;
}