using namespace std;

#include <iostream>
#include "Item.h"
#include "TaxableItem.h"
#include "PerishableItem.h"
#include "Polygon.h"
#include "Triangle.h"
#include "Rectangle.h"

void printItemCost(Item* item) {
	cout << "Your total cost for " << item->getName() << " is: "
		<< item->getTotalPrice() << endl;
}

Polygon* determineLargerPolygonByArea(Polygon* first, Polygon* second) {
	if (first->getArea() > second->getArea()) {
		return first;
	}
	else {
		return second;
	}
}

int main() {

	Item* apples = new Item("Apples", 1.25, 3);
	printItemCost(apples);

	TaxableItem* chickenNuggets = new TaxableItem("Chicken Nuggets", 1.99, .06);
	printItemCost(chickenNuggets);

	PerishableItem* cookies = new PerishableItem("Double chocolate chunk", 2.99, 1);
	printItemCost(cookies);

	
	

	Triangle* smallTriangle = new Triangle();
	smallTriangle->setSideLength(0, 3);
	smallTriangle->setSideLength(1, 4);
	smallTriangle->setSideLength(2, 5);

	Rectangle* smallRectangle = new Rectangle();
	smallRectangle->setSideLength(0, 5);
	smallRectangle->setSideLength(1, 2);

	Polygon* largerPolygon = determineLargerPolygonByArea(smallRectangle, smallRectangle);

	cout << "The area of the larger polygon is: " << largerPolygon->getArea() << endl;
}