/*
    12. Create a simple ATM menu using switch-case with options
        such as Check Balance, Deposit, Withdraw, and Exit.
        Maintain the balance during the program execution.
*/

#include <iostream>
using namespace std;

void ATM(int choice, float &balance)
{
    float amount;
    char wish;
    do
    {
        switch(choice)
        {
            case 1:
                cout << "\nBalance = " << balance;
                break;

            case 2:
                cout << "\nEnter deposit amount: ";
                cin >> amount;

                if(amount > 0)
                {
                    balance = balance + amount;
                    cout << "Amount deposited successfully";
                    cout << "\nNew Balance = " << balance;
                }

                else
                {
                    cout << "Invalid amount";
                }

                break;

            case 3:
                cout << "\nEnter withdrawal amount: ";
                cin >> amount;

                if(amount > 0 && amount <= balance)
                {
                    balance = balance - amount;
                    cout << "Amount withdrawn successfully";
                    cout << "\nNew Balance = " << balance;
                }

                else
                {
                    cout << "Insufficient balance or invalid amount";
                }

                break;

            case 4:
                cout << "\nThank you for using ATM";
                return;

            default:
                cout << "\nInvalid choice";
                break;
        }

        cout << "\n\nDo you wish to continue? (Y/N): ";
        cin >> wish;

        if(wish == 'y' || wish == 'Y')
        {
            cout << "\n1. Check Balance";
            cout << "\n2. Deposit";
            cout << "\n3. Withdraw";
            cout << "\n4. Exit";

            cout << "\nEnter choice: ";
            cin >> choice;
        }

    } while(wish == 'y' || wish == 'Y');
}

int main()
{
    int choice;
    float balance = 1000;

    cout << "*****ATM MENU*****";
    cout << "\n1. Check Balance";
    cout << "\n2. Deposit";
    cout << "\n3. Withdraw";
    cout << "\n4. Exit";

    cout << "\nEnter choice: ";
    cin >> choice;

    ATM(choice, balance);

    return 0;
}