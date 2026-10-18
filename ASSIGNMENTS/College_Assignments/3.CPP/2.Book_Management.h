/*  2.  Book Management
        Create a Book class with book ID, title, author, and price. Use a constructor to initialize the
        data members. Store details of multiple books in an array of objects and search for a book
        using its ID.
*/

#pragma once
#include<iostream>
#include<string>
using namespace std;

class Book
{
	private:
		int bookid;
		string title;
		string author;
		float price;

	public:
		Book()
		{
			bookid = 0;
			title = "";
			author = "";
			price = 0;
		}

		Book(int id, string t, string a, float p)
		{
			bookid = id;
			title = t;
			author = a;
			price = p;
		}

		void accept()
		{
			cout<<"\n Enter book id: ";
			cin>>bookid;

			cout<<" Enter title: ";
			cin>>title;

			cout<<" Enter author: ";
			cin>>author;

			cout<<" Enter price: ";
			cin>>price;
		}

		void display()
		{
			cout<<"\n Book ID: "<<bookid;
			cout<<"\n Title: "<<title;
			cout<<"\n Author: "<<author;
			cout<<"\n Price: "<<price;
		}

		bool search(int id)
		{
			if(bookid == id)
				return true;

			return false;
		}
};