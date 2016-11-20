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
		cout<< "Books: " << nextBook->getTitle()<<endl;

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
			return nextBook;
		}
		else 
		{
			nextBook = nextBook->getNext();
		}
	}
	return NULL;
	
}
Book* searchByAuthor(string name, Book* first)
{
	Book* nextBook = first;
	while(nextBook != NULL)
	{
		if(name == nextBook->getAuthor())
		{
			return nextBook;
		}
		else 
		{
			nextBook = nextBook->getNext();		
		}
	}
	return NULL;
	
}
Book* searchByISBN(long long int search, Book* first)
{
	Book* nextBook = first;
	while(nextBook != NULL)
	{
		if(search == nextBook->getISBN())
		{
			return nextBook;
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
	
	long long int numsearch;
	int selection;
	int choice;
	string search;

	cout << "_________________" << endl << "Welcome to the Library" << endl << "Select an option" << endl;
	cout << "1: Print Book List" << endl << "2: Search" << endl << "_________________" << endl << "Enter Choice" << endl;
	cin >> selection;
	/*
	switch(selection)
	{
	case 1:
		printDetialsStart(tkamb);
	case 2:
		searchByName(titlesearch, tkamb);
	case 3:
		cout << "Not a valid Option" << endl;
	}*/

	if ( selection == 1)
	{
		printDetialsStart(tkamb);
	}
	else if (selection == 2)
	{
		cout << "Would you like to search by: " << endl;
		cout << "1: Title" << endl << "2: Author" << endl << "3: ISBN" <<endl;
		cin >> choice;
		if (choice == 1)
		{
			cout << "Enter the title you want to search: " << endl;
			cin.clear();
			cin.sync();
			getline(std::cin, search);

			
			Book* found = searchByName(search, tkamb);
			if(found != NULL)
			{
				cout<<"Found title: "<< endl<<found->getTitle()<<endl << found->getAuthor() << endl << found->getISBN() << endl;
			}
			else
			{
				cout<<"Title not found"<<endl;
			}
			
		}
		else if (choice == 2)
		{
			cout << "Enter the author you want to search: " << endl;
			cin.clear();
			cin.sync();
			getline(std::cin, search);

			Book* found = searchByAuthor(search,tkamb);
			if(found != NULL)
			{
				cout<<"Found Author: "<< endl <<found->getTitle()<<endl << found->getAuthor() << endl << found->getISBN()<< endl;
			}
			else
			{
				cout<<"Author not found"<<endl;
			}
		}
		else if (choice == 3)
		{
			cout << "Enter the ISBN you want to search: " << endl;
			cin >> numsearch;

			Book* found = searchByISBN(numsearch,tkamb);
			if(found != NULL)
			{
				cout<<"Found ISBN: "<< endl <<found->getTitle()<<endl << found->getAuthor() << endl << found->getISBN()<< endl;
			}
			else
			{
				cout<<"ISBN not found"<<endl;
			}
		}
		else{cout << "Not a valid option";}
		
	}
	else{cout<<"Not a valid option";}
	

	
	system("pause");
}