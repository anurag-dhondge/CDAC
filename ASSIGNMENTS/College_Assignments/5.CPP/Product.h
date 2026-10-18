#pragma once

#include<iostream>
#include<string>
using namespace std;

class Product
{
private:
    int productId;
    string productName;
    float price;
    int quantity;

public:

    Product()
    {
        productId = 0;
        productName = "NA";
        price = 0.0f;
        quantity = 0;
    }

    Product(int productId, string productName, float price, int quantity)
    {
        this->productId = productId;
        this->productName = productName;
        this->price = price;
        this->quantity = quantity;
    }

    void displayProduct()
    {
        cout << "\nProduct ID: " << productId;
        cout << "\nProduct Name: " << productName;
        cout << "\nProduct Price: " << price;
        cout << "\nQuantity: " << quantity;
    }

    float getTotal()
    {
        return price * quantity;
    }
};