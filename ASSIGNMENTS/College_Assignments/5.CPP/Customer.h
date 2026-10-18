#pragma once

#include<iostream>
#include<string>
using namespace std;

class Customer
{
private:
    int customerNo;
    string name;
    long long phoneNo;

public:

    Customer()
    {
        customerNo = 0;
        name = "NA";
        phoneNo = 0;
    }

    Customer(int cno, string name, long long phone)
    {
        customerNo = cno;
        this->name = name;
        phoneNo = phone;
    }

    void displayCustomer()
    {
        cout << "\nCustomer Number: " << customerNo;
        cout << "\nName: " << name;
        cout << "\nPhone Number: " << phoneNo;
    }
};