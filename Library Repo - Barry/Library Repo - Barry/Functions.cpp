#include "Functions.h"
Book* searchBooks(Book* Bookptr)//Takes in firstBook in List as a parameter and returns the Book Selected
{
	unsigned int TypeChoice = 0;
	bool isAvailable = false;
	bool isfound = false;
	string search;
	unsigned int numsearch;
	while(TypeChoice != 9)
	{
		cout<<"To search for Books by Title, Enter 1\n";
		cout<<"To search for Books by Author, Enter 2\n";
		cout<<"To search for Books by ISBN, Enter 3\n";
		cout<<"To exit, Enter 9\n";
		cin>>TypeChoice;
		cout<<"-------------------------------------------------------------------\n";
		if (TypeChoice == 1)
		{
			cout << "Enter Title you want to search\n";
			cin.clear();
			cin.sync();
			getline(std::cin, search); //Allows to take in string WITH spaces
			Book* found = searchByName(search,Bookptr); //Calls fucntion to search by title and returns
			if(found != NULL) // If title found, prints out details
			{
				cout<<"Found title: "<< endl<<found->getTitle()<<endl << found->getAuthor() << endl << found->getISBN() << endl;
				cout<<"-------------------------------------------------------------------\n";
				if(found->getAv() == true)
				{
					cout << "That book is available\n";
					cout<<"-------------------------------------------------------------------\n";
				}
				else if(found->getAv() == false)
				{
					cout << "That book is un-available\n";
					cout<<"-------------------------------------------------------------------\n";
				}
				break;
			}	
			else
			{
				cout<<"Title not found"<<endl; // if title is not found
			}
			break;
		}
		if(TypeChoice == 2)
			{
				cout << "Enter Author you want to search\n";
				cin.clear();
				cin.sync();
				getline(std::cin, search);//Allows to take in string WITH spaces

				Book* found = searchByAuthor(search,Bookptr);//Calls fucntion to search by author and returns
				if(found != NULL)// If author found, prints out details
				{
					cout<<"Found Author: "<< endl <<found->getTitle()<<endl << found->getAuthor() << endl << found->getISBN()<< endl;
					cout<<"-------------------------------------------------------------------\n";	
					if(found->getAv() == true)
						{
							cout << "That book is available\n";
							cout<<"-------------------------------------------------------------------\n";
						}
						else if(found->getAv() == false)
						{
							cout << "That book is un-available\n";
							cout<<"-------------------------------------------------------------------\n";
						}
						break;
					}
					else
					{
						cout<<"Author not found"<<endl;
					}
					break;
				}
		
		if(TypeChoice == 3)
				{
				cout << "Enter ISBN you want to search\n";
				cin >> numsearch; // takes in isbn to search
				Book* found = searchByISBN(numsearch,Bookptr); //Calls search by isbn fucntion
				if(found != NULL)// If isbn found, prints out details
				{
					cout<<"Found ISBN: "<< endl <<found->getTitle()<<endl << found->getAuthor() << endl << found->getISBN()<< endl;
					cout<<"-------------------------------------------------------------------\n";
					if(found->getAv() == true)
					{
						cout << "That book is available\n";
						cout<<"-------------------------------------------------------------------\n";
					}
					else if(found->getAv() == false)
					{
						cout << "That book is un-available\n";
						cout<<"-------------------------------------------------------------------\n";
					}
						break;
					}
					else
					{
						cout<<"ISBN not found"<<endl;

					}
					break;

				}


	}

if (Bookptr == nullptr)
		{
			cout<<"No Book Found\n";
			cout<<"-------------------------------------------------------------------\n";
			return Bookptr;
		}

}
Book* getfirstBook(Book* Bookptr)//Returns Firstbook in List
{
	while(Bookptr !=nullptr)
	{
		if(Bookptr->getPrev() == nullptr)
		{
			return Bookptr;
		}
		Bookptr = Bookptr->getPrev();
	}
}


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
Book* searchByName(string name, Book* first)//Gets called in search method, takes in title to search and first book
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
Book* searchByAuthor(string name, Book* first)//Gets called in search method, takes in author to search and first book
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
Book* searchByISBN(long long int search, Book* first)//Gets called in search method, takes in number to search and first book
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
User* login(User* RegUserptr)//Takes in firstUser in list as a parameter and returns a pointer to the Current User that has been logged on
{
	User* Beginningptr = RegUserptr;
	bool isfound = false;
	string userNameParam;
	string passwordParam;
	while(isfound == false)
	{
		cout<<"Please enter your UserName: ";
		cin>>userNameParam;
		while (RegUserptr != nullptr)
		{
			if(RegUserptr->getName() == userNameParam)
			{
				cout<<"User Found!\nPlease enter your password: ";
				cin>>passwordParam;
				if (RegUserptr->getPassword() == passwordParam)
				{
					cout<<"Password Correct!\n";
					cout<<"-------------------------------------------------------------------\n";
					return RegUserptr;
				}
			}
			RegUserptr = RegUserptr->getNext();
		}
		cout<<"Error UserName not found\n";
		RegUserptr = Beginningptr;
	}
}
void checkOutBook(Book* BookPtr,User* RegUserPtr)
	//Takes in CurrentBook as a Pointer and Current User as a Pointer and prompts user to choose to check out book
	//Book isavailable is changed
{
	if(BookPtr->getAv() == true)
	{
		unsigned int checkOutChoice;
		cout<<"To check out this book, Enter 1: ";
		cin>>checkOutChoice;
		if(checkOutChoice == 1)
		{
			BookPtr->setCurrentHolder(RegUserPtr);
			BookPtr->setAv(false);
		}
		else
		{
			cout<<"You chose not to check out this book.\n";
		}
	}
	else if(BookPtr->getAv() == false)
	{
		cout << "Sorry that book is un-available\n";
	}
}
	

