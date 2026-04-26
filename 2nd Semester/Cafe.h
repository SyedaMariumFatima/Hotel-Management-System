#ifndef CAFE_H
#define CAFE_H

#include <iostream>
using namespace std;

class Cafe
{
private:
	string itemName;
	double price;

public:
	Cafe(string item = "", double p = 0);
	void displayItem() const;
	double getPrice() const;
};

#endif
