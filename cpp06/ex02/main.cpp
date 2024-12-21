/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:17:00 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/21 18:17:00 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main(void)
{
	Base	*base = generate();

	std::cout << "-----Identify ptr-----" << std::endl;
	identify(base);

	std::cout << "-----Identify ref-----" << std::endl;
	identify(*base);

	delete base;
	return 0;
}