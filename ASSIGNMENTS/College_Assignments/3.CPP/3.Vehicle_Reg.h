/*
    3.  Vehicle Registration System 
        Create a Vehicle class with registration number, owner name, and vehicle type. Use 
        constructors to initialize objects. Maintain a static member to count the total number of 
        registered vehicles. Store multiple vehicles in an array of objects and display all records.
*/

#pragma once
#include<iostream>
#include<string>
using namespace std;

class Vehicle
{
	private:
		int regno;
		string ownername;
		string vehicletype;

		static int count;

	public:
		Vehicle()
		{
			regno = 0;
			ownername = "";
			vehicletype = "";
			count++;
		}

		Vehicle(int r, string o, string v)
		{
			regno = r;
			ownername = o;
			vehicletype = v;
			count++;
		}

		void accept()
		{
			cout<<"\n Enter registration no: ";
			cin>>regno;

			cout<<" Enter owner name: ";
			cin>>ownername;

			cout<<" Enter vehicle type: ";
			cin>>vehicletype;
		}

		void display()
		{
			cout<<"\n Registration No: "<<regno;
			cout<<"\n Owner Name: "<<ownername;
			cout<<"\n Vehicle Type: "<<vehicletype;
		}

		static void displayCount()
		{
			cout<<"\n Total Registered Vehicles: "<<count;
		}
};

int Vehicle::count = 0;