/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-21 15:51:31 by tkara2            #+#    #+#             */
/*   Updated: 2024-11-21 15:51:31 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <string>

class	Contact
{
	public:
		Contact(void);
		~Contact(void);
		void	set_fname(std::string str);
		void	set_lname(std::string str);
		void	set_nname(std::string str);
		void	set_number(std::string str);
		void	set_secret(std::string str);
		std::string	get_fname(void) const;
		std::string	get_lname(void) const;
		std::string	get_nname(void) const;
		std::string	get_number(void) const;
		std::string	get_secret(void) const;
	private:
		std::string	f_name;
		std::string	l_name;
		std::string	n_name;
		std::string	phone_number;
		std::string	secret;
};

#endif