#include "Room.h"

Room::Room() {}

Room::Room(int num, string t, double price) 
	: roomNumber(num), type(t), pricePerNight(price), isAvailable(true) {}

int Room::getRoomNumber()
{
	return roomNumber;
}

double Room::getPrice() const
{
	return pricePerNight;
}

bool Room::getAvailability()
{
	return isAvailable;
}

string Room::getType()
{
	return type;
}

bool Room::bookRoom()
{
	if (isAvailable)
	{
		cout << "Room can be booked" << endl;
		isAvailable = false;
	}
	else
	{
		cout << "Room is already booked" << endl;
	}
	return true;
}

void Room::displayroom() const
{
	cout << "---Room Details---" << endl;
	cout << "Room number: " << roomNumber << endl;
	cout << "Type: " << type << endl;
	cout << "Price per night: " << pricePerNight << endl;
	if (isAvailable)
	{
		cout << "The room is available" << endl;
	}
	else
	{
		cout << "Room is already booked" << endl;
	}
}
