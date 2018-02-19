#pragma once
#include "point.h"
#include <vector>

class QuickHull{
public:
	QuickHull();
	QuickHull(std::vector<Point>);
	void print();
	~QuickHull();
private:
	void build(Point,Point,std::vector<Point>, bool);
	std::vector<Point> hull;
	int size = 0;
};

