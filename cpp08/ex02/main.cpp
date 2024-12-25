/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:21:58 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/25 17:21:58 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main(void)
{
	MutantStack<int>	mstack;

	mstack.push(3);
	mstack.push(5);
	mstack.push(21);
	mstack.push(42);
	mstack.push(84);


	std::cout << "--------------------------" << std::endl;
	std::cout << "After pushing in the stack" << std::endl;
	std::cout << "mstack top(): " << mstack.top() << std::endl;
	std::cout << "mstack size: " << mstack.size() << std::endl;
	std::cout << "--------------------------" << std::endl;

	mstack.pop();
	mstack.pop();

	std::cout << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << "After popping from the stack" << std::endl;
	std::cout << "mstack top(): " << mstack.top() << std::endl;
	std::cout << "mstack size: " << mstack.size() << std::endl;
	std::cout << "--------------------------" << std::endl;

	return 0;
}