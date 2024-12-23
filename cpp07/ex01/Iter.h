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

#ifndef ITER_H
#define ITER_H

# define MAX_SIZE 5

template<typename T>
void	iter(T *array, size_t size, void (*f_ptr)(T &content))
{
	for (size_t i = 0; i < size; i++)
		f_ptr(array[i]);
}

template<typename T>
void	displayArray(T array, size_t size)
{
	for (size_t i = 0; i < size; i++)
		std::cout << "Array " << i << ": " << array[i] << std::endl;
}

template<typename T>
void	addTen(T &content)
{
	content += 10;
}

template<typename T>
void	rot13(T &content)
{
	for (size_t i = 0; i < content.length(); i++)
	{
		if (content[i] >= 'a' && content[i] <= 'm')
			content[i] += 13;
		else if (content[i] >= 'n' && content[i] <= 'z')
			content[i] -= 13;
	}
}

#endif