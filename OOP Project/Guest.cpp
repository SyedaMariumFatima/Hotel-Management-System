#include "Guest.h"

Guest::Guest() : isVip(false), bookingCount(0), address(""), nationality("") {}

Guest::Guest(string n, string no, string e, int ID, string pass, string add, string nation) 
	: Person(n, no, e, ID, pass), isVip(false), bookingCount(0), address(add), nationality(nation) {}

string Guest::getRole() const
{
	return "Guest";
}

bool Guest::login(string Email, string pass) const
{
	return (email == Email && password == pass);
}

bool Guest::logOut()
{
	cout << "Logged out" << endl;
	return true;
}

void Guest::displayDetails() const
{
	Person::displayDetails();
	cout << "Address: " << address << endl;
	cout << "Total number of bookings: " << bookingCount << endl;
	cout << "Nationality: " << nationality << endl;
	if (isVip)
	{
		cout << "Guest is listed as a VIP" << endl;
	}
	else
	{
		cout << "Guest is not listed as a VIP" << endl;
	}
}

void Guest::addBooking()
{
	bookingCount++;
}

bool Guest::getVIPStatus()
{
	if (bookingCount > 5)
	{
		cout << "Discount applicable" << endl;
		return true;
	}
	else
	{
		return false;
	}
}

void Guest::cancelBooking()
{
	if (bookingCount > 0)
	{
		bookingCount--;
	}
	else
	{
		cout << "You have no prior bookings to cancel" << endl;
	}
}

int Guest::getBookingCount()
{
	return bookingCount;
}
