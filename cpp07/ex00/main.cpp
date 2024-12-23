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

	std::cout << "-----Before swap (int)-----" << std::endl;
	std::cout << "LHS: " << lhs << " and RHS: " << rhs << std::endl;
	std::cout << "Min(lhs, rhs) = " << ::min(lhs, rhs) << std::endl;
	std::cout << "Max(lhs, rhs) = " << ::max(lhs, rhs) << std::endl;
	::swap(lhs, rhs);
	std::cout << std::endl;
	std::cout << "-----After swap (int)-----" << std::endl;
	std::cout << "LHS: " << lhs << " and RHS: " << rhs << std::endl;
	std::cout << "Min(lhs, rhs) = " << ::min(lhs, rhs) << std::endl;
	std::cout << "Max(lhs, rhs) = " << ::max(lhs, rhs) << std::endl;

	std::cout << std::endl;

	std::string	str_lhs = "chaine2";
	std::string	str_rhs = "chaine1";

	std::cout << "-----Before swap (str)-----" << std::endl;
	std::cout << "Str_lhs: " << str_lhs << " and Str_rhs: " << str_rhs << std::endl;
	std::cout << "Min(Str_lhs, Str_rhs) = " << ::min(str_lhs, str_rhs) << std::endl;
	std::cout << "Max(Str_lhs, Str_rhs) = " << ::max(str_lhs, str_rhs) << std::endl;
	::swap(str_lhs, str_rhs);
	std::cout << std::endl;
	std::cout << "-----After swap (str)-----" << std::endl;
	std::cout << "Str_lhs: " << str_lhs << " and Str_rhs: " << str_rhs << std::endl;
	std::cout << "Min(Str_lhs, Str_rhs) = " << ::min(str_lhs, str_rhs) << std::endl;
	std::cout << "Max(Str_lhs, Str_rhs) = " << ::max(str_lhs, str_rhs) << std::endl;

	return 0;
}