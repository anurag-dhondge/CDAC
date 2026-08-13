/*
    1. Create a C++ program that implements a Book class with the following requirements:
    Attributes: title (string), author (string), pages (integer), price (double)
    Add default constructor and Parameterized Constructor write display method to show the book details.
    - Use proper encapsulation and data hiding techniques
    - Use meaningful variable names and comments to explain the code.
*/

#include <iostream>
using namespace std;

class Book
{
	private:
		string title;
		string author;
		int pages;
		double price;

	public:
		// Default constructor
		Book()
		{
			title = "Unknown";
			author = "Unknown";
			pages = 0;
			price = 0.0;
		}

		// Parameterized constructor
		Book(string bookTitle, string bookAuthor, int bookPages, double bookPrice)
		{
			title = bookTitle;
			author = bookAuthor;
			pages = bookPages;
			price = bookPrice;
		}

		// Display book details
		void display()
		{
			cout << "\nTitle: " << title;
			cout << "\nAuthor: " << author;
			cout << "\nPages: " << pages;
			cout << "\nPrice: " << price << endl;
		}
};

int main()
{
	Book book1;

	Book book2("C++ Programming", "Yashwant Kanetkar", 500, 450.50);

	cout << "Book 1 Details:";
	book1.display();

	cout << "\nBook 2 Details:";
	book2.display();

	return 0;
}