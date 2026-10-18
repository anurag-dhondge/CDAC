#include "2.Book_Management.h"

int main()
{
	int nob;

	cout<<"\n Enter number of books: ";
	cin>>nob;

	Book* barr = new Book[nob];

	for(int i=0; i<nob; i++)
	{
		cout<<"\n Enter details of book "<<i+1;
		barr[i].accept();
	}

	cout<<"\n\n All books------------";

	for(int i=0; i<nob; i++)
	{
		barr[i].display();
		cout<<endl;
	}

	int id;
	cout<<"\n Enter book id to search: ";
	cin>>id;

	for(int i=0; i<nob; i++)
	{
		if(barr[i].search(id))
		{
			cout<<"\n Book found------------";
			barr[i].display();
			break;
		}
	}

	delete[] barr;
}