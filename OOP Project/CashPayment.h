#ifndef CASHPAYMENT_H
#define CASHPAYMENT_H

#include "Payment.h"

class CashPayment : public Payment
{
public:
	CashPayment(int id, double a);

	void processPayment() override;
	void displayPayment() const override;
};

#endif
