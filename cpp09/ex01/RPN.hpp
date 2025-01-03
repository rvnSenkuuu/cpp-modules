/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:56:49 by tkara2            #+#    #+#             */
/*   Updated: 2025/01/03 10:06:37 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

# include <iostream>
# include <sstream>
# include <algorithm>
# include <stack>

# define MAX_OPERATION 4

typedef enum
{
	INVALID = -1,
	ADD,
	SUB,
	MULT,
	DIV
}	operationType;

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
		int		doOperation(const int &lhs, const int &rhs, operationType type);
		operationType	getOperationType(const std::string &arg);

	private:
		std::stack<int>	_data;
};
#endif