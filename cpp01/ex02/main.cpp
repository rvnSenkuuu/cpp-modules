/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:55:45 by tkara2            #+#    #+#             */
/*   Updated: 2024/11/26 14:55:45 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "String    Adresse: " << &string << std::endl;
	std::cout << "StringPTR Adresse: " << &stringPTR << std::endl;
	std::cout << "StringREF Adresse: " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "String    Valeur: " << string << std::endl;
	std::cout << "StringPTR Valeur: " << stringPTR << std::endl;
	std::cout << "StringREF Valeur: " << stringREF << std::endl;
	return 0;
}