/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:31:24 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/23 14:31:24 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

# include <iostream>
# include <exception>
# include <cstdlib>
# include <ctime>

template<typename T>
void	checkArrayValue(T lhs, int *rhs, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (lhs[i] != rhs[i])
			throw std::logic_error("The two arrays didn't have the same value");
	}
	std::cout << "CheckArrayValue Success" << std::endl;
}

template<typename T>
class	Array
{
	public:
		Array<T>(void)
		{
			std::cout << "Array default constructor called" << std::endl;
			this->_array = new T();
			this->_size = 1;
		};

		Array<T>(unsigned int n)
		{
			std::cout << "Array assignement constructor called" << std::endl;
			this->_size = n;
			this->_array = new T[this->_size]();
		};

		Array<T>(const Array<T> &other)
		{
			std::cout << "Array copy assignement constructor called" << std::endl;
			this->_size = other._size;
			this->_array = new T[this->_size]();
			for (size_t i = 0; i < this->_size; i++)
				this->_array[i] = other._array[i];
		}

		Array<T>	&operator=(const Array<T> &other)
		{
			std::cout << "Array copy assignement operator called" << std::endl;
			if (this != &other)
			{
				delete[] this->_array;
				*this = Array<T>(other);
			}
			return *this;
		}

		T	&operator[](unsigned int index)
		{
			if (index < 0 || index >= this->_size)
				throw std::out_of_range("Index out of range");
			return this->_array[index];
		}

		const T	&operator[](unsigned int index) const
		{
			if (index < 0 || index >= this->_size)
				throw std::out_of_range("Index out of range");
			return this->_array[index];
		}

		~Array<T>(void)
		{
			std::cout << "Array destructor called" << std::endl;
			delete[] this->_array;
		};

		size_t	size() const
		{
			return this->_size;
		}

	private:
		T		*_array;
		size_t	_size;
};

#endif