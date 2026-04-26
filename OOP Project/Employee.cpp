#include "Employee.h"

Employee::Employee() : department(""), salary(0), shift(""), hoursWorked(0), bonus(0) {}

Employee::Employee(string n, string no, string e, int ID, string p, string d, double s, string sh) 
	: Person(n, no, e, ID, p), department(d), salary(s), shift(sh), hoursWorked(0), bonus(2) {}

string Employee::getRole() const
{
	return "Employee";
}

void Employee::displayDetails() const
{
	Person::displayDetails();
	cout << "Department: " << department << endl;
	cout << "Salary: " << salary << endl;
	cout << "Shift: " << shift << endl;
	cout << "Hours worked: " << hoursWorked << endl;
	cout << "Bonus: " << bonus << endl;
}

double Employee::calculatePay()
{
	return (bonus * hoursWorked) + salary;
}

void Employee::updatesalary(double NewSalary)
{
	salary = NewSalary;
}
