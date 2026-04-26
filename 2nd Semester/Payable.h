#ifndef PAYABLE_H
#define PAYABLE_H

#include <iostream>
using namespace std;

class Payable
{
public:
	virtual double calculateTotal() const = 0;
	virtual void displayPaymentDetails() const = 0;
	virtual ~Payable() {}
};

#endif
