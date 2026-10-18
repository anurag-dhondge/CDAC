/*
Question 1

C++ Assignment: Custom Exceptions and Stream Operator Overloading

Domain: Banking / Digital Wallet System
*/

#include "Wallet.h"

int main()
{
    Wallet w;

    int choice;
    double amount;

    do
    {
        cout << "\n\nDigital Wallet";
        cout << "\n1. Create Wallet";
        cout << "\n2. Add Money";
        cout << "\n3. Withdraw Money";
        cout << "\n4. Display Wallet Details";
        cout << "\n5. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            try
            {
                cin >> w;

                cout << "\nWallet created successfully.";
                cout << w;
            }
            catch (InvalidAmountException err)
            {
                cout << "\nError: " << err.what();
            }

            break;


        case 2:

            try
            {
                cout << "\nEnter amount to add: ";
                cin >> amount;

                w.addMoney(amount);

                cout << "\nMoney added successfully.";
                cout << w;
            }
            catch (InvalidAmountException err)
            {
                cout << "\nError: " << err.what();
            }

            break;


        case 3:

            try
            {
                cout << "\nEnter amount to withdraw: ";
                cin >> amount;

                w.withdrawMoney(amount);

                cout << "\nMoney withdrawn successfully.";
                cout << w;
            }
            catch (InvalidAmountException err)
            {
                cout << "\nError: " << err.what();
            }
            catch (InsufficientBalanceException err)
            {
                cout << "\nError: " << err.what();
            }

            break;


        case 4:

            cout << w;

            break;


        case 5:

            cout << "\nThank you!";

            break;


        default:

            cout << "\nInvalid choice.";
        }

    } while (choice != 5);

    return 0;
}