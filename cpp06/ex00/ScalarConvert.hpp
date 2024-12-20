/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:12:50 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/18 15:12:50 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP

# include <iostream>
# include <sstream>
# include <cctype>
# include <cstdlib>
# include <iomanip>
# include <limits>

void	printNoDisplayable(void);
void	convertToNan(void);
void	convertToChar(std::string &toConvert);
void	convertToInt(std::string &toConvert);
void	convertToDouble(std::string toConvert);
void	convertToFloat(std::string toConvert);
bool	isFloat(std::string toConvert);
bool	isDouble(std::string toConvert);

enum	ScalarType
{
	INVALID = -1,
	NAN = 0,
	CHAR = 1,
	INT = 2,
	FLOAT = 3,
	DOUBLE = 4
};

class   ScalarConvert
{
    public:
        static void convert(std::string toConvert);

    private:
        ScalarConvert(void);
        ScalarConvert(ScalarConvert const &other);
        ~ScalarConvert(void);
        ScalarConvert   &operator=(ScalarConvert const &other);

		static ScalarType	getScalarType(std::string toConvert);
};

#endif