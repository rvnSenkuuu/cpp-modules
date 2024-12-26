/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:22:10 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/25 17:22:10 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <limits>
# include <exception>
# include <algorithm>
# include <stack>

typedef enum
{
	INVALID = -1,
	PUSH = 0,
	POP = 1,
	HELP = 2,
	PRINT = 3,
	RPRINT = 4,
	EXIT = 5
}	CommandType;

void	displayCommand(void);
void	displayStackContent(const int &content);
void	convertLowercase(std::string &input);
CommandType	getCommandType(const std::string &input);

template<typename T>
void	displayStackContent(T &content)
{
	std::cout << "Value: " << content << '\n';
}

template<typename T>
bool	addNumber(T &stack)
{
	std::string	input;

	while (input.empty())
	{
		std::cout << "Enter the number (INT): ";
		std::getline(std::cin, input);
		if (std::cin.eof()) return false;
		long long number = std::atoll(input.c_str());
		if (number > std::numeric_limits<int>::max() || number < std::numeric_limits<int>::min())
		{
			std::cerr << "Input value is out of range for integer values" << '\n';
			return false;
		}
		stack.push(number);
	}
	return true;
}

template<typename T>
class	MutantStack : public std::stack<T>
{
	public:
		MutantStack<T>(void)
		{
			std::cout << "MutantStack default constructor called" << std::endl;
		};

		MutantStack(MutantStack<T> const &other)
		{
			std::cout << "MutantStack copy assignement constructor called" << std::endl;
			*this = other;
		};

		~MutantStack(void)
		{
			std::cout << "MutantStack destructor called" << std::endl;
		};

		MutantStack<T>	&operator=(MutantStack<T> const &other)
		{
			std::cout << "MutantStack copy assignement operator called" << std::endl;
			if (this != &other)
				this->c = other.c;
			return *this;
		};

		typedef typename MutantStack<T>::container_type::iterator	iterator;
		typedef typename MutantStack<T>::container_type::const_iterator	const_iterator;
		typedef typename MutantStack<T>::container_type::reverse_iterator	reverse_iterator;
		typedef typename MutantStack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

		iterator	begin() { return this->c.begin(); }
		iterator	end() { return this->c.end(); }
		const_iterator	cbegin() const { return this->c.begin(); }
		const_iterator	cend() const { return this->c.end(); }
		reverse_iterator	rbegin() { return this->c.rbegin(); }
		reverse_iterator	rend() { return this->c.rend(); }
		const_reverse_iterator	crbegin() const { return this->c.rbegin(); }
		const_reverse_iterator	crend() const { return this->c.rend(); }
};

#endif