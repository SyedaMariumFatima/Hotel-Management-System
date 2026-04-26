#ifndef PAYMENT_H
#define PAYMENT_H

#include <iostream>
using namespace std;

class Booking;

class Payment
{
protected:
	int paymentID;
	double amount;
	string status;

public:
	Payment(int id, double amt);

	friend void linkPayment(Booking &b, Payment &p);

	bool operator>(const Payment &other) const;
	bool operator==(const Payment &other) const;

	virtual void processPayment() = 0;

	virtual void displayPayment() const = 0;

	virtual ~Payment() {}
};

#endif
