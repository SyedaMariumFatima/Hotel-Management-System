#ifndef SERVICEBILL_H
#define SERVICEBILL_H

#include "Bill.h"

class ServiceBill : public Bill
{
private:
	double serviceCost;

public:
	ServiceBill(double cost);

	double calculateTotal() const override;

	void displayBill() const override;
};

#endif
