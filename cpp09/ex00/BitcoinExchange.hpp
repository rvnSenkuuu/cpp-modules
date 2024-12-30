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
# include <exception>
# include <algorithm>
# include <map>

# define DATA_FILE "./data.csv"

class	BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &other);
		~BitcoinExchange(void);
		BitcoinExchange	&operator=(BitcoinExchange const &other);

		void	loadData(const char *dataFile);

	private:
		BitcoinExchange(const std::string &dataFile);
		std::map<std::string, double>	_data;
};

#endif