#include "Review.h"

Review::Review(string name, string c, int r) : reviewerName(name), comments(c), rating(r) {}

void Review::displayReview() const
{
	cout << reviewerName << " rated " << rating << "/5" << endl;
	cout << "Comments: " << comments << endl;
}
