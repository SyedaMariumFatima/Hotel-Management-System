#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Employee : public Person
{
protected:
	string department;
	double salary;
	string shift;
	int hoursWorked;
	double bonus;

public:
	Employee();
	Employee(string n, string no, string e, int ID, string p, string d, double s, string sh);

	string getRole() const override;

	void displayDetails() const;

	double calculatePay();

	void updatesalary(double NewSalary);
};

#endif
