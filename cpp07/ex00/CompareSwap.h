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

#ifndef COMPARESWAP_H
#define COMPARESWAP_H

template<typename T>
void	swap(T &lhs, T &rhs)
{
	T	tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}

template<typename T>
T const	&min(T const &lhs, T const &rhs)
{
	return lhs <= rhs ? lhs : rhs;
}

template<typename T>
T const	&max(T const &lhs, T const &rhs)
{
	return lhs >= rhs ? lhs : rhs;
}

#endif