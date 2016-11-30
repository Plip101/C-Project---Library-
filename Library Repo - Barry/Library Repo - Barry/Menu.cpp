#include "Menu.h"

using namespace std;

int guestPage()//Menu for GuestPage, Returns Choice made to main Function
{
	unsigned int choice;
	std::cout<<"To search for a book enter 1.\n";
	std::cout<<"To exit enter 9.\n";
	std::cout<<"Your choice: ";
	std::cin >> choice;
	std::cout<<"-------------------------------------------------------------------\n";
	return choice;
}
int introPage()//Menu for welcomePage, Returns Choice made to main Function
{
	unsigned int choice;
	cout << "Welcom to the library\n";
	cout<<"To continue as a guest, Enter 1.\n";
	cout<<"To login, Please Enter 2.\n";
	cout<<"To login as an administrator, Enter 3\n";
	cout<<"To exit the program, Enter 9\n";
	cout<<"Your choice: ";
	cin>>choice;
	cout<<"-------------------------------------------------------------------\n";
	return choice;
}
int userPage()//Menu for userPage, Returns Choice made to main Function
{
	unsigned int choice;
	cout<<"To search for a book enter 1.\n";
	cout<<"To check out a book enter 2.\n";
	cout<<"To return a book enter 3.\n";
	cout<<"To exit enter 9.\n";
	cout<<"Your choice: ";
	cin>>choice;
	cout<<"-------------------------------------------------------------------\n";
	return choice;
}
int adminPage()//Menu for adminPage, Returns Choice made to main Function
{
	unsigned int choice;
	cout<<"To add a book enter 1.\n";
	cout<<"To exit enter 9.\n";
	cout<<"Your choice: ";
	cin>>choice;
	cout<<"-------------------------------------------------------------------\n";
	return choice;
}