#ifndef ROOMBILL_H
#define ROOMBILL_H

#include "Bill.h"

class RoomBill : public Bill
{
private:
	int days;
	double costPerNight;

public:
	RoomBill(int d, double price);

	double calculateTotal() const override;

	void displayBill() const override;
};

#endif
