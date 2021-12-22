#include "Account.h"

#include <iostream>

Account::Account(int _balance)
	: balance(_balance)
{
	// If _balance is above zero, set it to the accounts balance
	if (_balance <= 0)
	{
		std::cout << "Invalid account balance given, defaulting to zero..." << std::endl;
		balance = 0;
	}
}

void Account::credit(int amount)
{
	// Apply credit to account
	balance += amount;
}

void Account::debt(int amount)
{
	// If the debt amount would result in a negative result, error
	if (balance - amount < 0)
	{
		std::cout << "Debit amount exceeded account balance." << std::endl;
	}
	else {
		// Otherwise, apply the debt
		balance -= amount;
	}
}

int Account::getBalance() const
{
	// Return the balance
	return balance;
}
