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

void	BitcoinExchange::checkValue(const double &value)
{
	if (value < 0)
		throw std::invalid_argument("not a positive number.");
	if (value > MAX_VALUE)
		throw std::invalid_argument("too large a number.");
}

bool	BitcoinExchange::validChar(const char &c)
{
	return (c >= '0' && c <= '9') || (c == '-'); 
}

void	BitcoinExchange::checkDate(std::string &date)
{
	date.erase(date.find(' '));
	if (date.length() != 10)
		throw std::logic_error("Bad input => " + date);

	for (size_t i = 0; i < date.length(); i++)
		if (!validChar(date.at(i)))
			throw std::logic_error("Wrong date format expected YYYY-MM-DD");
	
	int			year, month, day;
	std::string	delimiter = "-";
	size_t	fistDelPos = date.find_first_of(delimiter);
	size_t	lastDelPos = date.find_last_of(delimiter);

	year = std::atoi(date.substr(0, fistDelPos).c_str());
	month = std::atoi(date.substr(fistDelPos + 1, lastDelPos).c_str());
	day = std::atoi(date.substr(lastDelPos + 1).c_str());

	if (year <= 0 || (year > 2025 && month > 1))
		throw std::logic_error("Bad input => " + date);
	if (month <= 0 || month > 12)
		throw std::logic_error("Bad input => " + date);
	if (day <= 0 || day > 31)
		throw std::logic_error("Bad input => " + date);
	if (year <= 2009 && month <= 1 && day < 3)	
		throw std::logic_error("Bitcoin wasn't created yet at " + date);
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
				checkDate(date);
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