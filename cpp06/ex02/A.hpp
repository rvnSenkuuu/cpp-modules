/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:18:26 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/21 18:18:26 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_HPP
#define A_HPP

# include "Base.hpp"

class	A : public Base
{
	public:
		A(void);
		~A(void);

		void	announce(void);
};

#endif