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

	virtual void credit(double amount);
	virtual bool debt(double amount);

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
/// Checking.h
/// 
/// 

//#pragma once
//#include "Account.h"
class Checking : public Account
{
public:

	explicit Checking(double balance, double feePerTransaction);

	virtual void credit(double amount) override;
	virtual bool debt(double amount) override;

private:

	double m_feePerTransaction;
};

///
///
/// Checking.cpp
/// 
/// 

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
/// Source.cpp
/// 
/// 



// Name: -----	ID: -----

// ************************ PART 2 ************************

// (Polymorphic Banking Program Using Account Hierarchy) Develop  a  polymorphic  banking  
// program  using  the  Account hierarchy  created  for  Lab_11  question  #4  to create  a  vector of  Account
// pointers to SavingsAccount and CheckingAccount objects.For each Account in the vector, allow the user
// to  specify  an  amount  of  money  to  withdraw  from  the  Account using  member  function  debitand an
// amount  of  money  to  deposit  into  the  Account using  member  function  credit.As  you  process  each
// Account, determine its type.If an Account is a SavingsAccount, calculate the amount of interest owed to
// the Account using member function calculateInterest, then add the interest to the account balance using
// member function credit.After processing an Account, print the updated account balance obtained by
// invoking base - class member function getBalance.A sample output is shown in Fig. 2.


#include <iostream>
#include <iomanip>
#include <vector>


//#include "Account.h"
//#include "Checking.h"
//#include "Savings.h"

using namespace std;

int main()
{
	// set floating-point output formatting
	cout << fixed << setprecision(2);

	std::vector<Account*> accounts = {
		new Savings(95, 0.50),
		new Savings(25, 0.25),
		new Checking(30, 1)
	};

	for (int i = 0; i != accounts.size(); i++)
	{
		cout << "\n\nAccount " << i + 1 << " balance: " << accounts[i]->getBalance() << endl;

		double widthdraw;
		double deposit;

		cout << "Enter an amount to withdraw from Account " << i + 1 << ": ";
		cin >> widthdraw;
		accounts[i]->debt(widthdraw);

		cout << "Enter an amount to deposit from Account " << i + 1 << ": ";
		cin >> deposit;
		accounts[i]->credit(deposit);

		Savings* a = dynamic_cast<Savings*>(accounts[i]);

		if (a != NULL)
		{
			cout << "Account is of type Savings" << endl;
			cout << "Adding $" << a->calculateInterest() << " interest to account " << i + 1 << endl;
			a->credit(a->calculateInterest());
		}
		else {
			cout << "Account is of type Checking" << endl;
		}

		cout << "Updated Account " << i + 1 << " balance: " << accounts[i]->getBalance() << endl;
	}


} // end main