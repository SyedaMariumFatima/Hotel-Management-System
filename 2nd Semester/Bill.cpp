#include "Bill.h"

Bill::Bill(double a)
{
	baseAmount = a;
	taxRate = 0.1;
	discount = 0;
	status = "unpaid";
}

void Bill::applyDiscount(double d)
{
	discount = d;
}

void Bill::statusPaid()
{
	status = "paid";
}

double Bill::operator+(const Bill &other) const
{
	return calculateTotal() + other.calculateTotal();
}
