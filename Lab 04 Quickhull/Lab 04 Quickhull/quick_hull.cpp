#include "quick_hull.h"

QuickHull::QuickHull() {}

QuickHull::QuickHull(int n, Point* p) {
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
	
}