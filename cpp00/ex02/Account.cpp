/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 16:54:11 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/18 18:12:58 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

static void	displayTime( void );

typedef Account		t;

// Static member definitions
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Contructor and destroyer
Account::Account( int initial_deposit )
{
	this->_accountIndex = getNbAccounts();
	_nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	displayTime();
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->_amount << ";created\n";
}
Account::~Account()
{
	displayTime();
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->_amount << ";closed\n";
	_nbAccounts--;
}

// Private functions
int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}
int	Account::getTotalAmount( void )
{
	return _totalAmount;
}
int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}
int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}
void	Account::displayAccountsInfos( void )
{
	displayTime();
	std::cout << "accounts:" << getNbAccounts()
		<< ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals() << "\n";
}

// Public functions
void	Account::makeDeposit( int deposit )
{
	displayTime();
	std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << this->_amount;
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_nbDeposits++;
	this->_totalNbDeposits++;
	std::cout << ";deposit:" << deposit
		<< ";amount:" << this->_amount
		<< ";nb_deposits:" << this->_nbDeposits << "\n";
}
bool	Account::makeWithdrawal( int withdrawal )
{
	displayTime();
	std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << this->_amount;
	if (this->_amount - withdrawal < 0)
	{
		std::cout << ";withdrawal:refused\n";
		return false ;
	}
	this->_amount -= withdrawal;
	this->_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	this->_totalNbWithdrawals++;
	std::cout << ";withdrawal:" << withdrawal
		<< ";amount:" << this->_amount
		<< ";nb_withdrawals:" << this->_nbWithdrawals << "\n";
	return true ;
}
int		Account::checkAmount( void ) const
{
	return this->_amount;
}
void	Account::displayStatus( void ) const
{
	displayTime();
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals << "\n";
}

static void	displayTime( void )
{
	std::time_t	now = std::time(0);
	std::tm*	timeinfo = std::localtime(&now);
	char		timestamp[19];
	std::strftime(timestamp, sizeof(timestamp), "[%Y%m%d_%H%M%S] ", timeinfo);
	std::cout << timestamp;
}
