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
# include <stack>

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
};

#endif