#pragma once

#include<iostream>
#include<string>
#include"Customer.h"
#include"Product.h"
using namespace std;

class Order
{
private:
    int orderId;
    Customer c1;
    Product p1;

public:

    Order()
    {
        orderId = 0;
    }

    Order(int cno, string name, long long phone,
          int proid, string pname, float pprice,
          int quantity, int ord)
        : c1(cno, name, phone),
          p1(proid, pname, pprice, quantity)
    {
        orderId = ord;
    }

    void displayOrder()
    {
        cout << "\nOrder Id: " << orderId;

        c1.displayCustomer();

        p1.displayProduct();

        cout << "\nTotal Order Amount: " << p1.getTotal();

        cout << "\n";
    }
};