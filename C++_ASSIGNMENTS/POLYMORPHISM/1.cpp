/*
    1. Implement a C++ program that demonstrates compile-time polymorphism using function
    overloading. Create a class called Calculator with the following member functions:

    1. calculateArea(int): Calculates and returns the area of a square with the given side length

    2. calculateArea(int, int): Calculates and returns the area of a rectangle with the given
    length and width

    3. calculateArea(double, double): Calculates and returns the area of an ellipse with the
    given major and minor axes
*/

#include <iostream>
using namespace std;

class Calculator
{
	public:
		// Area of square
		int calculateArea(int side)
		{
			return side * side;
		}

		// Area of rectangle
		int calculateArea(int length, int width)
		{
			return length * width;
		}

		// Area of ellipse
		double calculateArea(double majorAxis, double minorAxis)
		{
			return 3.14159 * majorAxis * minorAxis;
		}
};

int main()
{
	Calculator calculator;

	cout << "Area of Square: ";
	cout << calculator.calculateArea(5);

	cout << "\nArea of Rectangle: ";
	cout << calculator.calculateArea(10, 20);

	cout << "\nArea of Ellipse: ";
	cout << calculator.calculateArea(5.0, 3.0);

	return 0;
}