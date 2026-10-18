/*  1.  Bank Account
        Create a BankAccount class with account number, customer name, and balance. Use a
        constructor to initialize account details. Implement member functions to deposit, withdraw,
        and display the balance. Create multiple account objects using an array of objects.
*/


#include"1.Bank_Account.h"

int main()
{
	int noa;

	cout<<"\n Enter number of accounts: ";
	cin>>noa;

	BankAccount* barr = new BankAccount[noa];

	for(int i = 0 ; i < noa ; i++)
	{
		cout<<"\n Enter details of account "<<i+1;
		barr[i].accept();
	}

	for(int i = 0 ; i < noa ; i++)
	{
		cout<<"\n\n Account "<< i + 1;
		barr[i].display();
	}

	int choice;

	cout<<"\n\n Enter account number/index for transaction: ";
	cin>>choice;

	barr[choice-1].deposit();

	cout<<"\n\n After deposit:";
	barr[choice-1].display();

	barr[choice-1].withdraw();

	cout<<"\n\n After withdrawal:";
	barr[choice-1].display();

	delete[] barr;
}