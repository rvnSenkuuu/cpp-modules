/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:56:51 by tkara2            #+#    #+#             */
/*   Updated: 2025/01/02 20:00:16 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
	std::cout << "RPN default constructor called" << std::endl;
}

RPN::RPN(const std::string &line)
{
	std::cout << "RPM assignement constructor called" << std::endl;
	operation(line);
}

RPN::RPN(RPN const &other)
{
	std::cout << "RPN copy constructor called" << std::endl;
	*this = other;
}

RPN	&RPN::operator=(RPN const &other)
{
	std::cout << "RPN copy assignement operator called" << std::endl;
	if (this != &other)
		this->_data = other._data;
	return *this;
}

RPN::~RPN(void)
{
	std::cout << "RPM destructor called" << std::endl;
}

bool	RPN::validOperator(const std::string &op)
{
	return op == "+" || op == "-" || op == "*" || op == "/";
}

int	RPN::doOperation(const int &lhs, const int &rhs, const std::string &op)
{
	if (op == "+") return lhs + rhs;
	if (op == "-") return lhs - rhs;
	if (op == "*") return lhs * rhs;
	if (op == "/")
	{
		if (lhs == 0)
			throw std::runtime_error("Division by 0 is impossible");
		return rhs / lhs;
	}
	return 0;
}

int	RPN::operation(const std::string &line)
{
	std::string			arg;
	std::stringstream	ss(line);

	while (ss >> arg)
	{
		if (validOperator(arg))
		{
			if (this->_data.size() < 2)
				throw std::runtime_error("Not enough arguments to operate");
			int	rhs = this->_data.top();
			this->_data.pop();
			int	lhs = this->_data.top();
			this->_data.pop();
			int res = doOperation(lhs, rhs, arg);
			this->_data.push(res);
		}
		else
		{
			int	number = std::strtod(arg.c_str(), NULL);

			if (number < 0 || number > 9)
				throw std::runtime_error("Invalid number in the operation");
			this->_data.push(number);
		}
	}
	if (this->_data.size() != 1)
		throw std::runtime_error("The user input has too many operands");

	return this->_data.top();
}