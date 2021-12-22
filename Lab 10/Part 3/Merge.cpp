///
///
/// SavingsAccount.h
/// 
/// 

//#pragma once
class SavingsAccount
{
public:
	static void modifyInterestRate(float new_rate);

	explicit SavingsAccount(float balance);

	float getBalance();

	void calculateMonthlyInterest();


private:

	static float s_annual_interest_rate;

	float m_savings_balance;
};



///
///
/// SavingsAccount.cpp
/// 
/// 

//#include "SavingsAccount.h"

float SavingsAccount::s_annual_interest_rate = 0.0f;

void SavingsAccount::modifyInterestRate(float new_rate)
{
	s_annual_interest_rate = new_rate;
}

SavingsAccount::SavingsAccount(float balance)
	: m_savings_balance(balance)
{
}

float SavingsAccount::getBalance()
{
	return m_savings_balance;
}

void SavingsAccount::calculateMonthlyInterest()
{
	m_savings_balance += m_savings_balance * (s_annual_interest_rate / 12.0f);
}


///
///
/// Source.cpp
/// 
/// 

// Name: -----	ID: -----

// ************************ PART 3 ************************

// Create a SavingsAccount class. Use a static data member annual-InterestRate to store the annual interest rate for each of the savers. Each member of the class contains a private data member savingsBalance indicating the amount the saver currently has on deposit. Provide member function calculateMonthlyInterest that calculates the monthly interest by multiplying the savingsBalance by annualInterestRate divided by 12; this interest should be added to savingsBalance. Provide a static member function modifyInterestRate that sets the static annualInterestRate to a new value. Write a driver program to test class SavingsAccount. Instantiate two different objects of class SavingsAccount, saver1 and saver2, with balances of $2000.00 and $3000.00, respectively. Set the annualInterestRate to 3 percent. Then calculate the monthly interest and print the new balances for each of the savers. Then set the annualInterestRate to 4 percent, calculate the next month’s interest and print the new balances for each of the savers.


#include <iostream>

//#include "SavingsAccount.h"


// Program entry function
int main(void)
{

	// Print the title of the project (optional)
	std::cout << "-----------====== SavingsAccount Class Demo ======-----------" << std::endl;

	SavingsAccount saver1 = SavingsAccount(2000.0f);
	SavingsAccount saver2 = SavingsAccount(3000.0f);

	std::cout << "Current balance of saver1: $" << saver1.getBalance() << std::endl;
	std::cout << "Current balance of saver2: $" << saver2.getBalance() << std::endl;

	std::cout << "\nCalulating this month new balance when interest when set to 3%" << std::endl;
	SavingsAccount::modifyInterestRate(0.03f);
	saver1.calculateMonthlyInterest();
	saver2.calculateMonthlyInterest();

	std::cout << "\nCurrent balance of saver1: $" << saver1.getBalance() << std::endl;
	std::cout << "Current balance of saver2: $" << saver2.getBalance() << std::endl;

	std::cout << "\nCalulating this month new balance when interest when set to 4%" << std::endl;
	SavingsAccount::modifyInterestRate(0.04f);
	saver1.calculateMonthlyInterest();
	saver2.calculateMonthlyInterest();

	std::cout << "\nCurrent balance of saver1: $" << saver1.getBalance() << std::endl;
	std::cout << "Current balance of saver2: $" << saver2.getBalance() << std::endl;


} // End entry function