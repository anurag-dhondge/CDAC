#pragma once

#include <iostream>
using namespace std;

class Complex
{
private:
    float real, imag;

public:

    // Parameterized Constructor
    Complex(float real, float imag)
    {
        this->real = real;
        this->imag = imag;
    }

    // Display
    void display()
    {
        cout << "\nReal: " << real;
        cout << "\nImaginary: " << imag;
    }

    // Operator Overloading +
    Complex operator+(Complex& obj)
    {
        Complex temp(0, 0);

        temp.real = this->real + obj.real;
        temp.imag = this->imag + obj.imag;

        return temp;
    }
};