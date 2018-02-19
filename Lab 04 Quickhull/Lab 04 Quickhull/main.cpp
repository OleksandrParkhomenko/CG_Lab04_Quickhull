#include "quick_hull.h"
#include <iostream>

int main() {
	int n;
	std::vector<Point> points;
	std::cout << "Enter the number of points: ";
	std::cin >> n;
	std::cout << "Enter coordinates of points (x,y):\n";
	for (int i = 0; i < n; i++) {
		Point tmp;
		std::cin >> tmp.x >> tmp.y;
		points.push_back(tmp);
	}
	QuickHull hull(points);
	hull.print();

	system("pause");
	return 0;
}