/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:49:43 by tkara2            #+#    #+#             */
/*   Updated: 2025/01/03 10:13:17 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
	std::cout << "RPN default constructor called" << std::endl;
}

RPN::RPN(const std::string &line)
{
	std::cout << "RPN asssignement constructor called" << std::endl;
	operation(line);
}

RPN::RPN(RPN const &other)
{
	std::cout << "RPN copy assignement constructor called" << std::endl;
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
	std::cout << "RPN destructor called" << std::endl;
}

bool	RPN::validOperator(const std::string &op)
{
	return op == "+" || op == "-" || op == "*" || op == "/";
}

operationType	RPN::getOperationType(const std::string &arg)
{
	operationType	operationIndex[MAX_OPERATION] = {ADD, SUB, MULT, DIV};
	std::string		operation[MAX_OPERATION] = {"+", "-", "*", "/"};

	for (int i = 0; i < MAX_OPERATION; i++)
		if (arg == operation[i])
			return operationIndex[i];

	return INVALID;
}

int	RPN::doOperation(const int &lhs, const int &rhs, operationType type)
{
	switch (type)
	{
		case ADD:
			return lhs + rhs;
			break;
		case SUB:
			return lhs - rhs;
			break;
		case MULT:
			return lhs * rhs;
			break;
		case DIV:
			if (lhs == 0)
				throw std::logic_error("Division by 0 is impossible");
			return lhs / rhs;
			break;
		default:
			break;
	}
	return INVALID;
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
			operationType	type = getOperationType(arg);
			int rhs = this->_data.top();
			this->_data.pop();
			int lhs = this->_data.top();
			this->_data.pop();
			int result = doOperation(lhs, rhs, type);
			this->_data.push(result);
		}
		else
		{
			int	number = std::atoi(arg.c_str());

			if (number < 0 || number > 9)
				throw std::runtime_error("Invalid number in the operation");
			this->_data.push(number);
		}
	}
	if (this->_data.size() != 1)
		throw std::runtime_error("The user input has too many operands");
	return this->_data.top();
}