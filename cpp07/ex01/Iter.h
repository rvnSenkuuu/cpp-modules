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

# include <iostream>

# define MAX_SIZE 5

template<typename T1, typename T2>
void	iter(T1 *array, size_t size, T2 f_ptr)
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
void	addFortyTwo(T &content)
{
	content += 42;
}

template<typename T>
void	rot13(T &content)
{
	for (size_t i = 0; i < content.length(); i++)
	{
		if ((content[i] >= 'a' && content[i] <= 'm')
			|| (content[i] >= 'A' && content[i] <= 'M'))
			content[i] += 13;
		else if ((content[i] >= 'n' && content[i] <= 'z') 
				|| (content[i] >= 'N' && content[i] <= 'Z'))
			content[i] -= 13;
	}
}

#endif