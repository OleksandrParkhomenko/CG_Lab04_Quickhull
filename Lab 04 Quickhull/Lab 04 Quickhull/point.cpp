#include"point.h"
#include <math.h>
#define PI 3.14159265

Point::Point() {}

Point::Point(int _x, int _y) {
	x = _x;
	y = _y;
}

double Point::angle(Point a, Point b) {
	double alpha = acos(((a.x - x)*(b.x - x) + (a.y - y)*(b.y - y)) /
		sqrt((pow(a.x - x, 2) + pow(a.y - y, 2))*(pow(b.x - x, 2) + pow(b.y - y, 2))));
	return (alpha * 180.0 / PI);
}

double Point::distanceToLine(Point a, Point b) {
	return abs((b.y - a.y)*x - (b.x - a.x)*y + b.x*a.y - b.y*a.x) /
		sqrt(pow(b.y - a.y, 2) + pow(b.x - a.x, 2));
}

bool Point::clockwise(Point a, Point b) {
	return ((a.x - x) * (b.y- y) - (a.y - y) * (b.x - x)) < 0;
}

Point& Point::operator=(const Point& _new) {
	this->x = _new.x;
	this->y = _new.y;
	return *this;
}

const bool Point::operator==(const Point& right) {
	return (this->x == right.x && this->y == right.y);
}

const bool Point::operator!=(const Point& right) {
	return !(*this == right);
}

Point::~Point() {}