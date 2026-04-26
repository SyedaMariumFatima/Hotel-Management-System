#include "Status.h"

Status::Status(string s) : currentStatus(s) {}

void Status::updateStatus(string s) 
{ 
	currentStatus = s; 
}

string Status::getStatus() const 
{ 
	return currentStatus; 
}

void Status::displayStatus() const 
{ 
	cout << "Status: " << currentStatus << endl; 
}
