/*  3.  Vehicle Registration System
        Create a Vehicle class with registration number, owner name, and vehicle type. Use
        constructors to initialize objects. Maintain a static member to count the total number of
        registered vehicles. Store multiple vehicles in an array of objects and display all records.
*/

#include "3.Vehicle_Reg.h"

int main()
{
	int nov;

	cout<<"\n Enter number of vehicles: ";
	cin>>nov;

	Vehicle* varr = new Vehicle[nov];

	for(int i=0; i<nov; i++)
	{
		cout<<"\n Enter details of vehicle "<<i+1;
		varr[i].accept();
	}

	cout<<"\n\n All vehicles------------";

	for(int i=0; i<nov; i++)
	{
		varr[i].display();
		cout<<endl;
	}

	Vehicle::displayCount();

	delete[] varr;
}