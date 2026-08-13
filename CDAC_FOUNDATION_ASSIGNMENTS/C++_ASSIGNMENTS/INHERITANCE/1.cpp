/*
    1. Develop a class hierarchy for vehicles. Start with a base class Vehicle having attributes
    (vehicle_no,owner_name) and create derived classes two-wheeler having members (veh_type as
    Motorcycle, scooter etc.).Define functions accepts() and display().
    Write a main() function to accept and display details of two-wheelers. [Single Inheritance]
*/

#include <iostream>
using namespace std;

class Vehicle
{
	private:
		int vehicleNo;
		string ownerName;

	public:
		void accepts()
		{
			cout << "Enter Vehicle Number: ";
			cin >> vehicleNo;

			cout << "Enter Owner Name: ";
			cin >> ownerName;
		}

		void display()
		{
			cout << "\nVehicle Number: " << vehicleNo;
			cout << "\nOwner Name: " << ownerName;
		}
};

class TwoWheeler : public Vehicle
{
	private:
		string vehicleType;

	public:
		void accepts()
		{
			Vehicle::accepts();

			cout << "Enter Vehicle Type: ";
			cin >> vehicleType;
		}

		void display()
		{
			Vehicle::display();

			cout << "\nVehicle Type: " << vehicleType;
		}
};

int main()
{
	TwoWheeler twoWheeler;

	cout << "Enter Two-Wheeler Details:\n";

	twoWheeler.accepts();

	cout << "\nTwo-Wheeler Details:";
	twoWheeler.display();

	return 0;
}