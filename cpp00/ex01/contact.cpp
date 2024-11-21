/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-21 16:11:27 by tkara2            #+#    #+#             */
/*   Updated: 2024-11-21 16:11:27 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void	Contact::set_fname(std::string str)
{
	this->fname = str;
	return;
}

void	Contact::set_lname(std::string str)
{
	this->lname = str;
	return;
}

void	Contact::set_nname(std::string str)
{
	this->nname = str;
	return;
}

void	Contact::set_number(std::string str)
{
	this->phone_number = str;
	return;
}

void	Contact::set_secret(std::string str)
{
	this->secret = str;
	return;
}

std::string	Contact::get_fname(void) const
{
	return this->fname;
}

std::string	Contact::get_lname(void) const
{
	return this->lname;
}

std::string	Contact::get_nname(void) const
{
	return this->nname;
}

std::string	Contact::get_number(void) const
{
	return this->phone_number;
}

std::string	Contact::get_secret(void) const
{
	return this->secret;
}