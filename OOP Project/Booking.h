#ifndef BOOKING_H
#define BOOKING_H

#include "Guest.h"
#include "Room.h"
#include "RoomBill.h"
#include "ServiceBill.h"
#include "Payment.h"

class Booking
{
private:
	int bookingID;
	Guest *guest;
	Room room;
	int days;
	RoomBill *bill;
	ServiceBill *serviceBills[10];
	int serviceCount;
	Payment *payment;

public:
	Booking();

	Booking(int id, Guest *g, Room r, int d);

	void orderFood(double price);
	
	friend void linkPayment(Booking &b, Payment &p);
	void addService(double serviceCost);

	double calculateTotal() const;

	void displayBooking() const;
	
	bool operator>(const Booking &other) const;
	bool operator==(const Booking &other) const;

	Guest *getGuest();
	Room getRoom() const;

	~Booking();
};

void linkPayment(Booking &b, Payment &p);

#endif
