#pragma once
#include<iostream>
#include<string>
using namespace std;

class LibraryMember
{
	private:
		int memberid;
		string name;
		int overdue_days;

		static float fine_rate;

	public:
		LibraryMember()
		{
			memberid = 0;
			name = "";
			overdue_days = 0;
		}

		LibraryMember(int id, string n, int days)
		{
			memberid = id;
			name = n;
			overdue_days = days;
		}

		void accept()
		{
			cout<<"\n Enter member id: ";
			cin>>memberid;

			cout<<" Enter name: ";
			cin>>name;

			cout<<" Enter overdue days: ";
			cin>>overdue_days;
		}

		float calculateFine()
		{
			return overdue_days * fine_rate;
		}

		static void setFineRate()
		{
			cout<<"\n Enter fine rate per day: ";
			cin>>fine_rate;
		}

		static void displayFineRate()
		{
			cout<<"\n Fine rate per day: "<<fine_rate;
		}

		void display()
		{
			cout<<"\n Member ID: "<<memberid;
			cout<<"\n Name: "<<name;
			cout<<"\n Overdue Days: "<<overdue_days;
			cout<<"\n Fine: "<<calculateFine();
		}
};

float LibraryMember::fine_rate = 0;