#include "Payment.h"

Payment::Payment(int id, double amt) : paymentID(id), amount(amt), status("Pending") {}

bool Payment::operator>(const Payment &other) const
{
	return amount > other.amount;
}

bool Payment::operator==(const Payment &other) const
{
	return paymentID == other.paymentID;
}
