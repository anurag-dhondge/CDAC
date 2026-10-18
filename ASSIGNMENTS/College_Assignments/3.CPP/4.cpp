/*  4.  Library Fine Calculator
        Create a LibraryMember class with member ID, name, and number of overdue days. Use a
        constructor to initialize the data. Write a member function to calculate the fine. Use a static
        data member to store the fine rate per day and a static member function to modify or
        display the fine rate.
*/

#include"4.Lib_Fine.h"

int main()
{
	int nom;

	cout<<"\n Enter number of library members: ";
	cin>>nom;

	LibraryMember* marr = new LibraryMember[nom];

	LibraryMember::setFineRate();

	for(int i=0; i<nom; i++)
	{
		cout<<"\n Enter details of member "<<i+1;
		marr[i].accept();
	}

	cout<<"\n\n Fine Rate------------";
	LibraryMember::displayFineRate();

	cout<<"\n\n Member Details------------";

	for(int i=0; i<nom; i++)
	{
		marr[i].display();
		cout<<endl;
	}

	delete[] marr;
}