#pragma once

using namespace std;

#include <vector>

class Polygon {

private:
	int numberOfSides;
	vector<double> sideLengths;

public:
	Polygon(int numberOfSides) {
		this->numberOfSides = numberOfSides;
		sideLengths = vector<double>(numberOfSides, 0);
	}

	virtual void setSideLength(int index, double length) {
		sideLengths.at(index) = length;
	}

	double getSideLength(int index) {
		return sideLengths.at(index);
	}

	double getPerimeter() {
		double perimeter = 0;
		for (int index = 0; index < sideLengths.size(); index++) {
			perimeter += sideLengths.at(index);
		}
		return perimeter;
	}

	// = 0 means it's pure virtual or 'abstract'
	virtual double getArea() = 0;

};