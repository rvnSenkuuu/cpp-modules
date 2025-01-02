/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:56:49 by tkara2            #+#    #+#             */
/*   Updated: 2025/01/02 19:51:27 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

# include <iostream>
# include <sstream>
# include <algorithm>
# include <stack>

class	RPN
{
	public:
		RPN(void);
		RPN(const RPN &other);
		~RPN(void);
		RPN	&operator=(RPN const &other);

		int	operation(const std::string &line);

	private:
		RPN(const std::string &line);
		bool	validOperator(const std::string &op);
		int		doOperation(const int &lhs, const int &rhs, const std::string &op);

	private:
		std::stack<int>	_data;
};
#endif