/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orezek <orezek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:37:07 by orezek            #+#    #+#             */
/*   Updated: 2024/08/31 10:22:13 by orezek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iomanip>
#include <ctime>

// Constructor
Account::Account(int initial_deposit)
{
	this->_amount += initial_deposit;
	this->_accountIndex = Account::_nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += initial_deposit;
	Account::_nbAccounts++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
				<< ";amount:" << initial_deposit
				<< ";created" << std::endl;
};
// Private constructor - no account should be created without some amount
Account::Account() {};
// Destructor - used by compiler to clean the memory
Account::~Account()
{
	this->_nbAccounts--;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";closed" << std::endl;
};

// Private variables
// Static class variable - they have to be defined in cpp file
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// Public methods
// static method - gets total number of accounts created across all the instances
int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}
// static method - gets total amount of money deposited across all accounts
int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}
// static method - gets total number of deposits, it counts makeDeposit function
int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}
// static method - total number of withdrawals, follow the makeWithdrawal function
int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}
// static method
void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts
			<< ";" "total:" << Account::_totalAmount
			<< ";deposits:" << Account::_totalNbDeposits
			<< ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}
// Instance method
void	Account::makeDeposit( int deposit )
{
	int p_amount = 0;
	p_amount = this->_amount;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	this->_nbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	<< ";p_amount:" << p_amount
	<< ";deposit:" << deposit
	<< ";amount:" << this->_amount
	<< ";nb_deposits:" << this->_nbDeposits << std::endl;
}
// Instance method
bool	Account::makeWithdrawal( int withdrawal )
{
	int	p_amount = 0;
	if (this->_amount - withdrawal >= 0)
	{
		p_amount = this->_amount;
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << p_amount
		<< ";withdrawal:" << withdrawal
		<< ";amount:" << this->_amount
		<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
	Account::_displayTimestamp();
	std::cout << "index:"
	<< this->_accountIndex
	<< ";p_amount:" << this->_amount
	<< ";withdrawal:refused"
	<< std::endl;
	return (false);
}
// Instance method
int		Account::checkAmount( void ) const
{
	return (this->_amount);
}
// Instance method
void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:"
	<< this->_accountIndex << ";amount:"
	<< this->_amount << ";deposits:"
	<< this->_nbDeposits << ";withdrawals:"
	<< this->_nbWithdrawals << std::endl;
}
// Private method
// static method
void	Account::_displayTimestamp( void )
{
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	std::cout << "[" << now->tm_year + 1900
		<< std::setfill('0') << std::setw(2) << now->tm_mon + 1
		<< std::setfill('0') << std::setw(2) << now->tm_mday << "_"
		<< std::setfill('0') << std::setw(2) << now->tm_hour
		<< std::setfill('0') << std::setw(2) << now->tm_min
		<< std::setfill('0') << std::setw(2) << now->tm_sec << "] ";
}
