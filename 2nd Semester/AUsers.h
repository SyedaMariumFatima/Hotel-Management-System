#ifndef AUSERS_H
#define AUSERS_H

#include <iostream>
using namespace std;

class AUsers
{
public:
	virtual void displayDetails() const = 0;
	virtual string getRole() const = 0;
	virtual bool login(string Email, string pass) const = 0;
	virtual bool logOut() = 0;
	virtual ~AUsers() {}
};

#endif
