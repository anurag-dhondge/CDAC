/*
    3. Create a class ComplexNumber with data members real, imaginary. Create Default and
    Parameterized constructors. Write getters and setters for all the data members.
    Also add the display function. Create the object of this class in main method and invoke
    all the methods in that class.
*/

#include <iostream>
using namespace std;

class ComplexNumber
{
	private:
		float real;
		float imaginary;

	public:
		// Default constructor
		ComplexNumber()
		{
			real = 0;
			imaginary = 0;
		}

		// Parameterized constructor
		ComplexNumber(float realValue, float imaginaryValue)
		{
			real = realValue;
			imaginary = imaginaryValue;
		}

		// Setter for real
		void setReal(float realValue)
		{
			real = realValue;
		}

		// Setter for imaginary
		void setImaginary(float imaginaryValue)
		{
			imaginary = imaginaryValue;
		}

		// Getter for real
		float getReal()
		{
			return real;
		}

		// Getter for imaginary
		float getImaginary()
		{
			return imaginary;
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

			cout << endl;
		}
};

int main()
{
	ComplexNumber c1;

	cout << "Default Constructor:";
	c1.display();

	c1.setReal(10);
	c1.setImaginary(5);

	cout << "\nAfter using Setters:";
	c1.display();

	cout << "\nReal = " << c1.getReal();
	cout << "\nImaginary = " << c1.getImaginary();

	ComplexNumber c2(20, 15);

	cout << "\n\nParameterized Constructor:";
	c2.display();

	return 0;
}