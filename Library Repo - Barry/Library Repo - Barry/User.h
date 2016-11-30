#ifndef User_H
#define User_H

#include<string>
#include<iostream>
#include<vector>
using namespace std;
class User
{
private:
	string name;
	string password;
	User* next;
	User* prev;
	bool isAdmin;
public:
	User(string NameParam,string PasswordParam);
	void setNext(User* nextParam);
	User* getNext() const;
	void setPrev(User* prevParam);
	User* getPrev() const;
	string getName() const;
	string getPassword() const;
	void setName(string nameParam);
	void setPassword(string passwordParam);
	bool getIsAdmin();
	void setIsAdmin(bool adminParam);
	void printUser();

};
#endif