/*
Question 1: Containment of Objects – Online Shopping Order Management System

Problem Statement:
Develop a C++ program for an Online Shopping Order Management System
to demonstrate containment of objects. Create Customer and Product classes,
and an Order class containing objects of both classes. Initialize the contained
objects through constructors, calculate the total order amount, and display
complete order details.
*/

#include "Order.h"

int main()
{
    Order o1(1, "abc", 9763770278, 213, "Apple", 100000, 2, 101);
    o1.displayOrder();

    Order o2(2, "xyz", 9876543210, 214, "Lenovo", 50000, 3, 102);
    o2.displayOrder();

    Order o3(3, "pqr", 9123456789, 215, "Samsung", 70000, 1, 103);
    o3.displayOrder();

    return 0;
}