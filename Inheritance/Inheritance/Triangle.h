#pragma once

#include "Polygon.h"

class Triangle : public Polygon {
public:
	Triangle() : Polygon(3) {
		// empty
	}

	double getArea() {
		// https://www.mathsisfun.com/geometry/herons-formula.html
		double semiPerimeter = getPerimeter() / 2;
		return sqrt(semiPerimeter *
			(semiPerimeter - getSideLength(0)) *
			(semiPerimeter - getSideLength(1)) *
			(semiPerimeter - getSideLength(2)));
		
	}

};