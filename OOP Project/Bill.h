#ifndef BILL_H
#define BILL_H

#include <iostream>
using namespace std;

class Bill
{
protected:
	double baseAmount;
	double taxRate;
	double discount;
	string status;

public:
	Bill(double a);

	virtual double calculateTotal() const = 0;
	virtual void displayBill() const = 0;

	void applyDiscount(double d);

	void statusPaid();
	
	double operator+(const Bill &other) const;
	
	virtual ~Bill() {}
};

#endif
