/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:29:40 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/23 14:29:40 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "CompareSwap.h"

int	main(void)
{
	int	lhs = 1;
	int	rhs = 9;

	std::cout << "-----Before swap-----" << std::endl;
	std::cout << "LHS: " << lhs << " and RHS: " << rhs << std::endl;
	std::cout << "Min(lhs, rhs) = " << ::min(lhs, rhs) << std::endl;
	std::cout << "Max(lhs, rhs) = " << ::max(lhs, rhs) << std::endl;
	::swap(lhs, rhs);
	std::cout << std::endl;
	std::cout << "-----After swap-----" << std::endl;
	std::cout << "LHS: " << lhs << " and RHS: " << rhs << std::endl;
	std::cout << "Min(lhs, rhs) = " << ::min(lhs, rhs) << std::endl;
	std::cout << "Max(lhs, rhs) = " << ::max(lhs, rhs) << std::endl;
	return 0;
}