/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:08:05 by tkara2            #+#    #+#             */
/*   Updated: 2024/12/14 19:08:05 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyForm", "Targetless", 145, 137)
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyForm", target, 145, 137)
{
	std::cout << "ShrubberyCreationForm assignement constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other)
{
	std::cout << "ShrubberyCreationForm copy assignement constructor called" << std::endl;
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	std::cout << "ShrubberyCreationForm copy assignement operator called" << std::endl;
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	this->checkForm(executor);

	std::string		infile = TREEFILE;
	std::string		outfile = this->getTarget();
	outfile.append(SCFFILESUFFIX);

	std::ifstream	ifs(infile.c_str());
	if (!ifs.is_open())
		throw std::runtime_error("Fail Open ifstream");

	std::ofstream	ofs(outfile.c_str());
	if (!ofs.is_open())
	{
		ifs.close();
		throw std::runtime_error("Fail Open ofstream");
	}

	for (std::string line; getline(ifs, line);)
		if (!ifs.eof())
			ofs << line << std::endl;

	ifs.close();
	ofs.close();
}