#pragma once

using namespace std;

#include <iostream>
#include <vector>

template<typename T>
class BagOfHolding {
private:
	vector<T> bag;
public:
	void addItem(T item) {
		bag.push_back(item);
	}

	T getItem() {
		// rand gives a random seed value to rand
		// students helped me because I can't remember anything
		srand(time(NULL));
		int randomIndex = rand() % bag.size();
		return bag.at(randomIndex);
	}
};