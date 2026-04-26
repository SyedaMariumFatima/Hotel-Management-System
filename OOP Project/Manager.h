#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"

class Manager : public Employee
{
private:
	int accessLevel;

public:
	Manager();
	Manager(string n, string no, string e, int ID, string p, string d, double s, string sh, int al);

	string getRole() const override;

	void displayDetails() const;

	void setAccessLevel(int acc);
};

#endif
