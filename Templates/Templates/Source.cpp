using namespace std;

#include <iostream>
#include "Item.h"
#include "Bag.h"


template<typename T>
void printSmallest(T first, T second, T third = T()) {
	if (first < second && first < third) {
		cout << first << endl;
	}
	else if (second < first && second < third) {
		cout << second << endl;
	}
	else {
		cout << third << endl;
	}
}


int main() {
	pair<string, Item> items;

	items.first = "Apples";
	items.second = Item("Apples", 1.99);

	printSmallest<int>(3, 23, 42);
	printSmallest<string>("first", "second", "third");
	printSmallest<Item>(Item("Apples", 1.99),
		Item("Bananas", .49), Item("Cucumbers", .99));


	BagOfHolding<Item> bag;
	bag.addItem(Item("Apples", 1.99));
	bag.addItem(Item("Bananas", .49));
	bag.addItem(Item("Cucumbers", .99));

	cout << bag.getItem() << endl;

}