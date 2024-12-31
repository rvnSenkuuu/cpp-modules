/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:23:14 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/30 14:23:14 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const std::string &dataFile)
{
	std::cout << "BitcoinExchange assignement constructor called" << std::endl;
	(void)dataFile;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
	std::cout << "BitcoinExchange copy constructor called" << std::endl;
	*this = other;
}

BitcoinExchange::~BitcoinExchange(void)
{
	std::cout << "BitcoinExchange destructor called" << std::endl;
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &other)
{
	std::cout << "BitcoinExchange copy assignement operator called" << std::endl;
	if (this != &other)
		this->_data = other._data;
	return *this;
}

void	BitcoinExchange::loadData(const char *dataFile)
{
	std::string		line;
	std::ifstream	ifs(dataFile);
	if (!ifs.is_open())
		throw std::invalid_argument("No such file");

	getline(ifs, line);
	while (getline(ifs, line))
	{
		size_t	delimiterPos = line.find(',');
		if (delimiterPos == std::string::npos)
			throw std::logic_error("Missing comma. Excepted format: 'data,value'");
		std::string	date = line.substr(0, delimiterPos);
		double		value = std::atof(line.substr(delimiterPos + 1).c_str());
		this->_data[date] = value;
	}
}

void	BitcoinExchange::printData(void)
{
	std::map<std::string, double>::iterator	it = this->_data.begin();
	std::map<std::string, double>::iterator	ite = this->_data.end();
	for (; it != ite; it++)
		std::cout << "Date: " << it->first << " Value: " << it->second << '\n';
	std::cout << std::endl;
}