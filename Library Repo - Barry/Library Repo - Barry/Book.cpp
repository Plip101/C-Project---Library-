#include "Book.h"
#include "User.h"
#include <string>
#include <iostream>
Book::Book(string titleParam, string authorParam, long long int isbnParam, bool avParam)
	:title(titleParam),author(authorParam),isbn(isbnParam),av(avParam),next(NULL),prev(NULL),currentHolder(NULL)
{
	
}

void Book::setTitle(string titleParam)
{
	title = titleParam;
}
void Book::setAuthor(string authorParam)
{
	author = authorParam;
}
void Book::setISBN(long long int isbnParam)
{
	isbn = isbnParam;
}
void Book::setAv(bool avParam)
{
	av = avParam;
}
void Book::setNext(Book* nextParam)
{
	next = nextParam;
}
void Book::setPrev(Book* prevParam)
{
	prev = prevParam;
}

string Book::getTitle()
{
	return title;
}
string Book::getAuthor()
{
	return author;
}
long long int Book::getISBN()
{
	return isbn;
}
bool Book::getAv()
{
	return av;
}
Book* Book:: getNext()
{
	return next;
}
Book* Book::getPrev()
{
	return prev;
}

User* Book::getCurrentHolder()const//gets Current holder of book
{
	return currentHolder;
}

void Book::setCurrentHolder(User* CurrentHolderParam)//sets Current Holder of book
{
	currentHolder = CurrentHolderParam;
}
void Book::printBook()//Prints out book details
{
	cout<<"\n------------------------\nTitle: "<< title << "\nAuthor: "<< author<<"\nISBN no: "<< isbn << "\n------------------------\n";
}