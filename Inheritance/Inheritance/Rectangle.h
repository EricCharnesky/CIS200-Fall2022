#pragma once

#include "Polygon.h"
#include <stdexcept>

class Rectangle : public Polygon {
public:
	Rectangle() : Polygon(4) {
		// empty
	}

	void setSideLength(int index, double sideLength) {
		if (index > 3) {
			throw logic_error("rectangles don't have that many sides");
		}
		if (index % 2 == 0) {
			Polygon::setSideLength(0, sideLength);
			Polygon::setSideLength(2, sideLength);
		}
		else {
			Polygon::setSideLength(1, sideLength);
			Polygon::setSideLength(3, sideLength);
		}
	}

	double getArea() {
		return getSideLength(0) * getSideLength(1);
	}
};