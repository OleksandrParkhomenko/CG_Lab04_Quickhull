#include "quick_hull.h"
#include <iostream>

QuickHull::QuickHull() {}

QuickHull::QuickHull(std::vector<Point> p) {
	int n = p.size();
	if (n < 1) return;
	Point left = p[0];
	Point right = p[0];
	for (int i = 1; i < n; i++) {
		if (left.x < p[i].x) {
			left = p[i];
		}
		if (right.x > p[i].x) {
			right = p[i];
		}
	}
	//hull.push_back(left);
	//hull.push_back(right);
	std::vector<Point> up;
	std::vector<Point> down;
	for (int i = 0; i < n; i++) {
		if (p[i].clockwise(left, right)) {
			up.push_back(p[i]);
		}
		else {
			down.push_back(p[i]);
		}
	}
	build(left, right, up, true);
	build(left, right, down, false);
}

void QuickHull::build(Point left, Point right, std::vector<Point> p, bool check_up) {
	if (p.size() == 0) {
		hull.push_back(left);
		hull.push_back(right);
		return;
	}
	if (p.size() == 1) {
		hull.push_back(left);
		hull.push_back(right);
		hull.push_back(p[0]);
		return;
	}
	Point max = p[0];
	for (int i = 1; i < p.size(); i++) {
		if (max.distanceToLine(left, right) < p[i].distanceToLine(left, right)) {
			max = p[i];
		}
	}
	std::vector<Point> up;
	std::vector<Point> down;
	for (int i = 1; i < p.size(); i++) {
		if (p[i].clockwise(left, max) == check_up) {
			up.push_back(p[i]);
		}
		if (p[i].clockwise(max, right) == check_up) {
			down.push_back(p[i]);
		}
	}
	build(left, max, up, check_up);
	build(max, right, down, check_up);
}

void QuickHull::print() {
	for (int i = 0; i < hull.size(); i++) {
		std::cout << hull[i].x << " " << hull[i].y << "\n";
	}
}

QuickHull::~QuickHull(){}