#ifndef PERSON_H
#define PERSON_H

#include "AUsers.h"

class Person : public AUsers
{
protected:
	string name;
	string number;
	string email;
	int id;
	string password;

public:
	Person();
	Person(string n, string no, string e, int ID, string passKey);

	void displayDetails() const override;
	string getName() const;
	void setContact(string Email, string num);

	virtual string getRole() const = 0;

	bool login(string Email, string pass) const override;
	bool logOut() override;
};

#endif
