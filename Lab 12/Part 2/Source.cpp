/*

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


#include "Account.h"
#include "Checking.h"
#include "Savings.h"

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

*/