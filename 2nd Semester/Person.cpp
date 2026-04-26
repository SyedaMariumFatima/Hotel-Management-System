#include "Person.h"

Person::Person()
{
	name = "";
	number = "";
	email = "@gmail.com";
	id = 0;
	password = "";
}

Person::Person(string n, string no, string e, int ID, string passKey) 
	: name(n), number(no), email(e), id(ID), password(passKey) {}

void Person::displayDetails() const
{
	cout << "Name: " << name << endl;
	cout << "Number: " << number << endl;
	cout << "Email: " << email << endl;
	cout << "ID: " << id << endl;
}

string Person::getName() const {
	return name;
}

void Person::setContact(string Email, string num)
{
	number = num;
	email = Email;
}

bool Person::login(string Email, string pass) const
{
	return (email == Email && pass == password);
}

bool Person::logOut()
{
	cout << "Log out successfull" << endl;
	return true;
}
