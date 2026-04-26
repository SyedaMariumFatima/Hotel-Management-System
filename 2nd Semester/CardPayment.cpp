#include "CardPayment.h"

CardPayment::CardPayment(int id, int a) : Payment(id, a) {}

void CardPayment::processPayment()
{
	status = "Completed (card).";
	cout << "Processing the card payment of amount: " << amount << endl;
}

void CardPayment::displayPayment() const
{
	cout << "Payment id : " << paymentID << endl;
	cout << "Amount : " << amount << endl;
	cout << "Status : " << status << endl;
}
