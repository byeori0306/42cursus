/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:56:12 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/21 17:12:11 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void) {
	return (_nbAccounts);
}

int	Account::getTotalAmount(void) {
	return (_totalAmount);
}

int	Account::getNbDeposits(void) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbDeposits() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	_totalAmount += this->_amount;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account() {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

void	Account::makeDeposit(int deposit) {
	int p_amount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits += 1;
	_totalNbDeposits += 1;
	
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << ";" << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	int p_amount = this->_amount;
	
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	if (this->_amount < withdrawal)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals += 1;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals += 1;
	}
	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << ";" << std::endl;
	return (true);
}

int	Account::checkAmount() const {
	return (this->_amount);
}

void	Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << ";" << std::endl;
}

void	Account::_displayTimestamp() {
	time_t	timer = time(NULL);
	struct tm*	t = localtime(&timer);

	std::cout << "[" << t->tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2) << t->tm_mon + 1;
	std::cout << std::setfill('0') << std::setw(2) << t->tm_mday << "_";
	std::cout << std::setfill('0') << std::setw(2) << t->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << t->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << t->tm_sec << "] ";
}