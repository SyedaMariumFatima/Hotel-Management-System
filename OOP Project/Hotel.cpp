#include "Hotel.h"

Hotel::Hotel(string name) : hotelName(name), roomCount(0), bookingCount(0), employeeCount(0), guestCount(0), menuCount(0), reviewCount(0), featureCount(0), paymentCount(0) {}

void Hotel::addRoom(Room r)
{
	if (roomCount < 20)
		rooms[roomCount++] = r;
}

void Hotel::addBooking(Booking b)
{
	if (bookingCount < 20)
		bookings[bookingCount++] = b;
}

void Hotel::addEmployee(Employee e)
{
	if (employeeCount < 20)
		employees[employeeCount++] = e;
}

void Hotel::addGuest(Guest g)
{
	if (guestCount < 20)
		guests[guestCount++] = g;
}

void Hotel::addMenuItem(Cafe c)
{
	if (menuCount < 20)
		menu[menuCount++] = c;
}

void Hotel::addReview(Review r)
{
	if (reviewCount < 20)
		reviews[reviewCount++] = r;
}

void Hotel::addFeature(Feature f)
{
	if (featureCount < 20)
		features[featureCount++] = f;
}

int Hotel::getGuestCount() const
{
	return guestCount;
}

Guest &Hotel::getGuestAt(int index)
{
	return guests[index];
}

int Hotel::getEmployeeCount() const
{
	return employeeCount;
}

Employee &Hotel::getEmployeeAt(int index)
{
	return employees[index];
}

int Hotel::getRoomCount() const
{
	return roomCount;
}

Room &Hotel::getRoomAt(int index)
{
	return rooms[index];
}

int Hotel::getBookingCount() const
{
	return bookingCount;
}

Booking &Hotel::getBookingAt(int index)
{
	return bookings[index];
}

int Hotel::getMenuCount() const
{
	return menuCount;
}

Cafe &Hotel::getMenuAt(int index)
{
	return menu[index];
}

int Hotel::getReviewCount() const
{
	return reviewCount;
}

Review &Hotel::getReviewAt(int index)
{
	return reviews[index];
}

int Hotel::getFeatureCount() const
{
	return featureCount;
}

Feature &Hotel::getFeatureAt(int index)
{
	return features[index];
}

void Hotel::displayHotelDetails() const
{
	cout << "Hotel: " << hotelName << endl;
	cout << "---Rooms---" << endl;
	for (int i = 0; i < roomCount; i++)
		rooms[i].displayroom();
	cout << "---Menu---" << endl;
	for (int i = 0; i < menuCount; i++)
		menu[i].displayItem();
	cout << "---Features---" << endl;
	for (int i = 0; i < featureCount; i++)
		features[i].displayFeature();
	cout << "---Reviews---" << endl;
	for (int i = 0; i < reviewCount; i++)
		reviews[i].displayReview();
}

void Hotel::addPayment(Payment *p)
{
	if (paymentCount < 20)
		payments[paymentCount++] = p;
}
