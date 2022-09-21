using namespace std;

#include <iostream>
#include "Item.h"
#include "TaxableItem.h"
#include "PerishableItem.h"

void printItemCost(Item* item) {
	cout << "Your total cost for " << item->getName() << " is: "
		<< item->getTotalPrice() << endl;
}

int main() {

	Item* apples = new Item("Apples", 1.25, 3);
	printItemCost(apples);

	TaxableItem* chickenNuggets = new TaxableItem("Chicken Nuggets", 1.99, .06);
	printItemCost(chickenNuggets);

	PerishableItem* cookies = new PerishableItem("Double chocolate chunk", 2.99, 1);
	printItemCost(cookies);


}