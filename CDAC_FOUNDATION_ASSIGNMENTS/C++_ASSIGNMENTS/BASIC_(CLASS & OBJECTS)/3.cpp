//   3. Write a program to create Book class, with data members as follows- 
//   book_no, book_name, author,edition, price, qty, bill, discount, netbill . 
//   Calculate bill and apply discount 5% on them, also calculate netbill. 
//  Initialize these data members by the objects of its class

#include <iostream>
using namespace std;

class Book
{
    int bookNo = 0;
    string bookName = "";
    string author = "";
    int edition = 0;
    float price = 0.0f;
    int qty = 0;
    float bill = 0.0f;
    float discount = 0.0f;
    float netBill = 0.0f;

    public:
        void accept()
        {
            cout << "Enter Book No: ";
            cin >> bookNo;

            cout << "Enter Book Name: ";
            cin >> bookName;

            cout << "Enter Author: ";
            cin >> author;

            cout << "Enter Edition: ";
            cin >> edition;

            cout << "Enter Price: ";
            cin >> price;

            cout << "Enter Quantity: ";
            cin >> qty;

            bill = price * qty;
            discount = bill * 0.05;
            netBill = bill - discount;
        }

        void display()
        {
            cout << "\nBook Details";
            cout << "\nBook No: " << bookNo;
            cout << "\nBook Name: " << bookName;
            cout << "\nAuthor: " << author;
            cout << "\nEdition: " << edition;
            cout << "\nPrice: " << price;
            cout << "\nQuantity: " << qty;
            cout << "\nBill: " << bill;
            cout << "\nDiscount (5%): " << discount;
            cout << "\nNet Bill: " << netBill;
        }
};

int main()
{
    Book b;

    b.accept();
    b.display();

    return 0;
}