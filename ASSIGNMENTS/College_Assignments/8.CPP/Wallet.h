#pragma once

#include <iostream>
#include <string>
using namespace std;

#include "InvalidAmountException.h"
#include "InsufficientBalanceException.h"

class Wallet
{
private:
    int walletId;
    string holderName;
    double balance;

public:

    // Default Constructor
    Wallet()
    {
        walletId = 0;
        holderName = "NA";
        balance = 0;
    }

    // Parameterized Constructor
    Wallet(int walletId, string holderName, double balance)
    {
        this->walletId = walletId;
        this->holderName = holderName;

        if (balance < 0)
        {
            InvalidAmountException ex("Balance cannot be negative");
            throw ex;
        }

        this->balance = balance;
    }

    // Add Money
    void addMoney(double amount)
    {
        if (amount <= 0)
        {
            InvalidAmountException ex("Amount must be greater than zero");
            throw ex;
        }

        this->balance = this->balance + amount;
    }

    // Withdraw Money
    void withdrawMoney(double amount)
    {
        if (amount <= 0)
        {
            InvalidAmountException ex("Amount must be greater than zero");
            throw ex;
        }

        if (amount > this->balance)
        {
            InsufficientBalanceException ex("Insufficient wallet balance");
            throw ex;
        }

        this->balance = this->balance - amount;
    }

    // Operator << 
    friend ostream& operator<<(ostream& o, Wallet& obj);

    // Operator >>
    friend istream& operator>>(istream& i, Wallet& obj);
};


// Insertion Operator
ostream& operator<<(ostream& o, Wallet& obj)
{
    o << "\nWallet Details";
    o << "\nWallet ID: " << obj.walletId;
    o << "\nHolder Name: " << obj.holderName;
    o << "\nBalance: " << obj.balance;
    o << endl;

    return o;
}


// Extraction Operator
istream& operator>>(istream& i, Wallet& obj)
{
    cout << "\nEnter Wallet ID: ";
    i >> obj.walletId;

    cout << "Enter Holder Name: ";
    i >> obj.holderName;

    cout << "Enter Balance: ";
    i >> obj.balance;

    if (obj.balance < 0)
    {
        InvalidAmountException ex("Balance cannot be negative");
        throw ex;
    }

    return i;
}