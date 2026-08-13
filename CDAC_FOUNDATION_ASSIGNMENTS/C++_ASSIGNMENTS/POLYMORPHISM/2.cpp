/*
    2. Create a C++ program that demonstrates runtime polymorphism using virtual functions
    and pointers to the base class. The program should simulate a simple graphics system
    with different shapes.

    i. Create a base class Shape with the following attributes:
    - color (string), filled (boolean)
    ii. Implement the following virtual functions in the Shape class:
    - draw()
    - getArea()
    - getPerimeter()
    iii. Create three derived classes Circle, Rectangle, and Triangle that inherit from Shape.
    iv. In the Circle class, override the draw() function to display a message indicating
    that a circle is being drawn.
    v. In the Rectangle class, override the getArea() function to calculate and return
    the area of the rectangle.
    vi. In the Triangle class, override the getPerimeter() function to calculate and return
    the perimeter of the triangle.
    vii. Create pointers to the Shape class and dynamically allocate objects of Circle,
    Rectangle and Triangle.
    viii. Call the virtual functions through the pointers to demonstrate runtime polymorphism.
*/

#include <iostream>
using namespace std;

class Shape
{
	protected:
		string color;
		bool filled;

	public:
		Shape(string shapeColor = "Red", bool shapeFilled = true)
		{
			color = shapeColor;
			filled = shapeFilled;
		}

		virtual void draw()
		{
			cout << "Drawing Shape";
		}

		virtual double getArea()
		{
			return 0;
		}

		virtual double getPerimeter()
		{
			return 0;
		}

		virtual ~Shape()
		{
		}
};

class Circle : public Shape
{
	private:
		double radius;

	public:
		Circle(double r) : Shape("Red", true)
		{
			radius = r;
		}

		void draw() override
		{
			cout << "Circle is being drawn.";
		}
};

class Rectangle : public Shape
{
	private:
		double length;
		double width;

	public:
		Rectangle(double l, double w) : Shape("Blue", true)
		{
			length = l;
			width = w;
		}

		double getArea() override
		{
			return length * width;
		}
};

class Triangle : public Shape
{
	private:
		double side1;
		double side2;
		double side3;

	public:
		Triangle(double a, double b, double c) : Shape("Green", true)
		{
			side1 = a;
			side2 = b;
			side3 = c;
		}

		double getPerimeter() override
		{
			return side1 + side2 + side3;
		}
};

int main()
{
	Shape *shape1;
	Shape *shape2;
	Shape *shape3;

	shape1 = new Circle(5);
	shape2 = new Rectangle(10, 5);
	shape3 = new Triangle(3, 4, 5);

	cout << "Circle:\n";
	shape1->draw();

	cout << "\n\nRectangle:";
	cout << "\nArea: " << shape2->getArea();

	cout << "\n\nTriangle:";
	cout << "\nPerimeter: " << shape3->getPerimeter();

	delete shape1;
	delete shape2;
	delete shape3;

	return 0;
}