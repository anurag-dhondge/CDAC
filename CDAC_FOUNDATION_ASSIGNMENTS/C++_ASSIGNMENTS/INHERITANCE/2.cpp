/*
    2. Implement given Inheritance. Define a base class Shape with properties like area and perimeter.
    Create derived classes like Circle, Rectangle, and Triangle. Accept suitable attributes as per shape.
    [Hierarchical Inheritance]
*/

#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
	protected:
		double area;
		double perimeter;
};

class Circle : public Shape
{
	private:
		double radius;

	public:
		void accepts()
		{
			cout << "Enter Radius: ";
			cin >> radius;
		}

		void calculate()
		{
			area = 3.14159 * radius * radius;
			perimeter = 2 * 3.14159 * radius;
		}

		void display()
		{
			cout << "\nArea of Circle: " << area;
			cout << "\nPerimeter of Circle: " << perimeter;
		}
};

class Rectangle : public Shape
{
	private:
		double length;
		double width;

	public:
		void accepts()
		{
			cout << "Enter Length: ";
			cin >> length;

			cout << "Enter Width: ";
			cin >> width;
		}

		void calculate()
		{
			area = length * width;
			perimeter = 2 * (length + width);
		}

		void display()
		{
			cout << "\nArea of Rectangle: " << area;
			cout << "\nPerimeter of Rectangle: " << perimeter;
		}
};

class Triangle : public Shape
{
	private:
		double side1;
		double side2;
		double side3;

	public:
		void accepts()
		{
			cout << "Enter Three Sides: ";
			cin >> side1 >> side2 >> side3;
		}

		void calculate()
		{
			perimeter = side1 + side2 + side3;

			double semiPerimeter = perimeter / 2;

			area = sqrt(semiPerimeter *
						(semiPerimeter - side1) *
						(semiPerimeter - side2) *
						(semiPerimeter - side3));
		}

		void display()
		{
			cout << "\nArea of Triangle: " << area;
			cout << "\nPerimeter of Triangle: " << perimeter;
		}
};

int main()
{
	Circle circle;
	Rectangle rectangle;
	Triangle triangle;

	cout << "Circle Details:\n";
	circle.accepts();
	circle.calculate();
	circle.display();

	cout << "\n\nRectangle Details:\n";
	rectangle.accepts();
	rectangle.calculate();
	rectangle.display();

	cout << "\n\nTriangle Details:\n";
	triangle.accepts();
	triangle.calculate();
	triangle.display();

	return 0;
}