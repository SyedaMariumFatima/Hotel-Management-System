#ifndef CARDPAYMENT_H
#define CARDPAYMENT_H

#include "Payment.h"

class CardPayment : public Payment
{
public:
	CardPayment(int id, int a);

	void processPayment() override;
	void displayPayment() const override;
};

#endif
