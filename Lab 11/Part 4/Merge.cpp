///
///
/// Account.h
/// 
/// 

//#pragma once
class Account
{
public:

	explicit Account(double balance);

	void credit(double amount);
	bool debt(double amount);

	double getBalance();

private:

	double m_balance;
};

///
///
/// Account.cpp
/// 
/// 

//#include "Account.h"

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

///
///
/// Savings.h
/// 
/// 

//#pragma once
//#include "Account.h"
class Savings : public Account
{
public:
	explicit Savings(double balance, double interestRate);

	double calculateInterest();

private:

	double m_interestRate;
};

///
///
/// Savings.cpp
/// 
/// 

//#include "Savings.h"

Savings::Savings(double balance, double interestRate)
	: Account(balance),
	m_interestRate(interestRate)
{
}

double Savings::calculateInterest()
{
	return getBalance() * m_interestRate;
}

///
///
/// Checking.h
/// 
/// 

//#pragma once
//#include "Account.h"
class Checking : public Account
{
public:

	explicit Checking(double balance, double feePerTransaction);

	void credit(double amount);
	void debt(double amount);

private:

	double m_feePerTransaction;
};

///
///
/// Checking.cpp
/// 
/// 

//#include "Checking.h"

//#include <iostream>

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

///
///
/// Source.cpp
/// 
/// 

// Name: -----	ID: -----

// ************************ PART 4 ************************

// (Account Inheritance Hierarchy) Create an inheritance hierarchy that a bank might use to represent customers’ bank accounts. All customers at this bank can deposit (i.e., credit) money into their accounts and withdraw (i.e., debit) money from their accounts. More specific types of accounts also exist. Savings accounts, for instance, earn interest on the money they hold. Checking accounts, on the other hand, charge a fee per transaction (i.e., credit or debit).

// Create an inheritance hierarchy containing base class Accountand derived classes Savings - Account and CheckingAccount that inherit from class Account.Base class Account should include one data member of type double to represent the account balance.The class should provide a constructor that receives an initial balance and uses it to initialize the data member.The constructor should validate the initial balance to ensure that it’s greater than or equal to 0.0.If not, the balance should be set to 0.0 and the constructor should display an error message, indicating that the initial balance was invalid.The class should provide three member functions.Member function credit should add an amount to the current balance.Member function debit should withdraw money from the Accountand ensure that the debit amount does not exceed the Account’s balance.If it does, the balance should be left unchangedand the function should print the message "Debit amount exceeded account balance." Member function getBalance should return the current balance.

// Derived class SavingsAccount should inherit the functionality of an Account, but also include a data member of type double indicating the interest rate(percentage) assigned to the Account.SavingsAccount’s constructor should receive the initial balance, as well as an initial value for the SavingsAccount’s interest rate.SavingsAccount should provide a public member function calculateInterest that returns a double indicating the amount of interest earned by an account.Member function calculateInterest should determine this amount by multiplying the interest rate by the account balance.[Note:SavingsAccount should inherit member functions credit and debit as is without redefining them.]

// Derived class CheckingAccount should inherit from base class Accountand include an additional data member of type double that represents the fee charged per transaction.Checking - Account’s constructor should receive the initial balance, as well as a parameter indicating a fee amount.Class CheckingAccount should redefine member functions creditand debit so that they subtract the fee from the account balance whenever either transaction is performed successfully.CheckingAccount’s versions of these functions should invoke the base - class Account version to perform the updates to an account balance.CheckingAccount’s debit function should charge a fee only if money is actually withdrawn(i.e., the debit amount does not exceed the account balance).[Hint:Define Account’s debit function so that it returns a bool indicating whether money was withdrawn.Then use the return value to determine whether a fee should be charged.]

// After defining the classes in this hierarchy, write a program that creates objects of each classand tests their member functions.Add interest to the SavingsAccount object by first invoking its calculateInterest function, then passing the returned interest amount to the object’s credit function.A sample output is shown in the following figure.


//#include <iostream>

//#include "Account.h"
//#include "Checking.h"
//#include "Savings.h"

// Program entry function
int main(void)
{

	// Print the title of the project (optional)
	std::cout << "-----------====== Account Deriving ======-----------" << std::endl;

	Account a1 = Account(0);
	Savings a2 = Savings(25, 0.25);
	Checking a3 = Checking(30, 1);

	std::cout << "Current Balances: " << std::endl;
	std::cout << "Account 1: " << a1.getBalance() << std::endl;
	std::cout << "Account 2: " << a2.getBalance() << std::endl;
	std::cout << "Account 3: " << a3.getBalance() << std::endl;

	std::cout << "Attempting to debt account 1 30$ (should fail)" << std::endl;
	a1.debt(30);

	std::cout << "\nCurrent Balance: " << std::endl;
	std::cout << "Account 1: " << a1.getBalance() << std::endl;

	std::cout << "\nAttempting to calculate interest on account 2 (with 25% interest rate)" << std::endl;
	a2.credit(a2.calculateInterest());

	std::cout << "\nCurrent Balance: " << std::endl;
	std::cout << "Account 2: " << a2.getBalance() << std::endl;

	std::cout << "\nAttempting to credit account 3 20$ (should be charged 1$ fee)" << std::endl;
	a3.credit(20);

	std::cout << "\nCurrent Balance: " << std::endl;
	std::cout << "Account 3: " << a3.getBalance() << std::endl;


} // End entry function