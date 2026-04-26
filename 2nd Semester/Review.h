#ifndef REVIEW_H
#define REVIEW_H

#include <iostream>
using namespace std;

class Review
{
private:
	string reviewerName;
	string comments;
	int rating;

public:
	Review(string name = "", string c = "", int r = 0);
	void displayReview() const;
};

#endif
