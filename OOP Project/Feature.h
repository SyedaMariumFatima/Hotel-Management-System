#ifndef FEATURE_H
#define FEATURE_H

#include <iostream>
using namespace std;

class Feature
{
private:
	string description;
	double cost;

public:
	Feature(string desc = "", double c = 0);
	void displayFeature() const;
	double getCost() const;
};

#endif
