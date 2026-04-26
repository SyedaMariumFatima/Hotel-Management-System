#ifndef ONLINEPAYMENT_H
#define ONLINEPAYMENT_H

#include "Payment.h"

class OnlinePayment : public Payment
{
public:
	OnlinePayment(int id, int a);

	void processPayment() override;
	void displayPayment() const override;
};

#endif
