// Name: -----    ID: -----

// ************************ PART 7 ************************

// (Calculating Credit Limits) Collecting money becomes increasingly difficult during periods of recession, so companies may tighten their credit limits to prevent their accounts receivable (money owed to them) from becoming too large. In response to a prolonged recession, one company has cut its customers’ credit limits in half. Thus, if a particular customer had a credit limit of $2000, it’s now $1000. If a customer had a credit limit of $5000, it’s now $2500. Write a program that analyzes the credit status of three customers of this company. For each customer you’re given:

// a) The customer’s account number

// b) The customer’s credit limit before the recession

// c) The customer’s current balance(i.e., the amount the customer owes the company).

// Your program should calculateand print the new credit limit for each customerand should

//Your program should calculateand print the new credit limit for each customerand should determine(and print) which customers have current balances that exceed their new credit limits.


#include <stdio.h>


// Program entry function
int main(void)
{
	for (int i = 1; i <= 3; i++)
	{
		// Define account number, credit limit, and current balance
		int accountNumber, creditLimit, currentBalance;

		// Print the title
		printf("--========= Credit Calculator for Account %d =========--\n", i);

		// Ask for account number
		printf("Enter an account number: ");
		scanf_s("%d", &accountNumber);

		// Ask for current credit limit
		printf("Enter the accounts credit limit: ");
		scanf_s("%d", &creditLimit);

		// Ask for current balance
		printf("Enter the accounts current balance: ");
		scanf_s("%d", &currentBalance);

		// Give us more space before printing again
		puts("\n");

		// Print the new credit limit (rounded down)
		printf("The new credit limit is now: $%d\n", creditLimit / 2);

		// If the current balance is greater then the credit limit,
		// print that we are exceeding, otherwise, say we are in limits.
		if (currentBalance > creditLimit / 2) {
			printf("The account is currently exceeding its limit!\n\n");
		}
		else {
			printf("The account is currently within its limit.\n\n");
		}
	}

} // End entry function