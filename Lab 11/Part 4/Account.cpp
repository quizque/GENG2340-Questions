/*

#include "Account.h"

#include <iostream>

Account::Account(double balance)
	: m_balance(balance)
{
	if (m_balance < 0)
	{
		std::cout << "[ERROR] Invalid balance, defaulting to zero." << std::endl;
		m_balance = 0;
	}
}

void Account::credit(double amount)
{
	m_balance += amount;
}

bool Account::debt(double amount)
{
	if (amount > m_balance)
	{
		std::cout << "[ERROR] Debit amount exceeded account balance." << std::endl;
		return false;
	}
	else {
		m_balance -= amount;
		return true;
	}
}

double Account::getBalance()
{
	return m_balance;
}

*/