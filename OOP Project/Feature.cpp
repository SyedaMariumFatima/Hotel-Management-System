#include "Feature.h"

Feature::Feature(string desc, double c) : description(desc), cost(c) {}

void Feature::displayFeature() const
{
	cout << "Feature: " << description << " | Cost: " << cost << endl;
}

double Feature::getCost() const 
{ 
	return cost; 
}
