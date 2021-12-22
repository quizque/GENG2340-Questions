/*

#include "SavingsAccount.h"

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

*/