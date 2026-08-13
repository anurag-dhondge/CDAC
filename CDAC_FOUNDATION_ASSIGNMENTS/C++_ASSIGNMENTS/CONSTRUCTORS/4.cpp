/*
    4. Create Date class with members day, month, year. Write no argument and parameterized
    constructor. Create two objects and initialize them using no argument and parameterized
    constructor respectively. Print date using display function.
*/

#include <iostream>
using namespace std;

class Date
{
	private:
		int day;
		int month;
		int year;

	public:
		// No argument constructor
		Date()
		{
			day = 1;
			month = 1;
			year = 2000;
		}

		// Parameterized constructor
		Date(int dateDay, int dateMonth, int dateYear)
		{
			day = dateDay;
			month = dateMonth;
			year = dateYear;
		}

		// Display date
		void display()
		{
			cout << day << "/" << month << "/" << year << endl;
		}
};

int main()
{
	Date date1;

	Date date2(13, 8, 2026);

	cout << "Date using No Argument Constructor: ";
	date1.display();

	cout << "Date using Parameterized Constructor: ";
	date2.display();

	return 0;
}