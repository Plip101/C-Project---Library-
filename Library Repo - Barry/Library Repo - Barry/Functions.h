#ifndef Functions_H
#define Functions_H
#include<string>
#include<iostream>
#include"Book.h"
#include "User.h"
void printDetialsStart(Book* first);
Book* searchBooks(Book* Bookptr);//SearchBooks Function
Book* searchByName(string name, Book* first);
Book* searchByAuthor(string name, Book* first);
Book* searchByISBN(long long int search, Book* first);
Book* getfirstBook(Book* Bookptr);
User* login(User* RegUserptr);
void checkOutBook(Book* BookPtr,User* RegUserPtr);
void checkInBook(Book* BookPtr);
void searchCheckoutBooks(Book* BookPtr,User* RegUserPtr);
void addBook(Book* Bookptr);


#endif