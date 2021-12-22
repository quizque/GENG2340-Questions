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
		std::cout << "[INFO] Applied $" << this->m_feePerTransaction << " trasaction fee" << std::endl;
		Account::credit(amount);
	}
	else {
		std::cout << "[ERROR] Unable to credit, not enough funds in account to cover fees" << std::endl;
	}
}

bool Checking::debt(double amount)
{
	if (Account::debt(m_feePerTransaction))
	{
		std::cout << "[INFO] Applied $" << this->m_feePerTransaction << " trasaction fee" << std::endl;
		Account::debt(amount);
		return true;
	}
	else {
		std::cout << "[ERROR] Unable to debt, not enough funds in account to cover fees" << std::endl;
		return false;
	}
}

*/