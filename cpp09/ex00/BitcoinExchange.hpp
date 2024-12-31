/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:23:16 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/30 14:23:16 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <exception>
# include <algorithm>
# include <map>

# define DATA_FILE "./data.csv"
# define MAX_VALUE 10000

template<typename T>
std::string	numberToString(T number)
{
	std::ostringstream	oss;
	oss << number;
	return oss.str();
}

class	BitcoinExchange
{
	public:
		BitcoinExchange(const char *dataFile);
		BitcoinExchange(BitcoinExchange const &other);
		~BitcoinExchange(void);
		BitcoinExchange	&operator=(BitcoinExchange const &other);

		void	convertBitcoin(const char *inputFile);
		void	printData(void);

	private:
		BitcoinExchange(void);

		void	loadData(const char *dataFile);
		void	checkValue(const double &value);

	private:
		std::map<std::string, double>	_data;
};

#endif