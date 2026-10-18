/*
    2. Create a class Point with data members as x,y. Create Default and Parameterized constructors.
    Write getters and setters for all the data members. Also add the display function.
    Create the object of this class in main method and invoke all the methods in that class.
*/

#include <iostream>
using namespace std;

class Point
{
	private:
		int x;
		int y;

	public:
		// Default constructor
		Point()
		{
			x = 0;
			y = 0;
		}

		// Parameterized constructor
		Point(int xValue, int yValue)
		{
			x = xValue;
			y = yValue;
		}

		// Setter for x
		void setX(int xValue)
		{
			x = xValue;
		}

		// Setter for y
		void setY(int yValue)
		{
			y = yValue;
		}

		// Getter for x
		int getX()
		{
			return x;
		}

		// Getter for y
		int getY()
		{
			return y;
		}

		// Display point
		void display()
		{
			cout << "Point: (" << x << ", " << y << ")" << endl;
		}
};

int main()
{
	Point p1;

	cout << "Default Constructor:";
	p1.display();

	p1.setX(10);
	p1.setY(20);

	cout << "\nAfter using Setters:";
	p1.display();

	cout << "\nX = " << p1.getX();
	cout << "\nY = " << p1.getY();

	Point p2(30, 40);

	cout << "\n\nParameterized Constructor:";
	p2.display();

	return 0;
}