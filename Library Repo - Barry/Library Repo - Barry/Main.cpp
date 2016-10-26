#include "Book.h"
#include <ostream>
#include <assert.h>
#include <string>
#include <iostream>
#include <vector>
#include <list>

void PrintList(list<Book>& books)
{
	cout << "Book names: " << endl;
	list<Book>::iterator pos;
	for (pos = books.begin(); pos != books.end(); pos++)
	{
		cout << "Name: " << pos->getTitle() << endl;
	}
}

void main()
{
	Book *tkamb = new Book("To Kill A Mocking Bird", "Harper Lee",1234567891234,false);
	Book *sl = new Book("Schindlers List", "Thomas Keneally",1234567892345,false);
	Book *it = new Book("IT", "Stephen King",1234567893456,true);
	Book *tgm = new Book("The Green Mile", "Stephen King",1234567894567,false);
	Book *b = new Book("Barry Bio", "Barry O' Brien",1234567895678,true); 


	list<Book> books;
	books.push_back(*tkamb);
	books.push_back(*sl);
	books.push_back(*it);
	books.push_back(*tgm);
	books.push_back(*b);

	PrintList(books);
	system("pause");
}