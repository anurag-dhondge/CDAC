/*
    3. Implement a C++ program for Binary Operator Overloading to Subtract two Complex Number.
*/

#include <iostream>
using namespace std;

class Complex
{
	private:
		float real;
		float imaginary;

	public:
		// Default constructor
		Complex()
		{
			real = 0;
			imaginary = 0;
		}

		// Parameterized constructor
		Complex(float r, float i)
		{
			real = r;
			imaginary = i;
		}

		// Binary operator overloading
		Complex operator-(Complex c)
		{
			Complex result;

			result.real = real - c.real;
			result.imaginary = imaginary - c.imaginary;

			return result;
		}

		// Display complex number
		void display()
		{
			cout << real;

			if (imaginary >= 0)
			{
				cout << " + " << imaginary << "i";
			}
			else
			{
				cout << " - " << -imaginary << "i";
			}
		}
};

int main()
{
	Complex c1(10, 20);
	Complex c2(5, 8);

	Complex c3 = c1 - c2;

	cout << "First Complex Number: ";
	c1.display();

	cout << "\nSecond Complex Number: ";
	c2.display();

	cout << "\nResult after Subtraction: ";
	c3.display();

	return 0;
}