#include "OnlinePayment.h"

OnlinePayment::OnlinePayment(int id, int a) : Payment(id, a) {}

void OnlinePayment::processPayment()
{
	status = "Completed (online).";
	cout << "Processing the online payment of amount: " << amount << endl;
}

void OnlinePayment::displayPayment() const
{
	cout << "Payment id : " << paymentID << endl;
	cout << "Amount : " << amount << endl;
	cout << "Status : " << status << endl;
}
