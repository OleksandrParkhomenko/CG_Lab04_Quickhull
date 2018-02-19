#include "quick_hull.h"
#include <iostream>

QuickHull::QuickHull() {}

QuickHull::QuickHull(std::vector<Point> p) {
	int n = p.size();
	if (n < 1) return;
	Point left = p[0];
	Point right = p[0];
	for (int i = 1; i < n; i++) {
		if (left.x > p[i].x) {
			left = p[i];
		}
		if (right.x < p[i].x) {
			right = p[i];
		}
	}
	hull.push_back(left);
	hull.push_back(right);
	std::vector<Point> up;
	std::vector<Point> down;
	for (int i = 0; i < n; i++) {
		if (p[i].clockwise(left, right)) {
			down.push_back(p[i]);
		}
		else if (p[i] != left && p[i] != right){
			up.push_back(p[i]);
		}
	}
	build(left, right, up, false);
	build(left, right, down, true);
}

void QuickHull::build(Point left, Point right, std::vector<Point> p, bool check_up) {
	if (p.size() == 0) {
		return;
	}
	if (p.size() == 1) {
		hull.push_back(p[0]);
		return;
	}
	
	Point max = p[0];
	for (int i = 1; i < p.size(); i++) {
		if (max.distanceToLine(left, right) < p[i].distanceToLine(left, right)) {
			max = p[i];
		}
		if (max.distanceToLine(left, right) == p[i].distanceToLine(left, right)) {
			if (max.angle(left, right) > p[i].angle(left, right)) {
				max = p[i];
			}
		}
	}
	hull.push_back(max);
	std::vector<Point> up_left;
	std::vector<Point> up_right;
	for (int i = 0; i < p.size(); i++) {
		if (p[i].clockwise(left, max) == check_up && max != p[i]) {
			up_left.push_back(p[i]);
		}
		if (p[i].clockwise(max, right) == check_up && max != p[i]) {
			up_right.push_back(p[i]);
		}
	}
	build(left, max, up_left, check_up);
	build(max, right, up_right, check_up);
}

void QuickHull::print() {
	std::cout << "The hull contains " << hull.size() << " points:\n";
	for (int i = 0; i < hull.size(); i++) {
		std::cout << hull[i].x << " " << hull[i].y << "\n";
	}
}

QuickHull::~QuickHull(){}