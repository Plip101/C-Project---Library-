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

public:
	Book(string titleParam, string authorParam, long long int isbnParam,bool avParam);

	string getTitle();
	string getAuthor();
	long long int getISBN();
	bool getAv();

	void setTitle(string titleParam);
	void setAuthor(string authorParam);
	void setISBN(long long int isbnParam);
	void setAv(bool av);

};



#endif