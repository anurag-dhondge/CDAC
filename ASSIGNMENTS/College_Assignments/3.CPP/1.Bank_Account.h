/*  1.  Bank Account
        Create a BankAccount class with account number, customer name, and balance. Use a
        constructor to initialize account details. Implement member functions to deposit, withdraw,
        and display the balance. Create multiple account objects using an array of objects.
*/

#pragma once
#include<iostream>
#include<string>
using namespace std;

class BankAccount
{
	private:
		int accountno;
		string customername;
		float balance;

	public:
		BankAccount()
		{
			accountno = 0;
			customername = "";
			balance = 0;
		}

		BankAccount(int a, string n, float b)
		{
			accountno = a;
			customername = n;
			balance = b;
		}

		void accept()
		{
			cout<<"\n Enter account no: ";
			cin>>accountno;

			cout<<" Enter customer name: ";
			cin>>customername;

			cout<<" Enter balance: ";
			cin>>balance;
		}

		void deposit()
		{
			float amount;

			cout<<"\n Enter amount to deposit: ";
			cin>>amount;

			balance = balance + amount;
		}

		void withdraw()
		{
			float amount;

			cout<<"\n Enter amount to withdraw: ";
			cin>>amount;

			if(amount <= balance)
				balance = balance - amount;
			else
				cout<<"\n Insufficient balance";
		}

		void display()
		{
			cout<<"\n Account No: "<<accountno;
			cout<<"\n Customer Name: "<<customername;
			cout<<"\n Balance: "<<balance;
		}
};