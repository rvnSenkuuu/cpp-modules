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

BitcoinExchange::BitcoinExchange(const char *dataFile)
{
	std::cout << "BitcoinExchange assignement constructor called" << std::endl;
	loadData(dataFile);
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
	double			value;
	std::string		date;
	std::string		line;
	std::ifstream	ifs(dataFile);
	if (!ifs.is_open())
		throw std::logic_error("No such .csv file");

	std::getline(ifs, line);
	if (line != "date,exchange_rate")
		throw std::logic_error("Wrong .csv file format, expected in first line: 'date,exchange_rate'");

	unsigned int	count_line = 0;
	while (std::getline(ifs, line))
	{
		std::istringstream	iss(line);
		if (std::getline(iss, date, ',') && iss >> value)
		{
			//TODO: Date check function
			this->_data[date] = value;
		}
		else
		{
			std::cerr << "Wrong data format at line: " << count_line << ". " <<
						 "Ensure that the data is in the correct format: '<date> | <value>'" << '\n';
			continue;
		}
		count_line++;
	}
}

void	BitcoinExchange::checkValue(const double &value)
{
	if (value < 0)
		throw std::invalid_argument("not a positive number.");
	if (value > MAX_VALUE)
		throw std::invalid_argument("too large a number.");
}

void	BitcoinExchange::convertBitcoin(const char *inputFile)
{
	double			value;
	std::string		date;
	std::string		line;
	std::ifstream	ifs(inputFile);
	if (!ifs.is_open())
		throw std::invalid_argument("No such input file");

	std::getline(ifs, line);
	if (line != "date,value")
		throw std::logic_error("Wrong input file format, expected in first line: 'date,value'");
	
	unsigned int	count_line = 0;
	while (std::getline(ifs, line))
	{
		std::istringstream	iss(line);
		if (std::getline(iss, date, '|') && iss >> value)
		{
			//TODO: Data check function
			try 
			{
				checkValue(value);
			}
			catch (const std::exception &e)
			{
				std::cerr << "Error: " << e.what() << '\n';
				continue;
			}
			std::cout << "DATE: " << date << " Value: "  << value << '\n';
		}
		else
		{
			std::cerr << "Wrong data format at line: " << count_line << ". " <<
						 "Ensure that the data is in the correct format: '<date> | <value>'" << '\n';
			continue;
		}
		count_line++;
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