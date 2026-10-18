/*
    1. Create a C++ program that implements a University class with the following requirements:
    Attributes: name (string), location (string)

    Static Members:
    - totalStudents (integer): The total number of students enrolled in all universities
      (static variable)
    - getTotalStudents() (static function): Returns the total number of students enrolled
      in all Universities.

    Member Functions:
    1. enrollStudent(): Increments the totalStudents static variable by 1.
    2. displayInfo(): Displays the university's name and location.
*/

#include <iostream>
using namespace std;

class University
{
	private:
		string name;
		string location;
		static int totalStudents;

	public:
		// Constructor
		University(string universityName, string universityLocation)
		{
			name = universityName;
			location = universityLocation;
		}

		// Enroll student
		void enrollStudent()
		{
			totalStudents++;
		}

		// Display university information
		void displayInfo()
		{
			cout << "\nUniversity Name: " << name;
			cout << "\nLocation: " << location << endl;
		}

		// Static function
		static int getTotalStudents()
		{
			return totalStudents;
		}
};

// Definition of static variable
int University::totalStudents = 0;

int main()
{
	University u1("SPPU", "Pune");
	University u2("Mumbai University", "Mumbai");

	cout << "University 1:";
	u1.displayInfo();

	cout << "\nUniversity 2:";
	u2.displayInfo();

	u1.enrollStudent();
	u1.enrollStudent();
	u1.enrollStudent();

	u2.enrollStudent();
	u2.enrollStudent();

	cout << "\nTotal Students in All Universities: "
		 << University::getTotalStudents();

	return 0;
}