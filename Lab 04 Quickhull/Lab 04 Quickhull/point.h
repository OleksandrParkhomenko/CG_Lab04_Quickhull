#pragma once
class Point {
public:
	int x;
	int y;
	Point();
	Point(int, int);
	double angle(Point, Point);
	double distanceToLine(Point, Point);
	bool clockwise(Point, Point);
	Point& operator=(const Point&);
	~Point();
};
