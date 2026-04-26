#ifndef ROOM_H
#define ROOM_H

#include <iostream>
using namespace std;

class Room
{
private:
	int roomNumber;
	string type;
	double pricePerNight;
	bool isAvailable;

public:
	Room();
	Room(int num, string t, double price);

	int getRoomNumber();
	double getPrice() const;
	bool getAvailability();
	string getType();

	bool bookRoom();

	void displayroom() const;
};

#endif
