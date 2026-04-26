#include "Booking.h"

Booking::Booking() : bookingID(0), guest(NULL), days(0), bill(NULL), serviceCount(0), payment(NULL)
{
	for (int i = 0; i < 10; i++)
		serviceBills[i] = NULL;
}

Booking::Booking(int id, Guest *g, Room r, int d) : bookingID(id), guest(g), room(r), days(d), serviceCount(0), payment(NULL)
{
	bill = new RoomBill(d, r.getPrice());

	if (guest->getVIPStatus())
	{
		bill->applyDiscount(d * r.getPrice() * 0.2);
	}
	guest->addBooking();
	for (int i = 0; i < 10; i++)
	{
		serviceBills[i] = NULL;
	}
}

void Booking::orderFood(double price)
{
	if(serviceCount < 10)
	{
		serviceBills[serviceCount] = new ServiceBill(price);
		serviceCount++;
		cout << "Food ordered and added to bill!" << endl;
	}
	else
	{
		cout << "Maximum services reached" << endl;
	}
}

void Booking::addService(double serviceCost)
{
	if (serviceCount < 10)
	{
		serviceBills[serviceCount] = new ServiceBill(serviceCost);
		serviceCount++;
	}
	else
	{
		cout << "Maximum services reached" << endl;
	}
}

double Booking::calculateTotal() const
{
	double total = bill->calculateTotal();
	for (int i = 0; i < serviceCount; i++)
	{
		total += serviceBills[i]->calculateTotal();
	}
	return total;
}

void Booking::displayBooking() const
{
	cout << "Booking ID: " << bookingID << endl;
	cout << "Guest details: " << endl;
	guest->displayDetails();

	cout << "Room Details: " << endl;
	room.displayroom();

	cout << "Room bill" << endl;
	bill->displayBill();

	if (serviceCount > 0)
	{
		cout << "Service bills: " << endl;
		for (int i = 0; i < serviceCount; i++)
		{
			serviceBills[i]->displayBill();
		}
	}
	cout << "Grand total: " << calculateTotal() << endl;
}

bool Booking::operator>(const Booking &other) const
{
	return calculateTotal() > other.calculateTotal();
}

bool Booking::operator==(const Booking &other) const
{
	return bookingID == other.bookingID;
}

Guest *Booking::getGuest()
{
	return guest;
}

Room Booking::getRoom() const
{
	return room;
}

Booking::~Booking()
{
	delete bill;
	for (int i = 0; i < serviceCount; i++)
	{
		delete serviceBills[i];
	}
}

void linkPayment(Booking &b, Payment &p)
{
	b.payment = &p;
	p.status = "linked";
	cout << "Payment is successfully linked to Booking." << b.bookingID << endl;
}
