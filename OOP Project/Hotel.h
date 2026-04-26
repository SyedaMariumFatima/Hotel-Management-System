#ifndef HOTEL_H
#define HOTEL_H

#include "Room.h"
#include "Booking.h"
#include "Employee.h"
#include "Manager.h"
#include "Guest.h"
#include "Cafe.h"
#include "Review.h"
#include "Feature.h"
#include "Payment.h"

class Hotel
{
private:
	string hotelName;
	Room rooms[20];
	int roomCount;
	Booking bookings[20];
	int bookingCount;
	Employee employees[20];
	int employeeCount;
	Guest guests[20];
	int guestCount;
	Cafe menu[20];
	int menuCount;
	Review reviews[20];
	int reviewCount;
	Feature features[20];
	int featureCount;
	Payment *payments[20];
	int paymentCount;

public:
	Hotel(string name);

	void addRoom(Room r);
	void addBooking(Booking b);
	void addEmployee(Employee e);
	void addGuest(Guest g);
	void addMenuItem(Cafe c);
	void addReview(Review r);
	void addFeature(Feature f);
	void addPayment(Payment *p);

	int getGuestCount() const;
	Guest &getGuestAt(int index);

	int getEmployeeCount() const;
	Employee &getEmployeeAt(int index);

	int getRoomCount() const;
	Room &getRoomAt(int index);

	int getBookingCount() const;
	Booking &getBookingAt(int index);

	int getMenuCount() const;
	Cafe &getMenuAt(int index);

	int getReviewCount() const;
	Review &getReviewAt(int index);

	int getFeatureCount() const;
	Feature &getFeatureAt(int index);

	void displayHotelDetails() const;
};

#endif
