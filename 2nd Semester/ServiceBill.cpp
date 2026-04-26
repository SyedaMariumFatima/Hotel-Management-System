#include "ServiceBill.h"

ServiceBill::ServiceBill(double cost) : Bill(cost), serviceCost(cost) {}

double ServiceBill::calculateTotal() const
{
	double total = serviceCost;
	total += total * taxRate;
	total -= discount;
	return total;
}

void ServiceBill::displayBill() const
{
	cout << "Service Charges: " << serviceCost << endl;
	cout << "Total (with tax/discount): " << calculateTotal() << endl;
}
