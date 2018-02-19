#pragma once
#include "point.h"

class QuickHull{
public:
	QuickHull();
	QuickHull(int, Point*);
	void print();
	~QuickHull();
private:
	Point* hull;
	int size = 0;
};

