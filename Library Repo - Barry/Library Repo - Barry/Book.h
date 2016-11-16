#ifndef Book_H
#define Book_H
#include <iostream>
using namespace std;


class Book
{
private:
	string title;
	string author;
	long long int isbn;
	bool av;
	Book* next;
	Book* prev;
		

public:
	Book(string titleParam, string authorParam, long long int isbnParam,bool avParam);

	string getTitle();
	string getAuthor();
	long long int getISBN();
	bool getAv();
	Book* getNext();
	Book* getPrev();


	void setTitle(string titleParam);
	void setAuthor(string authorParam);
	void setISBN(long long int isbnParam);
	void setAv(bool av);
	void setNext(Book* nextParam);
	void setPrev(Book* prevParam);

	

};



#endif