void checkInBook(Book* BookPtr)//Takes in CurrentBook and setsCurrent Holder to null to check back in book
{
	BookPtr->setCurrentHolder(NULL);
	BookPtr->setAv(true);
	cout<<"Thank you for checking back in this book\n";
}

void searchCheckoutBooks(Book* BookPtr,User* RegUserPtr)//Takes in FirstBook as a pointer and Current RegUser as a pointer and prints out all books User has checked out
{
	while (BookPtr != nullptr)
	{
		if(BookPtr->getCurrentHolder() == RegUserPtr)
		{
			unsigned int checkChoice;
			BookPtr->printBook();
			cout<<"Press 1 to return this book:\n";
			cout<<"Press 2 to continue searching:\nYour choice: ";
			cin>>checkChoice;
			if (checkChoice == 1)
			{
				checkInBook(BookPtr);
			}
		}
		BookPtr = BookPtr->getNext();
	}
	if (BookPtr==nullptr)
	{
		cout<<"There are no books to return\n";
		cout<<"-------------------------------------------------------------------\n";

	}
}
void addBook(Book* Bookptr)//Takes in firstBook as a pointer and Prompts user to create a new book
{
	string nameParam;
	string authorParam;
	unsigned int ISBNParam;
	unsigned int availableParam;
	bool isAvailableParam;
	cout<<"Please enter the name of the book: ";
	cout << "Enter Title you want to search\n";
	cin.clear();
	cin.sync();
	getline(std::cin, nameParam); //Allows me to take in string WITH SPACES // Takes in Title
	cout<<"\nPlease enter the author of the book: ";
	cin.clear();
	cin.sync();
	getline(std::cin, authorParam); //Allows me to take in string WITH SPACES // Takes in Author
	cout<<"\nPlease enter the ISBN of the book: ";
	cin >> ISBNParam; // Takes in ISBN
	cout<<"\nPlease enter 1 if the book is available.";
	cout<<"\nPlease enter 2 if the book is un-available.";
	cin>>availableParam; //Sets availability of book
	if(availableParam == 1)
		{
			isAvailableParam = true;
		}
	else if (availableParam == 2)
		{
			isAvailableParam = false;
		}
	Book* NewBookptr = new Book(nameParam,authorParam,ISBNParam,availableParam); //Creates new book using info taken in
	while (Bookptr != nullptr)
	{
		if(Bookptr->getNext() == nullptr) //If book pointer is at the end of the list
		{
			Bookptr->setNext(NewBookptr); //Sets a books Next to the new book in custom linked list
			NewBookptr->setPrev(Bookptr); //Sets new books Previous in custom linked list
			break;
		}
		Bookptr = Bookptr->getNext(); // Iterates through books, till reach end
		cout<<"-------------------------------------------------------------------\n";
	}
}
