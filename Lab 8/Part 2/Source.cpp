// Name: -----	ID: -----

// ************************ PART 2 ************************

// (Account Class) Create an Account class that a bank might use to represent customers’ bank accounts. 
// Include a data member of type int to represent the account balance.Provide a constructor that receives an
// initial balanceand uses it to initialize the data member.The constructor should validate the initial balance
// to ensure that it’s greater than or equal to 0. If not, set the balance to 0 and display  an  error  message
// indicating  that  the  initial  balance  was  invalid.Provide  three  member  functions.Member  function  credit
// should add an amount to the current balance.Member function debit should withdraw money from the
// Account and ensure that the debit amount does not exceed the Account’s balance.If it does, the balance
// should  be  left  unchangedand the  function  should  print  a  message  indicating  "Debit  amount  exceeded 
// account balance." Member function getBalance should return the current balance. Create a program that 
// creates two Account objects and tests the member functions of class Accoun


#include <iostream>
#include "Account.h"


// Program entry function
int main(void)
{

	// Print the title of the project (optional)
	std::cout << "-----------====== Account Class Demo ======-----------" << std::endl;

	// Run the tests on the first account
	std::cout << "\nTesting account1." << std::endl;
	std::cout << "Defining the first account with 100$ balance." << std::endl;
	// Define account1 with 100$ balance
	Account account1 = Account(100);

	std::cout << "Balance in account1: " << account1.getBalance() << "$" << std::endl;

	std::cout << "Applying 20$ credit to account1." << std::endl;
	// Run credit method on account 1
	account1.credit(20);
	std::cout << "Balance in account1: " << account1.getBalance() << "$" << std::endl;

	std::cout << "Applying 150$ debt to account1." << std::endl;
	// Run debt method on account 1 (should error)
	account1.debt(150);
	std::cout << "Balance in account1: " << account1.getBalance() << "$" << std::endl;

	// Run the tests on the second account
	std::cout << "\n\nTesting account2." << std::endl;
	std::cout << "Defining the second account with -300$ balance." << std::endl;
	// Define account2 with -300$ balance (should error)
	Account account2 = Account(-300);

	std::cout << "Balance in account2: " << account2.getBalance() << "$" << std::endl;

	std::cout << "Applying 300$ credit to account2." << std::endl;
	// Apply 300$ credit to account 2
	account2.credit(300);
	std::cout << "Balance in account2: " << account2.getBalance() << "$" << std::endl;

	std::cout << "Applying 175$ debt to account2." << std::endl;
	// Apply 175$ debt to account 2
	account2.debt(175);
	std::cout << "Balance in account2: " << account2.getBalance() << "$" << std::endl;

} // End entry function