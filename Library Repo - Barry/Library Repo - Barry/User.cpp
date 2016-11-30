#include "User.h"
#include "Book.h"
User::User(string nameParam,string passwordParam)
	:name(nameParam),password(passwordParam),next(NULL),prev(NULL),isAdmin(false)
{
}
string User::getName() const
{
	return name;
}

void User::setName(string nameParam) 
{
	name = nameParam;
}

string User::getPassword() const
{
	return password;
}

void User::setPassword(string passwordParam) 
{
	password = passwordParam;
}

void User::setNext(User* nextParam)
{
	next = nextParam;
}
User* User::getNext() const
{
	return next;
}
void User::setPrev(User* prevParam)
{
	prev = prevParam;
}
User* User::getPrev() const
{
	return prev;
}
void User::printUser() 
{
	cout<<"\n------------------------\nName: "+name+"\nPassword: "+ password+"\n------------------------\n";
}

bool User::getIsAdmin()
{
	return isAdmin;
}

void User::setIsAdmin(bool adminParam)
{
	isAdmin=adminParam;
}


