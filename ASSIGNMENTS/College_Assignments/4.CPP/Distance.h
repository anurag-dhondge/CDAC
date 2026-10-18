#pragma once

#include <iostream>
using namespace std;

class Distance
{
private:
    float feet;
    float inches;

public:

    // Parameterized Constructor
    Distance(float feet, float inches)
    {
        this->feet = feet;
        this->inches = inches;
    }

    // Display
    void display()
    {
        cout << "\nFeet: " << feet;
        cout << "\nInches: " << inches;
    }

    // Operator + Overloading
    Distance operator+(Distance& obj)
    {
        Distance temp(0, 0);

        temp.feet = this->feet + obj.feet;
        temp.inches = this->inches + obj.inches;

        // Convert inches into feet
        if (temp.inches >= 12)
        {
            temp.feet = temp.feet + (temp.inches / 12);
            temp.inches = (int)temp.inches % 12;
        }

        return temp;
    }

    // Operator == Overloading
    bool operator==(Distance& obj)
    {
        if (this->feet == obj.feet &&
            this->inches == obj.inches)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};