#ifndef STATUS_H
#define STATUS_H

#include <iostream>
using namespace std;

class Status
{
private:
	string currentStatus;

public:
	Status(string s = "Pending");
	void updateStatus(string s);
	string getStatus() const;
	void displayStatus() const;
};

#endif
