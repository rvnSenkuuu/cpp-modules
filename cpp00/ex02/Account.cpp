/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-24 20:47:04 by tkara2            #+#    #+#             */
/*   Updated: 2024-11-24 20:47:04 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts)
{
	Account::_displayTimestamp();
	this->_amount = initial_deposit;
	++Account::_nbAccounts;
	std::cout << "index:" << _accountIndex << ";" <<
				 "amount:" << _amount << ";" <<
				 "created" << std::endl;
	_totalAmount += _amount;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" <<
				 "amount:" << _amount << ";" <<
				 "closed" << std::endl;
	Account::_nbAccounts--;
}

int	Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";" <<
				 "total:" << getTotalAmount() << ";" << 
				 "deposits:" << getNbDeposits() << ";" <<
				 "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int	nb_deposit = 0;
	int	new_amount = checkAmount() + deposit;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" <<
				 "p_amount:" << this->_amount << ";" <<
				 "deposit:" << deposit << ";" <<
				 "amount:" << new_amount << ";" <<
				 "nb_deposits:" << ++nb_deposit << std::endl;
	this->_amount = new_amount;
	this->_nbDeposits += nb_deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if ((checkAmount() - withdrawal) >= 0)
	{
		int	nb_withdrawal = 0;
		int	new_amount = checkAmount() - withdrawal;

		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";" <<
					"p_amount:" << this->_amount << ";" <<
					"withdrawal:" << withdrawal << ";" << 
					"amount:" << new_amount << ";" <<
					"nb_withdrawals:" << ++nb_withdrawal << std::endl;
		this->_amount = new_amount;
		this->_nbWithdrawals = nb_withdrawal;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		return true;
	}
	else
	{
		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";" <<
					 "p_amount:" << this->_amount << ";" <<
					 "withdrawal:refused" << std::endl;
		return false;
	}
}

int		Account::checkAmount(void) const
{
	return this->_amount;
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" <<
				 "amount:" << this->_amount << ";" <<
				 "deposits:" << this->_nbDeposits << ";" <<
				 "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t	time = std::time(NULL);
	std::tm		*tm = std::localtime(&time);

	std::cout << "[" << tm->tm_year + 1900 <<
						tm->tm_mon + 1 <<
						tm->tm_mday <<
						"_" <<
						tm->tm_hour <<
						tm->tm_min <<
						tm->tm_sec << "] ";
}
