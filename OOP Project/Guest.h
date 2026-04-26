#ifndef GUEST_H
#define GUEST_H

#include "Person.h"

class Guest : public Person
{
protected:
	bool isVip;
	int bookingCount;
	string address;
	string nationality;

public:
	Guest();
	Guest(string n, string no, string e, int ID, string pass, string add, string nation);

	string getRole() const override;

	bool login(string Email, string pass) const override;
	bool logOut();

	void displayDetails() const;

	void addBooking();

	bool getVIPStatus();

	void cancelBooking();

	int getBookingCount();
};

#endif
