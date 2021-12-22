/*

#include "Checking.h"

#include <iostream>

Checking::Checking(double balance, double feePerTransaction)
	: Account(balance),
	  m_feePerTransaction(feePerTransaction)
{
}

void Checking::credit(double amount)
{
	if (Account::debt(m_feePerTransaction))
	{ 
		Account::credit(amount);
	}
	else {
		std::cout << "[ERROR] Unable to credit, not enough funds in account to cover fees" << std::endl;
	}
}

void Checking::debt(double amount)
{
	if (Account::debt(m_feePerTransaction))
	{
		Account::debt(amount);
	}
	else {
		std::cout << "[ERROR] Unable to debt, not enough funds in account to cover fees" << std::endl;
	}
}

*/