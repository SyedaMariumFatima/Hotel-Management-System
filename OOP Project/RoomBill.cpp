#include "RoomBill.h"

RoomBill::RoomBill(int d, double price) : Bill(0), days(d), costPerNight(price) {}

double RoomBill::calculateTotal() const
{
	double total = days * costPerNight;
	total += total * taxRate;
	total -= discount;
	return total;
}

void RoomBill::displayBill() const
{
	cout << "Room charges: " << days * costPerNight << endl;
	cout << "Total(inclusive of tax/discounts): " << calculateTotal() << endl;
}
