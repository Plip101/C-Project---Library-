#include "Book.h"
#include <ostream>
#include <assert.h>
#include <string>
#include <iostream>
#include <vector>
#include <list>

/*void PrintList(list<Book>& books)
{
	cout << "Book names: " << endl;
	list<Book>::iterator pos;
	for (pos = books.begin(); pos != books.end(); pos++)
	{
		cout << "Name: " << pos->getTitle() << endl;
	}
}*/
/*void searchForBookByISBN(list<Book>& books, long long int search)
{
	list<Book>::iterator pos;
	pos = books.begin();
	for (pos = books.begin(); pos != books.end(); pos++){
		
		if(search == pos->getISBN())
		{
			cout << "This book has that ISBN: "<< pos->getTitle() << endl;
			break;
		}
		else{
			cout << "No book with that ISBN" << endl;
			break;
		}
	}
}*/


void printDetialsStart(Book * first)
{
	cout<< "___________________" <<endl;
	Book* nextBook = first;
	while(nextBook != NULL)
	{
		cout<< "Books Start to End: " << nextBook->getTitle()<<endl;

		nextBook = nextBook->getNext();
	}
	cout<< "___________________" <<endl;

}
Book* searchByName(string name, Book* first)
{
	Book* nextBook = first;
	while(nextBook != NULL)
	{
		if(name == nextBook->getTitle())
		{
			cout << nextBook->getTitle() << endl;
			
			
		}
		else 
		{
			nextBook = nextBook->getNext();		
		}
	}
	return NULL;
	
}


void main()
{
	Book *tkamb = new Book("To Kill A Mocking Bird", "Harper Lee",1234567891234,false);
	Book *sl = new Book("Schindlers List", "Thomas Keneally",1234567892345,false);
	Book *it = new Book("IT", "Stephen King",1234567893456,true);
	Book *tgm = new Book("The Green Mile", "Stephen King",1234567894567,false);
	Book *b = new Book("Barry Bio", "Barry O' Brien",1234567895678,true); 

	tkamb->setNext(sl);
	sl->setNext(it);
	it->setNext(tgm);
	tgm->setNext(b);

	b->setPrev(tgm);
	tgm->setPrev(it);
	it->setPrev(sl);
	sl->setPrev(tkamb);
	
	long long int search;
	string titlesearch;
	
	printDetialsStart(tkamb);
	cout << "Book Name: " << endl;
	cin >> titlesearch;
	searchByName(titlesearch, tkamb);
	system("pause");
}