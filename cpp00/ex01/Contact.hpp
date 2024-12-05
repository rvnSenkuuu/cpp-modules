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

# include <iostream>
# include <string>

class	Contact
{
	public:
		Contact(void);
		~Contact(void);

		bool	create_contact(void);

		void	setFname(std::string str);
		void	setLname(std::string str);
		void	setNname(std::string str);
		void	setNumber(std::string str);
		void	setSecret(std::string str);
		std::string	getFname(void) const;
		std::string	getLname(void) const;
		std::string	getNname(void) const;
		std::string	getNumber(void) const;
		std::string	getSecret(void) const;

	private:
		std::string	_fname;
		std::string	_lname;
		std::string	_nname;
		std::string	_phone_number;
		std::string	_secret;
};

#endif