/*
    5. Create a class Person with data members as name, age, city. Write getters and setters
    for all the data members. Also add the display function. Create Default and Parameterized
    constructors. Create the object of this class in main method and invoke all the methods
    in that class.
*/

#include <iostream>
using namespace std;

class Person
{
	private:
		string name;
		int age;
		string city;

	public:
		// Default constructor
		Person()
		{
			name = "Unknown";
			age = 0;
			city = "Unknown";
		}

		// Parameterized constructor
		Person(string personName, int personAge, string personCity)
		{
			name = personName;
			age = personAge;
			city = personCity;
		}

		// Setter for name
		void setName(string personName)
		{
			name = personName;
		}

		// Setter for age
		void setAge(int personAge)
		{
			age = personAge;
		}

		// Setter for city
		void setCity(string personCity)
		{
			city = personCity;
		}

		// Getter for name
		string getName()
		{
			return name;
		}

		// Getter for age
		int getAge()
		{
			return age;
		}

		// Getter for city
		string getCity()
		{
			return city;
		}

		// Display person details
		void display()
		{
			cout << "\nName: " << name;
			cout << "\nAge: " << age;
			cout << "\nCity: " << city << endl;
		}
};

int main()
{
	Person person1;

	cout << "Default Constructor:";
	person1.display();

	person1.setName("Anurag");
	person1.setAge(22);
	person1.setCity("Pune");

	cout << "\nAfter using Setters:";
	person1.display();

	cout << "\nName: " << person1.getName();
	cout << "\nAge: " << person1.getAge();
	cout << "\nCity: " << person1.getCity();

	Person person2("Rahul", 23, "Mumbai");

	cout << "\n\nParameterized Constructor:";
	person2.display();

	return 0;
}