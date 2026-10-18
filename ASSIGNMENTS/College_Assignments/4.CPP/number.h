#pragma once

#include<iostream>
using namespace std;

class Number
{
private:
    int* no;

public:

    // Parameterized Constructor
    Number(int no)
    {
        this->no = new int;
        *(this->no) = no;
    }

    // Copy Constructor - Deep Copy
    Number(Number& copyObj)
    {
        this->no = new int;
        *(this->no) = *(copyObj.no);
    }

    // Display
    void display()
    {
        cout << "\nThe number is: " << *(this->no);
    }

    // Destructor
    ~Number()
    {
        if (this->no != NULL)
        {
            delete this->no;
            this->no = NULL;
        }
    }
};