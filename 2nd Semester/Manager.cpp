#include "Manager.h"

Manager::Manager() : Employee(), accessLevel(0) {}

Manager::Manager(string n, string no, string e, int ID, string p, string d, double s, string sh, int al) 
	: Employee(n, no, e, ID, p, d, s, sh), accessLevel(al) {}

string Manager::getRole() const
{
	return "Manager";
}

void Manager::displayDetails() const
{
	Employee::displayDetails();
	cout << "Access level: " << accessLevel << endl;
}

void Manager::setAccessLevel(int acc)
{
	accessLevel = acc;
}
