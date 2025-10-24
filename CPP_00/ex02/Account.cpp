/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:58:13 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/24 11:56:05 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			  << "amount:" << this->_amount << ";"
			  << "created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			  << "amount:" << this->_amount << ";"
			  << "closed" << std::endl;
	Account::_nbAccounts--;
}

int	Account::getNbAccounts( void )
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void )
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
			  << "total:" << getTotalAmount() << ";"
			  << "deposits:" << getNbDeposits() << ";"
			  << "withdrawals:" << getNbWithdrawals()
			  << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	int	p_amount;
	
	if (deposit <= 0)
	{
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";"
				  << "p_amount:" << this->_amount << ";"
				  << "deposit:" << "refused"
				  << std::endl;
		return ;
	}
	
	p_amount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;
	
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			  << "p_amount:" << p_amount << ";"
			  << "deposit:" << deposit << ";"
			  << "amount:" << this->_amount << ";"
			  << "nb_deposits:" << this->_nbDeposits
			  << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int	p_amount;

	if (this->_amount < withdrawal || withdrawal <= 0)
	{
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";"
				  << "p_amount:" << this->_amount << ";"
				  << "withdrawal:" << "refused"
				  << std::endl;
	
		return false;
	}
	
	p_amount = this->_amount;
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			  << "p_amount:" << p_amount << ";"
			  << "withdrawal:" << withdrawal << ";"
			  << "amount:" << this->_amount << ";"
			  << "nb_withdrawals:" << this->_nbWithdrawals
			  << std::endl;
	
	return true;
}

int		Account::checkAmount( void ) const
{
	return this->_amount;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			  << "amount:" << checkAmount() << ";"
			  << "deposits:" << this->_nbDeposits << ";"
			  << "withdrawals:" << this->_nbWithdrawals
			  << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t t = std::time(NULL);
	std::tm *tm = std::localtime(&t);

	std::cout << "["
			  << std::setfill('0') << std::setw(4) << (1900 + tm->tm_year)
			  << std::setfill('0') << std::setw(2) << (1 + tm->tm_mon)
			  << std::setfill('0') << std::setw(2) << tm->tm_mday
			  << "_"
			  << std::setfill('0') << std::setw(2) << tm->tm_hour
			  << std::setfill('0') << std::setw(2) << tm->tm_min
			  << std::setfill('0') << std::setw(2) << tm->tm_sec
			  << "] ";
}