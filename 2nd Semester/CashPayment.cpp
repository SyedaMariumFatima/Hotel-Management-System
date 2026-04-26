#include "CashPayment.h"

CashPayment::CashPayment(int id, double a) : Payment(id, a) {}

void CashPayment::processPayment()
{
	status = "Completed (Cash).";
	cout << "Processing the cash payment of amount: " << amount << endl;
}

void CashPayment::displayPayment() const
{
	cout << "Payment id : " << paymentID << endl;
	cout << "Amount : " << amount << endl;
	cout << "Status : " << status << endl;
}
