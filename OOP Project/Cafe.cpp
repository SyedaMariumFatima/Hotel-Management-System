#include "Cafe.h"

Cafe::Cafe(string item, double p) : itemName(item), price(p) {}

void Cafe::displayItem() const
{
	cout << "Item: " << itemName << " | Price: " << price << endl;
}

double Cafe::getPrice() const 
{ 
	return price; 
}
