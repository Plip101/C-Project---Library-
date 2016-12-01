#include "Book.h"
#include "Functions.h"
#include "Book.h"
#include "Menu.h"
#include "User.h"
void main()
{
	unsigned int Introchoice = 0;//Choice int for Welcome Screen
	unsigned int GuestChoice = 0;//Choice int for Guest Screen
	unsigned int UserChoice = 0;//Choice int for User Screen
	unsigned int AdminChoice = 0;//Choice int for Admin Screen

	Book *tkamb = new Book("To Kill A Mocking Bird", "Harper Lee",1234567891234,false);
	Book *sl = new Book("Schindlers List", "Thomas Keneally",1234567892345,false);
	Book *it = new Book("IT", "Stephen King",1234567893456,true);
	Book *tgm = new Book("The Mile", "Andrew Christ",1234567894567,false);
	Book *b = new Book("Barry Bio", "Barry O' Brien",1234567895678,true); 
	
	tkamb->setNext(sl);
	sl->setNext(it);
	it->setNext(tgm);
	tgm->setNext(b);

	b->setPrev(tgm);
	tgm->setPrev(it);
	it->setPrev(sl);
	sl->setPrev(tkamb);


	User *Barry = new User("Barry","O'Brien");
	User *Brendan = new User("Bredan","Potts");
	User *John = new User("John","Barret");


	Barry->setNext(Brendan);
	Brendan->setNext(John);
	John->setPrev(Brendan);
	Brendan->setPrev(Barry);

	Barry->setIsAdmin(true);
	User* firstUserPtr = Barry;//Pointer to firstUser in list
	User* CurrentUser = John;//Pointer toCurrent user, Does not matter at beginning of program
	Book* CurrentBookptr = tkamb;
	Book* firstBookptr = tkamb;

	string search;
	long long int numsearch;


	while (Introchoice !=9)//Main While Loop of Program
	{
		Introchoice = introPage();//Calls welcome Page menu
		if (Introchoice == 1)//If Guest Choice
		{
			GuestChoice = guestPage();//Calls Guest Menu
			while (GuestChoice!=9)
			{
				if(GuestChoice == 1)//If Search is chosen
				{
					CurrentBookptr = searchBooks(firstBookptr);//Search Books
					break;
				}
				else//Invalid Choice
				{
					std::cout<<"Error,Choice not valid!\nPlease Enter your choice: ";
					std::cin>>GuestChoice;
				}
			}

		}
		else if(Introchoice == 2)//If logging in as user
		{
			CurrentUser = login(firstUserPtr);//Calls Login in function and sets Current User as the logged in user
			while (UserChoice!=9)//While menu choice is not 9
			{
				UserChoice = userPage();//Calls UserPage Menu
				if(UserChoice == 1)
				{
					CurrentBookptr = searchBooks(firstBookptr);//Searching Books and setting CurrentBookptr to book selected
				}
				else if(UserChoice == 2)
				{
					cout << "Enter Title you want to search\n";
					cin.clear();
					cin.sync();
					getline(std::cin, search);
					CurrentBookptr = searchByName(search,firstBookptr);//Searching Books and setting CurrentBookptr to book selected
					checkOutBook(CurrentBookptr,CurrentUser);//Checking out book function is called 
				}
				else if(UserChoice == 3)
				{
					searchCheckoutBooks(firstBookptr,CurrentUser);//Searches checked out books on CurrentUser

				}
				else if(UserChoice == 9)
				{
				}
				else
				{
					std::cout<<"Error,Choice not valid!\nPlease Enter your choice: ";
					std::cin>>UserChoice;
				}
			}
		}
		else if(Introchoice == 3)//Admin Menu is called
		{
			CurrentUser = login(firstUserPtr);//Sets Current user to Admin Logged in
			if(CurrentUser->getIsAdmin()==true)//Checks if User has Admin Permission
			{
				while (AdminChoice!=9)
				{
					AdminChoice = adminPage();//Prints admin Menu and sets AdminChoice to the choice chosen
					if (AdminChoice == 1)//Adding Book option is selected
					{
						addBook(firstBookptr);//Calls addBookFunction
						printDetialsStart(firstBookptr);//Prints out Books
					}
					
				}
			}
			else//If user does not have admin permission
			{
				std::cout<<"User is not an admin\n";
				std::cout<<"----------------------------------------------------\n\n";
			}
		}
		
		
	 
		
		

	/*if ( selection == 1)
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
	

	*/
	system("pause");
	
}
}