/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:18:26 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/21 18:18:26 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>

class	Base
{
	public:
		virtual ~Base(void);
		virtual void	announce(void);
};

void	identify(Base *p);
void	identify(Base &p);
Base	*generate(void);

#endif