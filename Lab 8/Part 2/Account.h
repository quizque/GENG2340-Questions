#pragma once

// Define account class
class Account
{
public:

	// Define the constructor
	explicit Account(int _balance);

	// Define method credit and debt
	void credit(int amount);
	void debt(int amount);

	// Define getters
	int getBalance() const;

private:
	// Define balance
	int balance;
};

